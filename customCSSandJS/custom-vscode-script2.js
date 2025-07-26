// ======================================================================
// macOS Tahoe Dark – VS Code Custom JS
//
// This script adds a couple of dynamic UI behaviours to Visual Studio Code
// when used together with a macOS‑style dark theme. It does two things:
//   1. Toggles the Activity Bar when pressing ⌘/Ctrl +B. The bar slides
//      in and out with a smooth animation instead of just disappearing.
//   2. Automatically hides the Status Bar and reveals it only when you
//      press the Alt/Option key. The bar re‑hides itself after a short
//      delay. Adjust the timeout at the bottom if you want it to stay
//      visible longer.
//
// Drop this file in your VS Code custom JS setup (for example by using
// the “Custom CSS and JS Loader” extension) and reload the window to
// activate the behaviour.
//
// Author: OpenAI ChatGPT – July 2025
// ======================================================================

document.addEventListener("DOMContentLoaded", () => {
  // Ensure the core container exists before hooking events.
  const workbench = document.querySelector(".monaco-workbench");
  if (!workbench) return;

  /**
   * Toggle the Activity Bar when ⌘/Ctrl +B is pressed.
   * We use a CSS transform and a dataset flag to keep track of state.
   */
  window.addEventListener("keydown", (e) => {
    // macOS uses the Meta key, Windows/Linux uses Ctrl.
    if ((e.metaKey || e.ctrlKey) && e.key.toLowerCase() === "b") {
      const activityBar = document.querySelector(".part.activitybar");
      if (!activityBar) return;

      activityBar.style.transition = "transform 0.25s cubic-bezier(0.4, 0.0, 0.2, 1)";
      // Determine current state from data attribute.
      const hidden = activityBar.dataset.hidden === "true";
      // Slide out to the left (width of Activity Bar is 48px by default).
      activityBar.style.transform = hidden ? "translateX(0)" : "translateX(-48px)";
      // Update state.
      activityBar.dataset.hidden = hidden ? "false" : "true";
      e.preventDefault();
      e.stopPropagation();
    }
  });

  /**
   * Automatically hide the Status Bar and show it only while the user
   * holds the Alt/Option key. After showing, the bar hides again after
   * a timeout (default 3 seconds). Feel free to adjust the delay.
   */
  const statusBar = document.querySelector(".part.statusbar");
  if (statusBar) {
    let hideTimeout;
    const HIDE_DELAY_MS = 3000;

    function hideStatusBar() {
      // Move the bar down by its height (approx. 36px).
      statusBar.style.transform = "translateY(36px)";
    }
    function showStatusBar() {
      clearTimeout(hideTimeout);
      // Bring the bar back into view.
      statusBar.style.transform = "translateY(0)";
      // Start a timer to hide it again.
      hideTimeout = setTimeout(hideStatusBar, HIDE_DELAY_MS);
    }
    // Initially hide the Status Bar.
    hideStatusBar();
    // Listen for the Alt/Option key.
    window.addEventListener("keydown", (e) => {
      // Show only when Alt is pressed without other modifiers.
      if (e.altKey && !e.ctrlKey && !e.metaKey && !e.shiftKey) {
        showStatusBar();
      }
    });
    
    /* ---------- Command Palette 중앙 배치 & 애니메이션 ---------- */
    function centerQuickPalette(widget) {
      widget.style.position  = "fixed";
      widget.style.top       = "50%";
      widget.style.left      = "50%";
      widget.style.transform = "translate(-50%, -50%) scale(0.95)";
      widget.style.width     = `${Math.min(window.innerWidth * 0.8, 640)}px`;
      widget.style.transition = "transform .18s cubic-bezier(.4,0,.2,1)";
      /* 살짝 확대하여 등장 */
      requestAnimationFrame(() => {
        widget.style.transform = "translate(-50%, -50%) scale(1)";
      });
    }

    const quickObserver = new MutationObserver((mutList) => {
      mutList.forEach((m) => {
        m.addedNodes.forEach((n) => {
          if (n.classList?.contains("quick-input-widget")) {
            centerQuickPalette(n);
          }
        });
      });
    });

    quickObserver.observe(document.body, { childList: true, subtree: true });
  }
});
