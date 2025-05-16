// ──────────────────────────────────────────────
//  Mac-inspired UX tweaks for VS Code WebView
// ──────────────────────────────────────────────

// ─── tiny helper -------------------------------------------------------------
const $ = (sel, root = document) => root.querySelector(sel);

// fade an element in/out
const fadeVisibility = (el, show, ms = 180) => {
  if (!el) return;
  el.style.transition = `opacity ${ms}ms cubic-bezier(.4,0,.2,1)`;
  el.style.opacity = show ? "1" : "0";
  setTimeout(() => (el.style.visibility = show ? "visible" : "hidden"), ms);
};

// ─── 1. Sidebar title  (“Finder style”) --------------------------------------
const updateSidebarTitle = () => {
  const header = $(".monaco-workbench .part.sidebar .composite.title h2");
  if (!header) return;

  const original = header.dataset.originalText || header.textContent;
  header.dataset.originalText ||= original; // save once
  const project = original.split(":").pop().trim();

  if (header.textContent !== project) {
    fadeVisibility(header, false, 90);
    setTimeout(() => {
      header.textContent = project;
      fadeVisibility(header, true, 140);
    }, 90);
  }
};

// start observing sidebar changes
{
  const target = $(".monaco-workbench .part.sidebar .composite.title");
  if (target) {
    new MutationObserver(updateSidebarTitle).observe(target, {
      childList: true,
      subtree: true
    });
  }
  // run once on load
  window.addEventListener("load", updateSidebarTitle);
}

// ─── 2. Spotlight blur for command palette -----------------------------------
let paletteObserver, safetyTimer;

const createBlurOverlay = () => {
  const blur = document.createElement("div");
  blur.id = "command-blur";
  Object.assign(blur.style, {
    position: "fixed",
    inset: "0",
    width: "100vw",
    height: "100vh",
    backdropFilter: "blur(38px) saturate(170%)",
    background: "rgba(255,255,255,0.28)",
    opacity: "0",
    transition: "opacity 220ms cubic-bezier(.4,0,.2,1)",
    zIndex: "10000"
  });
  blur.addEventListener("click", hideSpotlightBlur);
  return blur;
};

function showSpotlightBlur() {
  const workbench = $(".monaco-workbench");
  if (!workbench) return;

  // remove orphaned overlay if any
  $("#command-blur")?.remove();

  workbench.appendChild(createBlurOverlay());
  requestAnimationFrame(() => ($("#command-blur").style.opacity = "1"));

  // fade out sticky bits
  document
    .querySelectorAll(".sticky-widget, .monaco-tree-sticky-container")
    .forEach((el) => fadeVisibility(el, false, 120));
}

function hideSpotlightBlur() {
  const blur = $("#command-blur");
  if (blur) {
    blur.style.opacity = "0";
    setTimeout(() => blur.remove(), 200);
  }
  document
    .querySelectorAll(".sticky-widget, .monaco-tree-sticky-container")
    .forEach((el) => fadeVisibility(el, true, 120));

  paletteObserver?.disconnect();
  clearInterval(safetyTimer);
}

// watch body for quick-input addition / removal / style change
function attachPaletteMonitor() {
  const quickInputSel = ".quick-input-widget";

  const checkState = () => {
    const qi = $(quickInputSel);
    const visible = qi && qi.offsetParent !== null && qi.style.display !== "none";
    visible ? showSpotlightBlur() : hideSpotlightBlur();
  };

  paletteObserver = new MutationObserver(checkState);
  paletteObserver.observe(document.body, {
    childList: true,
    subtree: true,
    attributes: true,
    attributeFilter: ["style"]
  });

  // fallback poll in case nothing mutates
  safetyTimer = setInterval(checkState, 250);

  checkState(); // initial
}

// ─── 3. Keyboard shortcuts ----------------------------------------------------
document.addEventListener(
  "keydown",
  (e) => {
    // ⌘P / Ctrl+P → spotlight
    if ((e.metaKey || e.ctrlKey) && e.key.toLowerCase() === "p") {
      setTimeout(showSpotlightBlur, 50); // allow widget to mount first
    }
    // Esc → close
    if (e.key === "Escape" || e.key === "Esc") {
      hideSpotlightBlur();
    }
  },
  true
);

// ─── 4. Bootstrapping ---------------------------------------------------------
document.addEventListener("DOMContentLoaded", attachPaletteMonitor);

