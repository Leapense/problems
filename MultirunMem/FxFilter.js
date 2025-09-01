var colorOverlay = {
    name: "color-overlay",
    callback: (element, color, opacity = 1) => {
        return `
            <feFlood flood-color="${color}" flood-opacity="${opacity}" result="colorOverlay"/>
            <feComposite in="colorOverlay" in2="SourceGraphic" operator="over"/>
        `;
    }
};

var liquidGlass = {
    name: "liquid-glass",
    callback: (element, refraction = 1, offset = 10, chromatic = 0) => {
        // Get element dimensions and validate them
        const rawWidth = element.offsetWidth || element.clientWidth || 1;
        const rawHeight = element.offsetHeight || element.clientHeight || 1;
        const width = Math.max(1, Math.round(rawWidth));
        const height = Math.max(1, Math.round(rawHeight));

        // If dimensions are still invalid, return empty filter
        if (width <= 1 || height <= 1) {
            console.warn('🚨 Liquid-glass effect skipped: element has zero or invalid dimensions', { width, height, element });
            return `<!-- Liquid-glass effect skipped: invalid dimensions -->`;
        }

        const refractionValue = parseFloat(refraction) / 2 || 0;
        const offsetValue = (parseFloat(offset) || 0) / 2;
        const chromaticValue = parseFloat(chromatic) || 0;
        const borderRadiusStr = window.getComputedStyle(element).borderRadius || '0';
        let borderRadius = 0;
        if (borderRadiusStr.includes('%')) {
            // Handle percentage border radius
            const percentage = parseFloat(borderRadiusStr);
            const elementSize = Math.min(width, height);
            borderRadius = (percentage / 100) * elementSize;
        } else {
            // Handle pixel values
            borderRadius = parseFloat(borderRadiusStr);
        }

        // Helper function to create displacement map with given refraction
        function createDisplacementMap(refractionMod) {
            const adjustedRefraction = refractionValue + refractionMod;
            const imageData = new ImageData(maxDimension, maxDimension);
            const data = imageData.data;

            // Initialize with neutral gray (127 = no displacement)
            for (let i = 0; i < data.length; i += 4) {
                data[i] = 127;     // R - X displacement channel
                data[i + 1] = 127; // G - unused channel
                data[i + 2] = 127; // B - Y displacement channel
                data[i + 3] = 255; // A
            }

            // Apply top edge displacement
            const topOffset = Math.floor(maxDimension / 2);
            for (let y = 0; y < topOffset; y++) {
                for (let x = 0; x < maxDimension; x++) {
                    const gradientSegment = (topOffset - y) / topOffset; // bottom to top
                    const pixelIndex = (y * maxDimension + x) * 4;
                    const vyValue = 1 * adjustedRefraction;
                    data[pixelIndex + 2] = Math.max(0, Math.min(255, Math.round(127 + 127 * vyValue * Math.pow(gradientSegment, 1))));
                }
            }

            // Apply bottom edge displacement
            for (let y = maxDimension - topOffset; y < maxDimension; y++) {
                for (let x = 0; x < maxDimension; x++) {
                    const gradientSegment = (y - (maxDimension - topOffset)) / topOffset; // top to bottom
                    const pixelIndex = (y * maxDimension + x) * 4;
                    const vyValue = -1 * adjustedRefraction;
                    data[pixelIndex + 2] = Math.max(0, Math.min(255, Math.round(127 + 127 * vyValue * Math.pow(gradientSegment, 1))));
                }
            }

            // Apply left edge displacement
            const leftOffset = Math.floor(maxDimension / 2);
            for (let y = 0; y < maxDimension; y++) {
                for (let x = 0; x < leftOffset; x++) {
                    const gradientSegment = (leftOffset - x) / leftOffset; // right to left
                    const pixelIndex = (y * maxDimension + x) * 4;
                    const vxValue = 1 * adjustedRefraction;
                    data[pixelIndex] = Math.max(0, Math.min(255, Math.round(127 + 127 * vxValue * Math.pow(gradientSegment, 1))));
                }
            }

            // Apply right edge displacement
            for (let y = 0; y < maxDimension; y++) {
                for (let x = maxDimension - leftOffset; x < maxDimension; x++) {
                    const gradientSegment = (x - (maxDimension - leftOffset)) / leftOffset; // left to right
                    const pixelIndex = (y * maxDimension + x) * 4;
                    const vxValue = -1 * adjustedRefraction;
                    data[pixelIndex] = Math.max(0, Math.min(255, Math.round(127 + 127 * vxValue * Math.pow(gradientSegment, 1))));
                }
            }

            return imageData;
        }

        // Helper function to create canvas with displacement map and apply blur/mask
        function createCanvasFromImageData(imageData) {
            const canvas = document.createElement('canvas');
            canvas.width = width;
            canvas.height = height;
            const ctx = canvas.getContext('2d');

            // Center the displacement map on the canvas
            const offsetX = (maxDimension - width) / 2;
            const offsetY = (maxDimension - height) / 2;
            ctx.putImageData(imageData, -Math.round(offsetX), -Math.round(offsetY));
            // Apply border radius mask if needed
            borderRadius = Math.max(.1, borderRadius);
            if (borderRadius > 0) {
                const maskCanvas = new OffscreenCanvas(width, height);
                const maskCtx = maskCanvas.getContext('2d');
                maskCtx.fillStyle = "rgb(127, 127, 127)";
                maskCtx.beginPath();
                // Make mask smaller based on blur amount to prevent edge transparency
                const inset = offsetValue * 1; // Adjust multiplier as needed
                maskCtx.roundRect(inset, inset, width - (inset * 2), height - (inset * 2), Math.max(0, borderRadius - inset));
                maskCtx.clip();
                maskCtx.fillRect(0, 0, width, height);

                ctx.filter = `blur(${offsetValue}px)`;
                ctx.drawImage(maskCanvas, 0, 0, width, height);
            } else if (offsetValue > 0) {
                ctx.filter = `blur(${offsetValue}px)`;
                ctx.drawImage(canvas, 0, 0);
            }

            const dataURL = canvas.toDataURL();
            canvas.remove();
            return dataURL;
        }

        const maxDimension = Math.ceil(Math.max(width, height));

        // If no chromatic aberration, use simple single displacement
        if (chromaticValue === 0) {
            const imageData = createDisplacementMap(0);
            const dataURL = createCanvasFromImageData(imageData);

            return `
                <feImage result="FEIMG" href="${dataURL}" color-interpolation-filters="sRGB"/>
                <feDisplacementMap in="SourceGraphic" in2="FEIMG" scale="127" yChannelSelector="B" xChannelSelector="R" color-interpolation-filters="sRGB"/>
            `;
        } else {
            // Create three displacement maps with different refraction values
            const chromaticOffset = chromaticValue * 0.25; // Scale the chromatic offset

            const redImageData = createDisplacementMap(chromaticOffset);  // R: +0.25 * chromatic
            const greenImageData = createDisplacementMap(0);             // G: normal refraction
            const blueImageData = createDisplacementMap(-chromaticOffset); // B: -0.25 * chromatic

            const redDataURL = createCanvasFromImageData(redImageData);
            const greenDataURL = createCanvasFromImageData(greenImageData);
            const blueDataURL = createCanvasFromImageData(blueImageData);

            return `
                <!-- Red channel displacement -->
                <feImage result="redImg" href="${redDataURL}" color-interpolation-filters="sRGB"/>
                <feDisplacementMap in="SourceGraphic" in2="redImg" scale="127" yChannelSelector="B" xChannelSelector="R" color-interpolation-filters="sRGB" result="redDisplaced"/>
                <feComponentTransfer in="redDisplaced" result="redChannel">
                    <feFuncR type="identity"/>
                    <feFuncG type="discrete" tableValues="0"/>
                    <feFuncB type="discrete" tableValues="0"/>
                    <feFuncA type="identity"/>
                </feComponentTransfer>

                <!-- Green channel displacement -->
                <feImage result="greenImg" href="${greenDataURL}" color-interpolation-filters="sRGB"/>
                <feDisplacementMap in="SourceGraphic" in2="greenImg" scale="127" yChannelSelector="B" xChannelSelector="R" color-interpolation-filters="sRGB" result="greenDisplaced"/>
                <feComponentTransfer in="greenDisplaced" result="greenChannel">
                    <feFuncR type="discrete" tableValues="0"/>
                    <feFuncG type="identity"/>
                    <feFuncB type="discrete" tableValues="0"/>
                    <feFuncA type="identity"/>
                </feComponentTransfer>

                <!-- Blue channel displacement -->
                <feImage result="blueImg" href="${blueDataURL}" color-interpolation-filters="sRGB"/>
                <feDisplacementMap in="SourceGraphic" in2="blueImg" scale="127" yChannelSelector="B" xChannelSelector="R" color-interpolation-filters="sRGB" result="blueDisplaced"/>
                <feComponentTransfer in="blueDisplaced" result="blueChannel">
                    <feFuncR type="discrete" tableValues="0"/>
                    <feFuncG type="discrete" tableValues="0"/>
                    <feFuncB type="identity"/>
                    <feFuncA type="identity"/>
                </feComponentTransfer>

                <!-- Combine all channels -->
                <feComposite in="redChannel" in2="greenChannel" operator="arithmetic" k1="0" k2="1" k3="1" k4="0" result="redGreen"/>
                <feComposite in="redGreen" in2="blueChannel" operator="arithmetic" k1="0" k2="1" k3="1" k4="0" result="final"/>
            `;
        }
    },
    updatesOn: ['border-radius', 'width', 'height']
};

var noise = {
    name: "noise",
    callback: (element, saturation = 0, intensity = 1, opacity = .25) => {
        // Get element dimensions and validate them
        const width = Math.max(1, element.clientWidth || element.offsetWidth || 1);
        const height = Math.max(1, element.clientHeight || element.offsetHeight || 1);
        
        // If dimensions are still invalid, return empty filter
        if (width <= 1 || height <= 1) {
            console.warn('🚨 Noise effect skipped: element has zero or invalid dimensions', { width, height, element });
            return `<!-- Noise effect skipped: invalid dimensions -->`;
        }
        
        // Create canvas for noise texture
        const canvas = document.createElement('canvas');
        canvas.width = width;
        canvas.height = height;
        const ctx = canvas.getContext('2d');

        // Disable smoothing for sharper noise
        ctx.imageSmoothingEnabled = false;

        // Generate additive noise pattern (bright)
        const imageDataAdd = ctx.createImageData(canvas.width, canvas.height);
        const dataAdd = imageDataAdd.data;
        const additiveIntensity = intensity;

        for (let i = 0; i < dataAdd.length; i += 4) {
            // Generate smooth random values between 0-1 for more unified noise
            const noiseValue1 = Math.random() * additiveIntensity * 255;
            const noiseValue2 = Math.random() * additiveIntensity * 255;
            const noiseValue3 = Math.random() * additiveIntensity * 255;

            // For saturation=0: use same value for all channels (grayscale)
            // For saturation=1: use different values for each channel (color)
            const baseNoise = noiseValue1; // Use first noise value as base for grayscale
            dataAdd[i] = baseNoise * (1 - saturation) + noiseValue1 * saturation;     // Red
            dataAdd[i + 1] = baseNoise * (1 - saturation) + noiseValue2 * saturation; // Green  
            dataAdd[i + 2] = baseNoise * (1 - saturation) + noiseValue3 * saturation; // Blue
            dataAdd[i + 3] = 255 * opacity; // Full opacity for unified appearance
        }

        ctx.putImageData(imageDataAdd, 0, 0);
        const noiseAdditiveURL = canvas.toDataURL();

        return `
                <feImage href="${noiseAdditiveURL}" result="noiseAdd" image-rendering="pixelated"/>
                <feBlend in="SourceGraphic" in2="noiseAdd" mode="overlay" image-rendering="pixelated" result="brightened"/>
                `;
    },
    updatesOn: ['width', 'height']  // No style dependencies for noise filter
};

/**
 * scale effect
 * 
 * Combinations:
 * - (scale, edgeMode)
 * - (scaleX, scaleY)
 * - (scaleX, scaleY, edgeMode)
 */
var scale = {
    name: 'scale',
    callback: (element, ...arguments_) => {
        let scaleX = 1, scaleY = 1;
        if (arguments_.length === 2) {
            if (!isNaN(Number(arguments_[1]))) {
                // (scale, edgeMode)
                scaleX = Number(arguments_[0]);
                scaleY = scaleX;
                arguments_[1];
            } else {
                // (scaleX, scaleY)
                scaleX = Number(arguments_[0]);
                scaleY = Number(arguments_[1]);
            }
        } else if (arguments_.length === 3) {
            // (scaleX, scaleY, edgeMode)
            scaleX = Number(arguments_[0]);
            scaleY = Number(arguments_[1]);
            arguments_[2];
        } else if (arguments_.length === 1) {
            scaleX = scaleY = Number(arguments_[0]);
        }
        if (
            isNaN(scaleX) || isNaN(scaleY) ||
            !isFinite(scaleX) || !isFinite(scaleY) ||
            scaleX === 0 || scaleY === 0
        ) {
            return '';
        }
        const c_scaleX = 1 / scaleX;
        const c_scaleY = 1 / scaleY;
        if (c_scaleX == 0 || c_scaleY == 0 || (c_scaleX == 1 && c_scaleY == 1)) return '';
        return `
        <feImage result="gradient" xlink:href="data:image/svg+xml;utf8,${encodeURIComponent(
            `<svg xmlns="http://www.w3.org/2000/svg" width="100%" height="100%">
            <defs>
                <linearGradient id="g" x1="0" y1="0" x2="1" y2="0">
                <stop offset="0%" stop-color="rgba(0,0,0,.5)"/>
                <stop offset="100%" stop-color="rgba(255,255,255,.5)"/>
                </linearGradient>
            </defs>
            <rect width="100%" height="100%" fill="url(#g)"/>
            </svg>`
        )}" />
        <feImage result="gradient2" xlink:href="data:image/svg+xml;utf8,${encodeURIComponent(
            `<svg xmlns="http://www.w3.org/2000/svg" width="100%" height="100%">
            <defs>
                <linearGradient id="g" x1="0" y1="0" x2="0" y2="1">
                <stop offset="0%" stop-color="rgba(0,0,0,.5)"/>
                <stop offset="100%" stop-color="rgba(255,255,255,.5)"/>
                </linearGradient>
            </defs>
            <rect width="100%" height="100%" fill="url(#g)"/>
            </svg>`
        )}" />
        <feDisplacementMap in2="gradient2" in="SourceGraphic" scale="${element.offsetHeight * (c_scaleY - 1)}" xChannelSelector="A" yChannelSelector="R" result="disp1" x="0" y="0" width="100%" height="100%"/>
                <feDisplacementMap in2="gradient" in="disp1" scale="${element.offsetWidth * (c_scaleX - 1)}" xChannelSelector="R" yChannelSelector="A" result="disp1" x="0" y="0" width="100%" height="100%"/>

        `;
    },
    updatesOn: ['width', 'height']
};

const builtInEffects = [
    colorOverlay,
    liquidGlass,
    noise,
    scale
];

var fxConsole$1 = fxConsole = {
    log: (...messages) => {
        if (window["FxFilterDebug"]) console.log("FxFilterJS:", ...messages);
    },
    warn: (...messages) => {
        if (window["FxFilterDebug"]) console.warn("FxFilterJS Warning:", ...messages);
    },
    error: (...messages) => {
        if (window["FxFilterDebug"]) console.error("FxFilterJS Error:", ...messages);
    },
    info: (...messages) => {
        if (window["FxFilterDebug"]) console.info("FxFilterJS Info:", ...messages);
    }
};

class FxFilter {
    static elements = new WeakMap(); // Track elements and their state
    static filters = new Map(); // Registry for custom filters
    static filterOptions = new Map(); // Track filter options including updatesOn
    static running = false;
    static observer = null; // MutationObserver instance
    static resizeObserver = null; // ResizeObserver instance
    static pendingElements = new Set(); // Elements waiting for proper dimensions
    static styleCheckInterval = null; // Interval for checking style changes

    static add(options) {
        // if options is a list of filters, register each one
        if (Array.isArray(options)) {
            options.forEach(filter => this.add(filter));
            return;
        }
        // Support both old (name, callback) and new (options) format
        if (typeof options === 'string') {
            // Old format: add(name, callback)
            const name = arguments[0];
            const callback = arguments[1];
            this.filters.set(name, callback);
            this.filterOptions.set(name, { name, callback, updatesOn: [] });
            fxConsole$1.log(`🔧 Registered filter: "${name}"`);
        } else {
            // New format: add({name, callback, updatesOn})
            const { name, callback, updatesOn = [] } = options;
            this.filters.set(name, callback);
            this.filterOptions.set(name, { name, callback, updatesOn });
            fxConsole$1.log(`🔧 Registered filter: "${name}" with updatesOn: [${updatesOn.join(', ')}]`);
        }
    }

    static init() {
        fxConsole$1.log('🔄 FxFilter.init() called');

        // Register --fx-filter as a proper CSS custom property
        if ('CSS' in window && 'registerProperty' in CSS) {
            try {
                CSS.registerProperty({
                    name: '--fx-filter',
                    syntax: '*',
                    inherits: false,
                    initialValue: ''
                });
                fxConsole$1.log('✅ --fx-filter property registered');
            } catch (e) {
                fxConsole$1.log('⚠️ CSS registerProperty not supported or already registered');
            }
        }

        if (!this.running) {
            fxConsole$1.log('🚀 Starting FxFilter with MutationObserver');
            this.running = true;
            
            // Wait for DOM to be ready before initial scan
            this.waitForDOMReady(() => {
                this.setupMutationObserver();
                this.setupResizeObserver();
                this.setupStyleWatcher(); // Add periodic style checking
                this.scanElements(); // Initial scan for existing elements
                fxConsole$1.log('🎯 Initial DOM scan completed');
            });
        } else {
            fxConsole$1.log('⚡ FxFilter already running - skipping duplicate initialization');
        }
    }

    static waitForDOMReady(callback) {
        if (document.readyState === 'loading') {
            // DOM is still loading, wait for DOMContentLoaded
            document.addEventListener('DOMContentLoaded', () => {
                // Give a small delay to ensure layout calculations are done
                setTimeout(callback, 50);
            });
        } else {
            // DOM is already ready, execute immediately
            setTimeout(callback, 50);
        }
    }

    static setupStyleWatcher() {
        // Set up periodic checking for style changes on elements with updatesOn properties
        // This is much more efficient than the old RAF approach since it only checks
        // elements that actually have effects with style dependencies
        this.styleCheckInterval = setInterval(() => {
            this.checkStyleChanges();
        }, 100); // Check every 100ms, much less frequent than 60fps RAF
        
        fxConsole$1.log('⏰ Style watcher setup complete (checking every 100ms)');
    }

    static checkStyleChanges() {
        const elementsToCheck = [];
        
        // Only check elements that have effects with updatesOn properties
        document.querySelectorAll('*:not(.fx-container):not(svg)').forEach(element => {
            const storedState = this.elements.get(element);
            if (storedState && storedState.filter && storedState.trackedStyles && storedState.trackedStyles.size > 0) {
                elementsToCheck.push(element);
            }
        });
        
        if (elementsToCheck.length > 0) {
            this.scanSpecificElements(elementsToCheck);
        }
    }

    static setupResizeObserver() {
        if ('ResizeObserver' in window) {
            this.resizeObserver = new ResizeObserver((entries) => {
                const elementsToCheck = new Set();
                
                entries.forEach(entry => {
                    const element = entry.target;
                    
                    // Check if this element had zero dimensions before and now has dimensions
                    if (this.pendingElements.has(element)) {
                        const rect = element.getBoundingClientRect();
                        const clientWidth = element.clientWidth || 0;
                        const clientHeight = element.clientHeight || 0;
                        const offsetWidth = element.offsetWidth || 0;
                        const offsetHeight = element.offsetHeight || 0;
                        
                        // Element now has valid dimensions if all methods report positive values
                        const hasValidDimensions = (
                            rect.width > 0 && rect.height > 0 &&
                            (clientWidth > 0 || offsetWidth > 0) &&
                            (clientHeight > 0 || offsetHeight > 0)
                        );
                        
                        if (hasValidDimensions) {
                            fxConsole$1.log('📏 Element now has valid dimensions, processing:', element);
                            this.pendingElements.delete(element);
                            elementsToCheck.add(element);
                        }
                    }
                    
                    // Also check if this element needs updates based on size changes
                    const storedState = this.elements.get(element);
                    if (storedState && storedState.filter) {
                        elementsToCheck.add(element);
                    }
                });
                
                if (elementsToCheck.size > 0) {
                    this.scanSpecificElements(Array.from(elementsToCheck));
                }
            });
            
            fxConsole$1.log('📏 ResizeObserver setup complete');
        } else {
            fxConsole$1.log('⚠️ ResizeObserver not supported');
        }
    }

    static setupMutationObserver() {
        // Create MutationObserver to watch for DOM changes
        this.observer = new MutationObserver((mutations) => {
            this.handleMutations(mutations);
        });

        // Start observing document.body for changes
        this.observer.observe(document.body, {
            childList: true,    // Watch for added/removed nodes
            subtree: true,      // Watch entire subtree 
            attributes: true,   // Watch for attribute changes
            attributeFilter: ['style', 'class'] // Only watch style and class changes
        });

        fxConsole$1.log('👁️ MutationObserver setup complete');
    }

    static handleMutations(mutations) {
        const elementsToCheck = new Set();

        mutations.forEach(mutation => {
            if (mutation.type === 'childList') {
                // Handle added nodes
                mutation.addedNodes.forEach(node => {
                    if (node.nodeType === Node.ELEMENT_NODE) {
                        // Add the element itself
                        elementsToCheck.add(node);
                        // Add all descendants that could have --fx-filter
                        node.querySelectorAll('*:not(.fx-container):not(svg)').forEach(el => {
                            elementsToCheck.add(el);
                        });
                    }
                });

                // Handle removed nodes - clean up if they had filters
                mutation.removedNodes.forEach(node => {
                    if (node.nodeType === Node.ELEMENT_NODE) {
                        this.cleanupRemovedElement(node);
                        // Clean up descendants too
                        node.querySelectorAll('*').forEach(el => {
                            this.cleanupRemovedElement(el);
                        });
                    }
                });
            } else if (mutation.type === 'attributes') {
                // Handle attribute changes (style, class) that might affect --fx-filter
                if (mutation.target.nodeType === Node.ELEMENT_NODE) {
                    elementsToCheck.add(mutation.target);
                }
            }
        });

        // Process all affected elements
        if (elementsToCheck.size > 0) {
            this.scanSpecificElements(Array.from(elementsToCheck));
        }
    }

    static cleanupRemovedElement(element) {
        const storedState = this.elements.get(element);
        if (storedState && storedState.hasContainer) {
            // Element was removed from DOM, clean up our tracking
            this.elements.delete(element);
            fxConsole$1.log('🧹 Cleaned up removed element from tracking');
        }
        
        // Remove from pending and stop observing
        this.pendingElements.delete(element);
        if (this.resizeObserver) {
            this.resizeObserver.unobserve(element);
        }
    }

    static cleanup() {
        // Clean up all observers and intervals
        if (this.observer) {
            this.observer.disconnect();
            this.observer = null;
        }
        
        if (this.resizeObserver) {
            this.resizeObserver.disconnect();
            this.resizeObserver = null;
        }
        
        if (this.styleCheckInterval) {
            clearInterval(this.styleCheckInterval);
            this.styleCheckInterval = null;
        }
        
        this.running = false;
        fxConsole$1.log('🧹 FxFilter cleanup completed');
    }

    static scanElements() {
        // Scan all elements in the document (used for initial scan)
        const elements = document.querySelectorAll('*:not(.fx-container):not(svg)');
        this.scanSpecificElements(Array.from(elements));
    }

    static scanSpecificElements(elements) {
        // Scan only the provided elements for --fx-filter updates
        elements.forEach(element => {
            // Skip our generated containers and SVG elements
            if (element.classList.contains('fx-container') || element.tagName.toLowerCase() === 'svg') {
                return;
            }

            const fxFilter = this.getFxFilterValue(element);
            const storedState = this.elements.get(element);

            if (fxFilter) {
                // Check if element has zero dimensions using multiple methods
                const rect = element.getBoundingClientRect();
                const clientWidth = element.clientWidth || 0;
                const clientHeight = element.clientHeight || 0;
                const offsetWidth = element.offsetWidth || 0;
                const offsetHeight = element.offsetHeight || 0;
                
                // Element has zero dimensions if any of these are true
                const hasZeroDimensions = (
                    rect.width <= 0 || rect.height <= 0 ||
                    (clientWidth <= 0 && offsetWidth <= 0) ||
                    (clientHeight <= 0 && offsetHeight <= 0)
                );
                
                if (hasZeroDimensions) {
                    // Element has zero dimensions, add to pending and observe for resize
                    fxConsole$1.log('⏳ Element has zero dimensions, adding to pending list:', element, {
                        rect: { width: rect.width, height: rect.height },
                        client: { width: clientWidth, height: clientHeight },
                        offset: { width: offsetWidth, height: offsetHeight }
                    });
                    this.pendingElements.add(element);
                    
                    // Start observing this element for size changes
                    if (this.resizeObserver) {
                        this.resizeObserver.observe(element);
                    }
                    
                    // Skip processing for now
                    return;
                }
                
                // Remove from pending if it was there (element now has dimensions)
                if (this.pendingElements.has(element)) {
                    this.pendingElements.delete(element);
                    fxConsole$1.log('✅ Element now has dimensions, processing:', element);
                }

                let parsedFilter;
                if (storedState && storedState.filter === fxFilter && storedState.parsedFilter) {
                    parsedFilter = storedState.parsedFilter;
                } else {
                    parsedFilter = this.parseFilterValue(fxFilter);
                }
                const currentStyles = this.getTrackedStyles(element, fxFilter, parsedFilter);

                if (!storedState) {
                    // New element: create container and persistent filterId
                    const filterId = `fx-${Math.random().toString(36).substr(2, 8)}`;
                    this.addFxContainer(element, fxFilter, parsedFilter, filterId);
                    this.elements.set(element, {
                        filter: fxFilter,
                        hasContainer: true,
                        trackedStyles: currentStyles,
                        parsedFilter: parsedFilter,
                        filterId
                    });
                    
                    // Start observing for size changes if supported
                    if (this.resizeObserver) {
                        this.resizeObserver.observe(element);
                    }
                } else if (storedState.filter !== fxFilter || this.stylesChanged(storedState.trackedStyles, currentStyles)) {
                    // Only update SVG filter and CSS filter reference, not container
                    this.updateFxFilter(element, fxFilter, parsedFilter, storedState.filterId);
                    this.elements.set(element, {
                        filter: fxFilter,
                        hasContainer: true,
                        trackedStyles: currentStyles,
                        parsedFilter: parsedFilter,
                        filterId: storedState.filterId
                    });
                }
                // If storedState exists and filter is same and styles unchanged, do nothing
            } else {
                if (storedState && storedState.hasContainer) {
                    this.removeFxContainer(element);
                    this.elements.delete(element);
                    
                    // Stop observing this element
                    if (this.resizeObserver) {
                        this.resizeObserver.unobserve(element);
                    }
                }
                
                // Remove from pending if it was there
                this.pendingElements.delete(element);
            }
        });
    }

    static getFxFilterValue(element) {
        const computed = getComputedStyle(element);
        return computed.getPropertyValue('--fx-filter').trim() || null;
    }

    static addFxContainer(element, filterValue, parsedFilter) {
        // Skip if element already has fx-container
        if (element.querySelector('.fx-container')) {
            return;
        }

        const { orderedFilters, customFilters } = parsedFilter || this.parseFilterValue(filterValue);
        fxConsole$1.log('Parsed filters:', { orderedFilters, customFilters });

        // Use provided filterId for persistent reference
        let filterId = arguments[3];
        if (!filterId) {
            filterId = `fx-${Math.random().toString(36).substr(2, 8)}`;
        }

        // Build the combined filter list
        const filterParts = [];
        let svgContent = '';

        let customFilterIndex = 0;
        orderedFilters.forEach(item => {
            if (item.type === 'custom') {
                const filter = item.filter;
                const callback = this.filters.get(filter.name);
                if (callback) {
                    const filterContent = callback(element, ...filter.params);
                    const uniqueFilterId = `${filterId}-${customFilterIndex++}`;
                    svgContent += `<filter id="${uniqueFilterId}"
                     x="0" y="0" width="100%" height="100%" color-interpolation-filters="sRGB"
                     >${filterContent}</filter>`;
                    filterParts.push(`url(#${uniqueFilterId})`);
                }
            } else if (item.type === 'css') {
                filterParts.push(item.filter);
            }
        });

        const backdropFilter = filterParts.join(' ');

        if (backdropFilter.trim()) {
            element.insertAdjacentHTML('beforeend', `
                <div class="fx-container" style="position: absolute; top: 0; left: 0; right: 0; bottom: 0; backdrop-filter: ${backdropFilter}; background: transparent; pointer-events: none; z-index: -1; overflow: hidden; border-radius: inherit;">
                    <svg style="position: absolute; width: 0; height: 0;">
                        ${svgContent}
                    </svg>
                </div>
            `);
            fxConsole$1.log('Applied combined filter:', backdropFilter);
        } else {
            fxConsole$1.log('No valid filters found');
        }
    }

    // Update SVG filter and CSS filter reference in-place
    static updateFxFilter(element, filterValue, parsedFilter, filterId) {
        const { orderedFilters, customFilters } = parsedFilter || this.parseFilterValue(filterValue);
        fxConsole$1.log('Updating filter:', { orderedFilters, customFilters });
        const filterParts = [];
        let svgContent = '';
        let customFilterIndex = 0;
        orderedFilters.forEach(item => {
            if (item.type === 'custom') {
                const filter = item.filter;
                const callback = this.filters.get(filter.name);
                if (callback) {
                    const filterContent = callback(element, ...filter.params);
                    const uniqueFilterId = `${filterId}-${customFilterIndex++}`;
                    svgContent += `<filter id="${uniqueFilterId}"
                     x="0" y="0" width="100%" height="100%" color-interpolation-filters="sRGB"
                     >${filterContent}</filter>`;
                    filterParts.push(`url(#${uniqueFilterId})`);
                }
            } else if (item.type === 'css') {
                filterParts.push(item.filter);
            }
        });
        const backdropFilter = filterParts.join(' ');
        // Update SVG content
        const svg = element.querySelector('.fx-container svg');
        if (svg) {
            svg.innerHTML = svgContent;
        }
        // Update backdrop-filter style
        const container = element.querySelector('.fx-container');
        if (container) {
            container.style.backdropFilter = backdropFilter;
        }
        fxConsole$1.log('Updated combined filter:', backdropFilter);
    }

    static createUnifiedSVG(customFilters) {
        fxConsole$1.log('createUnifiedSVG called with:', customFilters);

        const svg = document.createElement('svg');
        svg.style.cssText = 'position: absolute; width: 0; height: 0; pointer-events: none;';

        const filterIds = [];
        let svgContent = '';

        customFilters.forEach((filter, index) => {
            fxConsole$1.log('Processing filter:', filter.name, 'with params:', filter.params);
            const callback = this.filters.get(filter.name);
            fxConsole$1.log('Callback found:', !!callback);

            if (callback) {
                // Create unique ID for this filter instance
                const filterId = `fx-${filter.name}-${Math.random().toString(36).substr(2, 6)}`;
                filterIds.push(filterId);

                // Render filter content with callback, passing parameters as arguments
                const filterContent = callback(...filter.params);
                fxConsole$1.log('Filter content generated:', filterContent);
                svgContent += `<filter id="${filterId}" x="-20%" y="-20%" width="140%" height="140%">${filterContent}</filter>`;
            }
        });

        fxConsole$1.log('Final SVG content:', svgContent);
        svg.innerHTML = svgContent;
        fxConsole$1.log('SVG element created:', svg);
        return { svg, filterIds };
    }


    static removeFxContainer(element) {
        element.querySelectorAll('.fx-container, svg').forEach(el => el.remove());
    }

    static parseFilterValue(filterValue) {
        // Parse: saturate(2) frosted-glass(8, 0.15) blur(10px)
        // Return: { orderedFilters: [...], customFilters: [...] }

        fxConsole$1.log('🔍 Parsing filter value:', filterValue);

        const orderedFilters = []; // Maintains original order
        const customFilters = [];

        // Regular expression to match filter functions with their parameters
        const filterRegex = /(\w+(?:-\w+)*)\s*\(([^)]*)\)/g;

        let match;
        while ((match = filterRegex.exec(filterValue)) !== null) {
            const filterName = match[1];
            const params = match[2];

            fxConsole$1.log(`📝 Found filter: ${filterName} with params: "${params}"`);

            if (this.filters.has(filterName)) {
                fxConsole$1.log(`✅ Custom filter "${filterName}" found in registry`);
                // It's a registered custom filter
                let paramArray = [];
                if (params.trim() !== '') {
                    paramArray = params.split(',').map(p => {
                        const trimmed = p.trim();
                        if (trimmed === '') return undefined;
                        const number = parseFloat(trimmed);
                        return !isNaN(number) ? number : trimmed;
                    }).filter(p => p !== undefined);
                }
                fxConsole$1.log(`📋 Parsed params for "${filterName}":`, paramArray);
                const customFilter = { name: filterName, params: paramArray };
                customFilters.push(customFilter);
                orderedFilters.push({ type: 'custom', filter: customFilter });
            } else {
                fxConsole$1.log(`🎨 CSS filter: ${filterName}(${params})`);
                // It's a native CSS filter
                orderedFilters.push({ type: 'css', filter: `${filterName}(${params})` });
            }
        }

        fxConsole$1.log('📊 Parse results:', { orderedFilters, customFilters });
        return {
            orderedFilters: orderedFilters,
            customFilters: customFilters
        };
    }

    static getTrackedStyles(element, filterValue, parsedFilter) {
        const { customFilters } = parsedFilter || this.parseFilterValue(filterValue);
        const trackedStyles = new Map();

        customFilters.forEach(filter => {
            const filterOptions = this.filterOptions.get(filter.name);
            if (filterOptions && filterOptions.updatesOn) {
                const computed = getComputedStyle(element);
                filterOptions.updatesOn.forEach(styleProp => {
                    const value = computed.getPropertyValue(styleProp);
                    trackedStyles.set(styleProp, value);
                });
            }
        });

        return trackedStyles;
    }

    static stylesChanged(oldStyles, newStyles) {
        if (!oldStyles || !newStyles) return true;
        if (oldStyles.size !== newStyles.size) return true;

        for (const [prop, value] of newStyles) {
            if (oldStyles.get(prop) !== value) {
                fxConsole$1.log(`🔄 Style change detected: ${prop} changed from "${oldStyles.get(prop)}" to "${value}"`);
                return true;
            }
        }

        return false;
    }
}
FxFilter.add(builtInEffects);
FxFilter.init();

// Export the class for external access
window.FxFilter = FxFilter;
