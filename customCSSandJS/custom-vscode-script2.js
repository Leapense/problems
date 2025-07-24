/*
  macos_dark_mode.js

  A companion JavaScript file for use with the Custom CSS and JS Loader extension in Visual Studio Code.  
  This script introduces a dynamic accent colour system that mimics macOS’s ability to choose different accent colours.  
  When loaded, it sets a CSS custom property (`--mac-accent-color`) to a default colour and binds a keyboard shortcut (Ctrl+Alt+A) to cycle through a predefined list of accent colours.  
  The current accent colour is stored in `localStorage` so that it persists across restarts of VS Code.  

  Usage: save this file to disk, reference it in the `vscode_custom_css.imports` setting alongside the CSS file, run “Reload Custom CSS and JS”, and restart VS Code.  
*/

(() => {
  // List of accent colours inspired by macOS system preferences.
  const accentColors = [
    '#0a84ff', // Blue (default macOS accent)
    '#5e5ce6', // Purple
    '#bf5af2', // Pink
    '#ff375f', // Red
    '#ff9f0a', // Orange
    '#ffd60a', // Yellow
    '#32d74b', // Green
    '#8e8e93'  // Graphite
  ];

  // Retrieve the last used accent index from localStorage; default to 0.
  let accentIndex = 0;
  try {
    const saved = localStorage.getItem('macosAccentIndex');
    if (saved !== null) {
      accentIndex = parseInt(saved, 10) || 0;
    }
  } catch (e) {
    console.warn('Custom macOS accent: unable to read localStorage', e);
  }

  // Function to apply the current accent colour to the document.
  const applyAccent = () => {
    const colour = accentColors[accentIndex % accentColors.length];
    document.documentElement.style.setProperty('--mac-accent-color', colour);
    try {
      localStorage.setItem('macosAccentIndex', accentIndex.toString());
    } catch (e) {
      console.warn('Custom macOS accent: unable to persist accent index', e);
    }
  };

  // Initial application of the accent.
  applyAccent();

  // Cycle to the next accent colour in the list.
  const cycleAccent = () => {
    accentIndex = (accentIndex + 1) % accentColors.length;
    applyAccent();
  };

  // Listen for Ctrl+Alt+A (or Cmd+Alt+A on macOS) to cycle accent colours.
  window.addEventListener('keydown', (evt) => {
    const isCtrlOrCmd = evt.ctrlKey || evt.metaKey;
    if (isCtrlOrCmd && evt.altKey && (evt.key === 'a' || evt.key === 'A')) {
      cycleAccent();
      evt.preventDefault();
    }
  });
})();