## file: plot_banner_complexity.m
## 사용법:
##   octave --no-gui plot_banner_complexity.m

function plot_banner_complexity()
  % 1) 다크 테마 배경 설정
  h_fig = figure('Color', 'k', 'Position', [200,200,800,500]);
  h_ax  = axes('Parent', h_fig);
  set(h_ax, ...
      'Color',      'k', ...         % 축 배경 검정
      'XColor',     'w', ...         % 눈금 레이블 흰색
      'YColor',     'w', ...
      'GridColor',  [1,1,1]*0.4, ... % 그리드 연한 회색
      'GridAlpha',  0.3, ...
      'LineWidth',  1);

  hold(h_ax, 'on');
  grid(h_ax, 'on');
  
  % 2) 입력 크기 (로그 스케일)
  N = logspace(1, 3, 200);  % 10 ~ 1000 범위
  
  % 3) 복잡도 계산
  time_complexity  = N .^ 2;   % O(N^2)
  space_complexity = N .^ 2;   % O(N^2)
  
  % 4) 로그-로그 플롯
  h1 = loglog(h_ax, N, time_complexity,  ...
              'LineWidth', 2, ...
              'Color',      [0.1, 0.6, 1]);    % 파란 계열
  h2 = loglog(h_ax, N, space_complexity, ...
              '--', ...
              'LineWidth', 2, ...
              'Color',      [1, 0.6, 0.1]);    % 주황 계열
  
  % 5) 축 레이블 & 제목
  xlabel('Grid size N (N = M)', 'Color', 'w', 'FontSize', 12);
  ylabel('Operations / Memory', 'Color', 'w', 'FontSize', 12);
  title('Time Complexity / Space Complexity Visualizer', 'Color', 'w', 'FontSize', 14);
  
  % 6) 범례
  legend([h1, h2], {'Time: O(N^2)', 'Space: O(N^2)'}, ...
         'TextColor', 'w', 'Location', 'northwest');
  
  hold(h_ax, 'off');
end

% 스크립트 실행 시 바로 그림을 띄우도록 호출
plot_banner_complexity();

