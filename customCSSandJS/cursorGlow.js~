/*--------------------------------------------------------------
  VS Code Sidebar Ripple (Method ③)
  Place this file next to your custom CSS and load it via
  "Custom CSS & JS Loader" (or @be5invis/vscode-custom-css) :
    "custom.styles": ["/path/to/vscode-glassmorphism-animated.css"],
    "custom.scripts": ["/path/to/vscode-ripple.js"],
  then run the **Enable Custom CSS and JS** command and reload.
----------------------------------------------------------------*/

(() => {
  const DUR = 500; // ripple duration (ms)
  const EASING = getComputedStyle(document.documentElement)
                  .getPropertyValue('--vscode-easing') || 'cubic-bezier(.4,0,.2,1)';

  document.addEventListener('pointerdown', (e) => {
    // Detect rows in any sidebar list/tree
    const row = e.target.closest('.monaco-list-row');
    if (!row) return;

    // Make sure the row can host absolutely‑positioned children
    const cs = getComputedStyle(row);
    if (cs.position === 'static') row.style.position = 'relative';

    // Create ripple element
    const ripple = document.createElement('span');
    const rect   = row.getBoundingClientRect();
    const size   = Math.max(rect.width, rect.height) * 2; // big enough to cover
    ripple.style.position = 'absolute';
    ripple.style.borderRadius = '50%';
    ripple.style.background   = 'var(--ripple-color, currentColor)';
    ripple.style.opacity      = '0.25';
    ripple.style.pointerEvents= 'none';
    ripple.style.width = ripple.style.height = `${size}px`;
    ripple.style.left  = `${e.clientX - rect.left - size/2}px`;
    ripple.style.top   = `${e.clientY - rect.top  - size/2}px`;
    ripple.style.transform = 'scale(0)';
    ripple.style.animation = `ripple ${DUR}ms ${EASING} forwards`;

    // Insert & clean up
    row.appendChild(ripple);
    ripple.addEventListener('animationend', () => ripple.remove());
  }, true); // use capture so we catch early
})();

