/*
 * Custom JavaScript for Visual Studio Code (Fedora 42)
 *
 * Features:
 *  - Blur overlay on editor when Command Palette/Quick Input shows
 *  - Welcome modal on startup (remember "Don't show again")
 *  - Robust theme detection (VS Code CSS variables -> vs-dark/vscode-dark fallback)
 *  - Liquid Glass visual effect (modal + blur overlay)
 *
 * Requires: "Custom CSS and JS Loader" extension
 */

document.addEventListener('DOMContentLoaded', () => {
  // ===================== Blur Overlay Logic =====================
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
      overlay.style.pointerEvents = 'none'; // don't block clicks
      editorContent.appendChild(overlay);

      // Liquid Glass styling on the overlay (purely visual; still non-interactive)
      overlay.classList.add('lg-glass');
    }
  }

  function removeBlurOverlay() {
    const overlay = document.getElementById('custom-blur-overlay');
    if (overlay) overlay.remove();
  }

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

  // Poll until the quick-input widget exists, then observe it
  const intervalId = setInterval(() => {
    const quickInput = document.querySelector('.quick-input-widget');
    if (quickInput) {
      if (quickInput.style.display !== 'none') addBlurOverlay();
      observeQuickInput(quickInput);
      clearInterval(intervalId);
    }
  }, 500);

  // ESC anywhere removes blur (just in case)
  document.addEventListener('keydown', (ev) => {
    if (ev.key === 'Escape') removeBlurOverlay();
  });

  // ===================== Theme Token Helper =====================
  function pickThemeTokens() {
    const css = getComputedStyle(document.documentElement);
    const varOr = (name, fallback) => {
      const v = css.getPropertyValue(name).trim();
      return v || fallback;
    };

    const tokens = {
      fg: varOr('--vscode-foreground', ''),
      bg: varOr('--vscode-editor-background', ''),
      border: varOr('--vscode-widget-border', ''),
      subtle: varOr('--vscode-descriptionForeground', ''),
      btnBg: varOr('--vscode-button-background', ''),
      btnFg: varOr('--vscode-button-foreground', ''),
      hoverBg: varOr('--vscode-toolbar-hoverBackground', ''),
    };

    const hasAllCore = tokens.fg && tokens.bg && tokens.btnBg && tokens.btnFg;
    if (hasAllCore) return { tokens, isDark: null };

    // Fallback: detect theme classes anywhere (not only on body)
    const hasClass = (c) => !!document.querySelector('.' + c);
    const isDark =
      hasClass('vs-dark') || hasClass('vscode-dark') || hasClass('hc-black');

    return {
      isDark,
      tokens: {
        fg: tokens.fg || (isDark ? '#e6e6e6' : '#1e1e1e'),
        bg: tokens.bg || (isDark ? '#252526' : '#ffffff'),
        border: tokens.border || (isDark ? '#3c3c3c' : '#e5e5e5'),
        subtle: tokens.subtle || (isDark ? '#9da0a2' : '#6b6f73'),
        btnBg: tokens.btnBg || '#0e639c',
        btnFg: tokens.btnFg || '#ffffff',
        hoverBg: tokens.hoverBg || (isDark ? '#2a2a2a' : '#f3f3f3'),
      },
    };
  }

  // ===================== Liquid Glass Helpers =====================
  function ensureLiquidGlassStyles() {
    if (document.getElementById('custom-liquid-glass-styles')) return;
    const style = document.createElement('style');
    style.id = 'custom-liquid-glass-styles';
    style.textContent = `
      /* Base glass panel */
      .lg-glass {
        position: relative;
        background: rgba(255, 255, 255, 0.06);
        border: 1px solid rgba(255, 255, 255, 0.18);
        border-radius: 12px;
        backdrop-filter: blur(14px) saturate(1.2);
        -webkit-backdrop-filter: blur(14px) saturate(1.2);
        overflow: hidden;
        box-shadow:
          inset 0 1px 0 rgba(255,255,255,0.15),
          inset 0 -1px 0 rgba(0,0,0,0.08),
          0 20px 60px rgba(0,0,0,0.25), 0 2px 12px rgba(0,0,0,0.2);
      }
      /* soft inner highlight ring */
      .lg-glass::before {
        content: "";
        position: absolute; inset: 0;
        pointer-events: none;
        background:
          radial-gradient(120% 160% at 10% 0%,
            rgba(255,255,255,0.18) 0%, rgba(255,255,255,0.02) 36%, transparent 60%),
          radial-gradient(120% 160% at 90% 100%,
            rgba(255,255,255,0.10) 0%, rgba(255,255,255,0.00) 50%);
        mix-blend-mode: screen;
      }
      /* animated specular sweep */
      .lg-spec {
        position: absolute; inset: -40%;
        background:
          conic-gradient(from 0deg at 50% 50%,
            rgba(255,255,255,0.00) 0%,
            rgba(255,255,255,0.07) 10%,
            rgba(255,255,255,0.15) 15%,
            rgba(255,255,255,0.00) 25%,
            rgba(255,255,255,0.00) 100%);
        filter: blur(18px);
        animation: lgSweep 8s linear infinite;
        pointer-events: none;
        opacity: .7;
      }
      @keyframes lgSweep {
        0%   { transform: rotate(0deg)   scale(1.05); }
        50%  { transform: rotate(180deg) scale(1.10); }
        100% { transform: rotate(360deg) scale(1.05); }
      }

      /* subtle moving refraction caustics */
      .lg-caustics {
        position: absolute; inset: -20%;
        pointer-events: none;
        opacity: .22;
        filter: blur(10px) contrast(1.05) saturate(1.1);
        background:
          radial-gradient(45% 35% at 20% 30%, rgba(255,255,255,.45), transparent 60%),
          radial-gradient(40% 30% at 80% 70%, rgba(255,255,255,.35), transparent 60%),
          radial-gradient(35% 25% at 30% 80%, rgba(255,255,255,.25), transparent 60%),
          radial-gradient(30% 20% at 70% 25%, rgba(255,255,255,.30), transparent 60%);
        animation: lgFloat 18s ease-in-out infinite;
      }
      @keyframes lgFloat {
        0%   { transform: translate3d(0, 0, 0) scale(1.0); }
        25%  { transform: translate3d(-3%, 2%, 0) scale(1.03); }
        50%  { transform: translate3d(2%, -3%, 0) scale(1.02); }
        75%  { transform: translate3d(-2%, -1%, 0) scale(1.04); }
        100% { transform: translate3d(0, 0, 0) scale(1.0); }
      }

      /* fine grain for glass – super subtle */
      .lg-grain {
        position: absolute; inset: 0;
        pointer-events: none;
        mix-blend-mode: soft-light;
        opacity: .07;
        background-image: repeating-linear-gradient(
          0deg, rgba(255,255,255,.25) 0, rgba(255,255,255,.25) 1px, transparent 1px, transparent 2px
        );
        animation: lgGrainShift 3s steps(60) infinite;
      }
      @keyframes lgGrainShift {
        0%   { transform: translate3d(0,0,0); }
        100% { transform: translate3d(0,-2px,0); }
      }
    `;
    document.head.appendChild(style);
  }

  /**
   * Apply liquid glass layers to an element.
   * Respects VS Code theme tokens if available.
   * @param {HTMLElement} el
   * @param {{bg?:string, border?:string}} tokens
   */
  function applyLiquidGlass(el, tokens = {}) {
    ensureLiquidGlassStyles();
    el.classList.add('lg-glass');

    // Match VS Code theme background/border softly
    if (tokens.bg) {
      // color-mix keeps a hint of the underlying panel color
      el.style.background = 'color-mix(in oklab, ' + tokens.bg + ' 75%, transparent)';
    }
    if (tokens.border) {
      el.style.border = '1px solid ' + tokens.border;
    }

    // Add animated light layers
    const spec = document.createElement('div');
    spec.className = 'lg-spec';
    const caustics = document.createElement('div');
    caustics.className = 'lg-caustics';
    const grain = document.createElement('div');
    grain.className = 'lg-grain';

    el.appendChild(spec);
    el.appendChild(caustics);
    el.appendChild(grain);
  }

  // ===================== Welcome Modal =====================
  (function welcomeModalBootstrap() {
    const STORAGE_KEY = 'vscodeCustomWelcome.dismissed';
    const SHOW_ON_EVERY_START = false; // set true to always show

    if (!SHOW_ON_EVERY_START && localStorage.getItem(STORAGE_KEY) === 'true')
      return;

    createWelcomeModal();

    function createWelcomeModal() {
      if (document.getElementById('custom-welcome-overlay')) return;

      const { tokens, isDark } = pickThemeTokens();

      // Backdrop overlay
      const overlay = document.createElement('div');
      overlay.id = 'custom-welcome-overlay';
      overlay.setAttribute('role', 'dialog');
      overlay.setAttribute('aria-modal', 'true');
      Object.assign(overlay.style, {
        position: 'fixed',
        inset: '0',
        background: 'rgba(0,0,0,0.35)',
        backdropFilter: 'blur(2px)',
        zIndex: '10000',
        display: 'flex',
        alignItems: 'center',
        justifyContent: 'center',
      });

      // Modal panel
      const modal = document.createElement('div');
      Object.assign(modal.style, {
        minWidth: '420px',
        maxWidth: '560px',
        padding: '20px 22px',
        borderRadius: '12px',
        background: tokens.bg || 'rgba(255,255,255,0.06)',
        color: tokens.fg || '#e6e6e6',
        boxShadow:
          '0 20px 60px rgba(0,0,0,0.25), 0 2px 12px rgba(0,0,0,0.2)',
        border: `1px solid ${tokens.border || 'rgba(255,255,255,0.18)'}`,
        fontFamily:
          'var(--vscode-font-family, system-ui, -apple-system, Segoe UI, Roboto, sans-serif)',
      });

      // Apply Liquid Glass to modal
      applyLiquidGlass(modal, tokens);

      // Title
      const h = document.createElement('div');
      h.textContent = 'Welcome 👋';
      Object.assign(h.style, {
        fontSize: '18px',
        fontWeight: '600',
        marginBottom: '8px',
      });

      // Body
      const p = document.createElement('div');
      p.innerHTML =
        '커스텀 CSS/JS가 활성화되었습니다. 명령 팔레트(⌘/Ctrl+Shift+P)를 열면 에디터가 살짝 블러 처리돼 초점이 팔레트에 맞춰집니다. ' +
        '문제가 생기면 “Disable Custom CSS and JS” 명령으로 비활성화하세요.';
      Object.assign(p.style, {
        fontSize: '13px',
        lineHeight: '1.6',
        color: tokens.subtle || (isDark ? '#9da0a2' : '#6b6f73'),
      });

      // Footer
      const footer = document.createElement('div');
      Object.assign(footer.style, {
        display: 'flex',
        alignItems: 'center',
        justifyContent: 'space-between',
        marginTop: '16px',
        gap: '12px',
      });

      // Checkbox
      const left = document.createElement('label');
      Object.assign(left.style, {
        display: 'inline-flex',
        alignItems: 'center',
        gap: '8px',
        userSelect: 'none',
      });
      const cb = document.createElement('input');
      cb.type = 'checkbox';
      cb.id = 'custom-welcome-dontshow';
      const lbl = document.createElement('span');
      lbl.textContent = '다시 보지 않기';
      left.appendChild(cb);
      left.appendChild(lbl);

      // Actions
      const actions = document.createElement('div');
      Object.assign(actions.style, { display: 'inline-flex', gap: '8px' });

      const mkBtn = (text, primary = false) => {
        const b = document.createElement('button');
        b.type = 'button';
        b.textContent = text;
        Object.assign(b.style, {
          fontSize: '13px',
          padding: '8px 12px',
          borderRadius: '8px',
          border: `1px solid ${primary ? 'transparent' : (tokens.border || 'transparent')}`,
          cursor: 'pointer',
        });
        if (primary) {
          b.style.background = tokens.btnBg || '#0e639c';
          b.style.color = tokens.btnFg || '#ffffff';
        } else {
          b.style.background = 'transparent';
          b.style.color = tokens.fg || '#e6e6e6';
          b.onmouseenter = () => {
            b.style.background = tokens.hoverBg || (isDark ? '#2a2a2a' : '#f3f3f3');
          };
          b.onmouseleave = () => { b.style.background = 'transparent'; };
        }
        return b;
      };

      const btnDocs = mkBtn('문서 열기');
      const btnClose = mkBtn('닫기', true);

      actions.appendChild(btnDocs);
      actions.appendChild(btnClose);
      footer.appendChild(left);
      footer.appendChild(actions);

      // Assemble
      modal.appendChild(h);
      modal.appendChild(p);
      modal.appendChild(footer);
      overlay.appendChild(modal);
      document.body.appendChild(overlay);

      // Focus trap
      const focusable = [cb, btnDocs, btnClose];
      let lastFocused = document.activeElement;
      cb.focus();
      overlay.addEventListener('keydown', (e) => {
        if (e.key === 'Tab') {
          const idx = focusable.indexOf(document.activeElement);
          if (e.shiftKey) {
            if (idx <= 0) {
              focusable[focusable.length - 1].focus();
              e.preventDefault();
            }
          } else {
            if (idx === focusable.length - 1) {
              focusable[0].focus();
              e.preventDefault();
            }
          }
        } else if (e.key === 'Escape') {
          close(true);
        }
      });

      // Buttons
      btnClose.addEventListener('click', () => close(true));
      btnDocs.addEventListener('click', () => {
        window.open(
          'https://code.visualstudio.com/docs/getstarted/themes#_customizing-a-color-theme',
          '_blank',
          'noopener'
        );
      });

      // Click outside closes
      overlay.addEventListener('click', (e) => {
        if (e.target === overlay) close(true);
      });

      function close(setStorage) {
        if (setStorage && cb.checked) {
          try { localStorage.setItem(STORAGE_KEY, 'true'); } catch {}
        }
        overlay.remove();
        if (lastFocused && typeof lastFocused.focus === 'function') lastFocused.focus();
      }
    }
  })();
});