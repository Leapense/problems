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

    // ===================== Editor Music Player (robust mount + local playlist) =====================
  (function editorMusicPlayer() {
    const ID = 'editor-music-player';
    if (document.getElementById(ID)) return;

    const STORAGE = {
      vol: 'vscodeAudioPlayer.volume',
      idx: 'vscodeAudioPlayer.trackIndex',
      collapsed: 'vscodeAudioPlayer.collapsed',
      listOpen: 'vscodeAudioPlayer.listOpen',
      rate: 'vscodeAudioPlayer.playbackRate',
      pitch: 'vscodeAudioPlayer.pitchPreserve',
    };

    const REMOTE_PRESETS = [
    ];

    // 1) 에디터 컨테이너 찾기(여러 후보) + 실패 시 고정(fixed)로 바디/워크벤치에 부착
    function findEditorContainer() {
      return (
        document.querySelector('.monaco-workbench .part.editor > .content') ||
        document.querySelector('.monaco-workbench .part.editor .content') ||
        document.querySelector('.monaco-workbench .part.editor') ||
        null
      );
    }

    let tries = 0;
    const maxTriesBeforeFallback = 20; // 약 10초
    const t = setInterval(tryMount, 500);
    tryMount();

    function tryMount() {
      if (document.getElementById(ID)) {
        clearInterval(t);
        return;
      }
      const container = findEditorContainer();
      if (container) {
        try {
          createMusicPlayer(container, /*useFixed*/ false);
          console.info('[MusicPlayer] mounted on', describe(container));
          clearInterval(t);
        } catch (e) {
          console.error('[MusicPlayer] init error (will retry):', e);
          // 재시도 유지
        }
      } else {
        tries++;
        if (tries >= maxTriesBeforeFallback) {
          // fallback: workbench/body에 고정 위치로
          const wb = document.querySelector('.monaco-workbench') || document.body;
          try {
            createMusicPlayer(wb, /*useFixed*/ true);
            console.warn('[MusicPlayer] fallback: mounted fixed on workbench/body');
          } catch (e) {
            console.error('[MusicPlayer] fallback init error:', e);
          } finally {
            clearInterval(t);
          }
        }
      }
    }

    function describe(el) {
      return el.id ? `#${el.id}` : el.className ? `.${String(el.className).split(' ').join('.')}` : el.tagName;
    }

    function createMusicPlayer(root, useFixed) {
      const { tokens, isDark } = pickThemeTokens();

      // Wrapper
      const wrap = document.createElement('div');
      wrap.id = ID;
      Object.assign(wrap.style, {
        position: useFixed ? 'fixed' : 'absolute',
        top: '40px',
        right: '10px',
        zIndex: '30',
        pointerEvents: 'auto',
        userSelect: 'none',
        maxWidth: 'min(520px, calc(100% - 20px))',
      });

      // Panel (glass)
      const panel = document.createElement('div');
      Object.assign(panel.style, {
        display: 'inline-flex',
        alignItems: 'center',
        gap: '8px',
        padding: '6px 8px',
        borderRadius: '10px',
        color: tokens.fg || '#e6e6e6',
        position: 'relative',
        maxWidth: '100%',
      });
      applyLiquidGlass(panel, tokens);

      const row = document.createElement('div');
      Object.assign(row.style, {
        display: 'inline-flex',
        alignItems: 'center',
        gap: '8px',
        position: 'relative',
        zIndex: '1',
        maxWidth: '100%',
      });

      const title = document.createElement('span');
      title.title = '현재 트랙';
      Object.assign(title.style, {
        fontSize: '12px',
        opacity: '0.9',
        maxWidth: '260px',
        overflow: 'hidden',
        textOverflow: 'ellipsis',
        whiteSpace: 'nowrap',
      });

      const audio = document.createElement('audio');
      audio.preload = 'metadata';
      audio.style.display = 'none';

      const mkBtn = (text, aria, titleText) => {
        const b = document.createElement('button');
        b.type = 'button';
        b.textContent = text;
        b.setAttribute('aria-label', aria || text);
        if (titleText) b.title = titleText;
        Object.assign(b.style, {
          fontSize: '13px',
          padding: '6px 8px',
          borderRadius: '8px',
          border: '1px solid ' + (tokens.border || 'rgba(255,255,255,0.18)'),
          background: 'transparent',
          color: tokens.fg || '#e6e6e6',
          cursor: 'pointer',
          lineHeight: '1',
        });
        b.onmouseenter = () => {
          b.style.background = tokens.hoverBg || (isDark ? '#2a2a2a' : '#f3f3f3');
        };
        b.onmouseleave = () => {
          b.style.background = 'transparent';
        };
        return b;
      };

      const prevBtn = mkBtn('⏮', '이전 곡', '이전 트랙');
      const playBtn = mkBtn('▶', '재생/일시정지', '재생/일시정지');
      const nextBtn = mkBtn('⏭', '다음 곡', '다음 트랙');
      const addBtn = mkBtn('＋', '파일 추가', '오디오 파일 추가');
      const addDirBtn = mkBtn('📁', '폴더 추가', '폴더에서 오디오 추가');
      const listBtn = mkBtn('♪', '재생목록 열기/닫기', '재생목록 열기/닫기');
      const collapseBtn = mkBtn('–', '접기/펼치기', '접기/펼치기');

      const vol = document.createElement('input');
      vol.type = 'range';
      vol.min = '0'; vol.max = '1'; vol.step = '0.01';
      vol.value = localStorage.getItem(STORAGE.vol) || '0.7';
      Object.assign(vol.style, {
        width: '90px',
        cursor: 'pointer',
      });
      vol.style.setProperty('accent-color', tokens.btnBg || '#0e639c');

      // order
      row.appendChild(prevBtn);
      row.appendChild(playBtn);
      row.appendChild(nextBtn);
      row.appendChild(title);
      row.appendChild(vol);
      row.appendChild(addBtn);
      row.appendChild(addDirBtn);
      row.appendChild(listBtn);
      row.appendChild(collapseBtn);

      panel.appendChild(row);
      wrap.appendChild(panel);
      wrap.appendChild(audio);
      root.appendChild(wrap);

      // Playlist panel
      const listWrap = document.createElement('div');
      Object.assign(listWrap.style, {
        position: useFixed ? 'fixed' : 'absolute',
        top: useFixed ? '58px' : 'calc(100% + 8px)',
        right: '0',
        minWidth: '320px',
        maxWidth: '420px',
        maxHeight: '260px',
        overflowY: 'hidden',
        padding: '6px',
        display: 'none',
        zIndex: '31',
      });
      applyLiquidGlass(listWrap, tokens);

      const listHeader = document.createElement('div');
      listHeader.textContent = '재생목록';
      Object.assign(listHeader.style, { fontSize: '12px', opacity: '0.8', margin: '2px 4px 6px' });

      const list = document.createElement('div');
      list.id = 'editor-music-player-list';
      listWrap.appendChild(listHeader);
      listWrap.appendChild(list);
      wrap.appendChild(listWrap);

      // Hidden inputs
      const filePicker = document.createElement('input');
      filePicker.type = 'file'; filePicker.accept = 'audio/*'; filePicker.multiple = true; filePicker.style.display = 'none';

      const dirPicker = document.createElement('input');
      dirPicker.type = 'file'; dirPicker.multiple = true; dirPicker.style.display = 'none';
      // 일부 크로미움/Electron 버전에서 속성으로 넣는 게 더 호환됨
      dirPicker.setAttribute('webkitdirectory', '');

      wrap.appendChild(filePicker);
      wrap.appendChild(dirPicker);

      const RATES = [0.5, 0.75, 1, 1.25, 1.5, 1.75, 2];
      const speedSel = document.createElement('select');
      speedSel.title = '재생 속도';
      Object.assign(speedSel.style, {
        fontSize: '12px',
        padding: '5px 6px',
        borderRadius: '8px',
        border: '1px solid ' + (tokens.border || 'rgba(255,255,255,0.18'),
        backgrond: 'transparent',
        color: tokens.fg || '#e6e6e6',
        cursor: 'pointer', 
      });

      const savedRate = parseFloat(localStorage.getItem(STORAGE.rate) || '1');
      RATES.forEach((r) => {
        const opt = document.createElement('option');
        opt.value = String(r);
        opt.textContent = (r % 1 === 0 ? r.toFixed(0) : r.toFixed(2).replace(/0$/, '')) + 'x';
        speedSel.appendChild(opt);
      });

      // 테마 기반으로 버튼/슬라이더/셀렉트 색상을 통일
      function injectPlayerStyles(tokens, isDark) {
        const id = 'editor-music-player-theme';
        let style = document.getElementById(id);
        const accent = tokens.btnBg || '#0e639c';
        const fg = tokens.fg || (isDark ? '#e6e6e6' : '#1e1e1e');
        const bg = tokens.bg || (isDark ? '#252526' : '#ffffff');
        const border = tokens.border || (isDark ? '#3c3c3c' : '#e5e5e5');
        const hover = tokens.hoverBg || (isDark ? '#2a2a2a' : '#f3f3f3');
        const caretFill = encodeURIComponent(isDark ? '#cfd3d7' : '#4a4d50');

        const css = `
          /* 공통 */
          #editor-music-player button,
          #editor-music-player select {
            background: color-mix(in oklab, ${bg} 88%, transparent);
            color: ${fg};
            border: 1px solid ${border};
            outline: none;
          }
          #editor-music-player button:hover,
          #editor-music-player select:hover {
            background: ${hover};
          }
          #editor-music-player button:focus-visible,
          #editor-music-player select:focus-visible,
          #editor-music-player input[type="range"]:focus-visible {
            outline: none;
            border-color: ${accent};
            box-shadow: 0 0 0 2px ${accent}55;
          }

          /* 셀렉트(속도) – 기본 파란 하이라이트 제거 + 캐럿 커스텀 */
          #editor-music-player select {
            -webkit-appearance: none;
            appearance: none;
            padding: 5px 26px 5px 8px;
            border-radius: 8px;
            background-color: ${bg};
            color: ${fg};
            background-image: url("data:image/svg+xml;utf8,<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 12 8'><path fill='${caretFill}' d='M1 1l5 5 5-5'/></svg>");
            background-repeat: no-repeat;
            background-position: right 8px center;
            background-size: 12px 8px;
          }

          /* 버튼 모서리/전경 */
          #editor-music-player button {
            border-radius: 8px;
            color: ${fg};
          }

          /* 슬라이더 – 트랙/썸브를 테마 컬러로 */
          #editor-music-player input[type="range"] {
            -webkit-appearance: none;
            appearance: none;
            height: 18px;
            background: transparent;
          }
          /* WebKit (Chromium/Electron) */
          #editor-music-player input[type="range"]::-webkit-slider-runnable-track {
            height: 4px;
            border-radius: 999px;
            background: color-mix(in oklab, ${bg} 72%, transparent);
          }
          #editor-music-player input[type="range"]::-webkit-slider-thumb {
            -webkit-appearance: none;
            appearance: none;
            width: 12px; height: 12px;
            margin-top: -4px; /* 트랙 중앙정렬 */
            border-radius: 50%;
            background: ${accent};
            border: 1px solid ${border};
            box-shadow: 0 0 0 2px color-mix(in oklab, ${bg} 60%, transparent);
            cursor: pointer;
          }
          /* Firefox */
          #editor-music-player input[type="range"]::-moz-range-track {
            height: 4px;
            border-radius: 999px;
            background: color-mix(in oklab, ${bg} 72%, transparent);
          }
          #editor-music-player input[type="range"]::-moz-range-thumb {
            width: 12px; height: 12px;
            border-radius: 50%;
            background: ${accent};
            border: 1px solid ${border};
            cursor: pointer;
          }
          #editor-music-player input[type="range"]::-moz-range-progress {
            height: 4px;
            border-radius: 999px;
            background: color-mix(in oklab, ${accent} 40%, transparent);
          }
        `;

        if (!style) {
          style = document.createElement('style');
          style.id = id;
          document.head.appendChild(style);
        }
        style.textContent = css;
      }

      injectPlayerStyles(tokens, isDark);

      let pitchPreserve = JSON.parse(localStorage.getItem(STORAGE.pitch) || 'false'); // 기본: 꺼짐

      function setPitchPreserve(preserve) {
        ['preservesPitch','mozPreservesPitch','webkitPreservesPitch'].forEach((p)=>{
          if (p in audio) { try { audio[p] = preserve; } catch {} }
        });
        localStorage.setItem(STORAGE.pitch, String(!!preserve));
      }
      setPitchPreserve(pitchPreserve);

      function applyRateFromUI() {
        const r = parseFloat(speedSel.value || '1');
        const rate = RATES.includes(r) ? r : 1;
        audio.playbackRate = rate;
        audio.defaultPlaybackRate = rate;
        localStorage.setItem(STORAGE.rate, String(rate));
      }

      applyRateFromUI();

      ['preservesPitch', 'mozPreservesPitch', 'webkitPreservesPitch'].forEach((p) => {
        if (p in audio) { try { audio[p] = false; } catch {} }
      });

      speedSel.addEventListener('change', applyRateFromUI);
      speedSel.addEventListener('wheel', (e) => {
        e.preventDefault();
        const dir = e.deltaY > 0 ? 1 : -1;
        let i = RATES.indexOf(parseFloat(speedSel.value));
        i = Math.max(0, Math.min(RATES.length - 1, i + dir));
        speedSel.value = String(RATES[i]);
        applyRateFromUI();
      }, {passive: false});

      speedSel.addEventListener('dblclick', () => {
        speedSel.value = '1';
        applyRateFromUI();
      });

      row.insertBefore(speedSel, addBtn);

      const pitchBtn = mkBtn(pitchPreserve ? '🔒' : '🔓', '피치 보정 토글', '피치 보정(🔒=고정, 🔓=해제)');
      function updatePitchBtn(){ pitchBtn.textContent = pitchPreserve ? '🔒' : '🔓'; }
      pitchBtn.addEventListener('click', () => {
        pitchPreserve = !pitchPreserve;
        setPitchPreserve(pitchPreserve);
        updatePitchBtn();
      });
      row.insertBefore(pitchBtn, addBtn);
      updatePitchBtn();

      // State
      let playlist = [...REMOTE_PRESETS];
      let idx = clampIndex(parseInt(localStorage.getItem(STORAGE.idx) || '0', 10));
      let collapsed = localStorage.getItem(STORAGE.collapsed) === 'true';
      let listOpen = localStorage.getItem(STORAGE.listOpen) === 'true';
      const localObjectURLs = new Set();

      // Utils
      function clampIndex(i) {
        if (!playlist.length) return 0;
        return (i % playlist.length + playlist.length) % playlist.length;
      }
      function updatePlayIcon() {
        playBtn.textContent = audio.paused ? '▶' : '⏸';
      }
      function setCollapsed(v) {
        collapsed = !!v;
        localStorage.setItem(STORAGE.collapsed, String(collapsed));
        title.style.display = collapsed ? 'none' : '';
        vol.style.display = collapsed ? 'none' : '';
        addBtn.style.display = collapsed ? 'none' : '';
        addDirBtn.style.display = collapsed ? 'none' : '';
        listBtn.style.display = collapsed ? 'none' : '';
        speedSel.style.display = collapsed ? 'none' : '';
        collapseBtn.textContent = collapsed ? '▣' : '–';
        collapseBtn.title = collapsed ? '펼치기' : '접기';
        if (collapsed) hideList();
      }
      function setListOpen(v) {
        listOpen = !!v;
        localStorage.setItem(STORAGE.listOpen, String(listOpen));
        listWrap.style.display = listOpen ? 'block' : 'none';
      }
      function toggleList() { setListOpen(!listOpen); }
      function hideList() { setListOpen(false); }

      function humanTitleFromFile(file) {
        return file.name.replace(/\.[^.]+$/, '');
      }
      function isAudioFile(file) {
        if (file.type && file.type.startsWith('audio/')) return true;
        return /\.(mp3|m4a|aac|flac|wav|ogg|oga|opus|webm)$/i.test(file.name);
      }
      function genId() {
        return 't_' + Date.now().toString(36) + '_' + Math.random().toString(36).slice(2, 8);
      }

      function addFiles(filesLike) {
        const files = Array.from(filesLike || []).filter(isAudioFile);
        if (!files.length) return;
        const wasEmpty = playlist.length === 0;
        files.forEach((f) => {
          const url = URL.createObjectURL(f);
          localObjectURLs.add(url);
          playlist.push({ id: genId(), title: humanTitleFromFile(f), url, file: f, source: 'local' });
        });
        renderPlaylist();
        if (wasEmpty) setCurrent(0, false);
      }

      function removeTrackById(id) {
        const removeIdx = playlist.findIndex((t) => t.id === id);
        if (removeIdx === -1) return;
        const wasCurrent = removeIdx === idx;
        const t = playlist[removeIdx];
        if (t.source === 'local' && t.url && localObjectURLs.has(t.url)) {
          try { URL.revokeObjectURL(t.url); } catch {}
          localObjectURLs.delete(t.url);
        }
        playlist.splice(removeIdx, 1);
        if (!playlist.length) {
          audio.pause();
          audio.removeAttribute('src');
          audio.load();
          idx = 0;
          title.textContent = '재생목록이 비었습니다';
        } else {
          if (removeIdx < idx) idx -= 1;
          else if (wasCurrent) idx = clampIndex(idx);
          setCurrent(idx, false);
        }
        renderPlaylist();
      }

      function setCurrent(i, autoplay) {
        if (!playlist.length) return;
        idx = clampIndex(i);
        localStorage.setItem(STORAGE.idx, String(idx));
        const t = playlist[idx];
        title.textContent = t.title || 'Untitled';
        audio.src = t.url || '';
        audio.playbackRate = parseFloat(speedSel.value || '1');
        if (autoplay) audio.play().catch(() => updatePlayIcon()); else updatePlayIcon();
        highlightCurrent();
      }
      function nextTrack(autoplay) { if (playlist.length) setCurrent(idx + 1, autoplay ?? !audio.paused); }
      function prevTrack() { if (playlist.length) setCurrent(idx - 1, !audio.paused); }

      function highlightCurrent() {
        const rows = list.querySelectorAll('[data-track-id]');
        rows.forEach((row) => {
          const active = playlist[idx] && row.getAttribute('data-track-id') === playlist[idx].id;
          row.style.background = active ? (tokens.hoverBg || (isDark ? '#2a2a2a' : '#f0f0f0')) : 'transparent';
        });
      }

      function renderPlaylist() {
        list.innerHTML = '';
        playlist.forEach((t, i) => {
          const row = document.createElement('div');
          row.setAttribute('data-track-id', t.id);
          Object.assign(row.style, {
            display: 'grid',
            gridTemplateColumns: 'auto 1fr auto',
            alignItems: 'center',
            gap: '8px',
            padding: '6px',
            overflowY: 'auto',
            overflowX: 'hidden',
            borderRadius: '8px',
            cursor: 'pointer',
          });

          const indexBadge = document.createElement('span');
          indexBadge.textContent = String(i + 1).padStart(2, '0');
          Object.assign(indexBadge.style, { fontSize: '11px', opacity: '0.7', width: '24px', textAlign: 'right' });

          const name = document.createElement('div');
          name.textContent = t.title || 'Untitled';
          Object.assign(name.style, { fontSize: '12px', overflow: 'hidden', textOverflow: 'ellipsis', whiteSpace: 'nowrap' });

          const del = document.createElement('button');
          del.type = 'button';
          del.textContent = '✕';
          del.title = '이 트랙 제거';
          Object.assign(del.style, {
            fontSize: '12px',
            padding: '2px 6px',
            borderRadius: '6px',
            border: '1px solid ' + (tokens.border || 'rgba(255,255,255,0.18)'),
            background: 'transparent',
            color: tokens.fg || '#e6e6e6',
            cursor: 'pointer',
          });
          del.onmouseenter = () => { del.style.background = tokens.hoverBg || (isDark ? '#2a2a2a' : '#f3f3f3'); };
          del.onmouseleave = () => { del.style.background = 'transparent'; };

          del.addEventListener('click', (e) => { e.stopPropagation(); removeTrackById(t.id); });
          row.addEventListener('click', () => {
            const goIndex = playlist.findIndex((x) => x.id === t.id);
            if (goIndex !== -1) setCurrent(goIndex, true);
          });

          row.appendChild(indexBadge);
          row.appendChild(name);
          row.appendChild(del);
          list.appendChild(row);
        });
        highlightCurrent();
      }

      // Init
      audio.volume = parseFloat(vol.value);
      setCollapsed(localStorage.getItem(STORAGE.collapsed) === 'true');
      setListOpen(localStorage.getItem(STORAGE.listOpen) === 'true');
      if (playlist.length) setCurrent(idx, false);
      renderPlaylist();
      updatePlayIcon();

      // Events
      playBtn.addEventListener('click', () => {
        if (!playlist.length) return filePicker.click();
        if (audio.paused) audio.play().catch(() => {}); else audio.pause();
      });
      nextBtn.addEventListener('click', () => nextTrack(true));
      prevBtn.addEventListener('click', () => prevTrack());
      collapseBtn.addEventListener('click', () => setCollapsed(!collapsed));
      listBtn.addEventListener('click', () => toggleList());

      vol.addEventListener('input', () => {
        audio.volume = parseFloat(vol.value);
        localStorage.setItem(STORAGE.vol, vol.value);
      });

      audio.addEventListener('play', updatePlayIcon);
      audio.addEventListener('pause', updatePlayIcon);
      audio.addEventListener('ended', () => nextTrack(true));
      audio.addEventListener('error', () => {
        title.textContent = '재생 오류: 다음 트랙으로 이동';
        setTimeout(() => nextTrack(true), 800);
      });

      // 파일/폴더 추가
      addBtn.addEventListener('click', () => filePicker.click());
      filePicker.addEventListener('change', () => { addFiles(filePicker.files); filePicker.value = ''; });

      addDirBtn.addEventListener('click', () => dirPicker.click());
      dirPicker.addEventListener('change', () => { addFiles(dirPicker.files); dirPicker.value = ''; });

      // 드래그&드롭
      const dragHighlightOn = () => { panel.style.outline = `2px dashed ${tokens.border || (isDark ? '#3c3c3c' : '#cfcfcf')}`; };
      const dragHighlightOff = () => { panel.style.outline = 'none'; };
      panel.addEventListener('dragover', (e) => {
        if (e.dataTransfer && Array.from(e.dataTransfer.items || []).some(it => it.kind === 'file')) {
          e.preventDefault(); e.stopPropagation(); dragHighlightOn();
        }
      });
      panel.addEventListener('dragleave', dragHighlightOff);
      panel.addEventListener('drop', (e) => {
        e.preventDefault(); e.stopPropagation(); dragHighlightOff();
        if (e.dataTransfer && e.dataTransfer.files) addFiles(e.dataTransfer.files);
      });

      // unload 시 ObjectURL 정리
      function revokeAllLocalUrls() {
        localObjectURLs.forEach((u) => { try { URL.revokeObjectURL(u); } catch {} });
        localObjectURLs.clear();
      }
      window.addEventListener('unload', revokeAllLocalUrls);
    }
  })();
});