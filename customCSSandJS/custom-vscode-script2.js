/*
 * Custom JavaScript for Visual Studio Code (Fedora 42)
 *
 * This script accompanies the custom CSS created for the “Custom CSS and JS
 * Loader” extension.  It enhances the user interface by adding a blur
 * overlay to the editor whenever the command palette or quick‑input widget
 * is shown, thereby drawing attention to the palette.  The implementation
 * uses a MutationObserver to monitor the visibility of the `.quick-input-widget`
 * element, following the pattern illustrated in community examples【823052481447695†L0-L11】.
 * When the palette opens, a semi‑transparent overlay with a blur effect is
 * injected on top of the editor; when the palette closes, the overlay is
 * removed【823052481447695†L26-L38】.
 *
 * To use this file:
 * 1. Save it alongside your custom CSS file (e.g. `~/.config/vscode-custom.js`).
 * 2. Add its file URI to the `vscode_custom_css.imports` setting together with
 *    your CSS file.  Example:
 *
 *        "vscode_custom_css.imports": [
 *          "file:///home/<your-user>/.config/vscode-custom.css",
 *          "file:///home/<your-user>/.config/vscode-custom.js"
 *        ]
 *
 * 3. Run the “Enable Custom CSS and JS” command and restart VS Code.
 */

document.addEventListener('DOMContentLoaded', () => {
  /**
   * Creates a blur overlay if one doesn’t already exist.  The overlay is an
   * absolutely positioned <div> that fills the editor area and uses
   * CSS backdrop filters to blur the background.  It also uses
   * `pointerEvents: none` so that it doesn’t interfere with mouse clicks.
   */
  function addBlurOverlay() {
    const editorContent = document.querySelector(
      '.monaco-workbench .part.editor > .content'
    );
    if (!editorContent) return;
    if (!document.getElementById('custom-blur-overlay')) {
      const overlay = document.createElement('div');
      overlay.id = 'custom-blur-overlay';
      overlay.style.position = 'absolute';
      overlay.style.top = '0';
      overlay.style.left = '0';
      overlay.style.right = '0';
      overlay.style.bottom = '0';
      overlay.style.backdropFilter = 'blur(6px)';
      overlay.style.backgroundColor = 'rgba(0,0,0,0.15)';
      overlay.style.zIndex = '10';
      overlay.style.pointerEvents = 'none';
      editorContent.appendChild(overlay);
    }
  }

  /**
   * Removes the blur overlay from the editor if present.
   */
  function removeBlurOverlay() {
    const overlay = document.getElementById('custom-blur-overlay');
    if (overlay) {
      overlay.remove();
    }
  }

  /**
   * Observes a quick‑input widget (command palette) and applies or removes
   * the blur overlay depending on its visibility.  The observer watches for
   * changes to the `style` attribute, similar to the example script【823052481447695†L14-L24】.
   *
   * @param {HTMLElement} quickInput The element representing the command palette.
   */
  function observeQuickInput(quickInput) {
    const observer = new MutationObserver(() => {
      const isVisible = quickInput.style.display !== 'none';
      if (isVisible) {
        addBlurOverlay();
      } else {
        removeBlurOverlay();
      }
    });
    observer.observe(quickInput, { attributes: true, attributeFilter: ['style'] });
  }

  /**
   * Periodically searches for the quick‑input widget until it appears, then sets
   * up the observer.  Once the widget is found, the interval is cleared to
   * prevent unnecessary polling【823052481447695†L0-L11】.
   */
  const intervalId = setInterval(() => {
    const quickInput = document.querySelector('.quick-input-widget');
    if (quickInput) {
      // If it is already visible on first discovery, apply blur immediately
      if (quickInput.style.display !== 'none') {
        addBlurOverlay();
      }
      observeQuickInput(quickInput);
      clearInterval(intervalId);
    }
  }, 500);

  // Remove blur overlay if the user presses Esc outside of quick input.
  document.addEventListener('keydown', (ev) => {
    if (ev.key === 'Escape') {
      removeBlurOverlay();
    }
  });
});