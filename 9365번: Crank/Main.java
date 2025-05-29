import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// 클래스를 final로 선언하여 상속 방지 (S110)
// 유틸리티 클래스는 인스턴스화 가능한 public 생성자를 가져서는 안됨 (S1118)
public final class Main {
    // 상수는 static final 이어야 하며 대문자 스네이크 케이스 사용 (S115)
    private static final int[] DELTA_ROWS = {-1, 1, 0, 0};
    private static final int[] DELTA_COLS = {0, 0, -1, 1};
    private static final int NUM_DIRECTIONS = 4;

    // Java 14+ record 사용, 불변 객체 (하지만, 온라인 코딩 사이트에서 이 record는 프리뷰 버전 입장이기 때문에 가급적이면 다른 대체 타입으로 사용해야 함.)
    public static class Point {
        int r;
        int c;
        public Point(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static void main(String[] args) {
        // "try-with-resources" 문을 사용하여 "Scanner" 리소스 관리 (S2095)
        try (Scanner scanner = new Scanner(System.in)) {
            int testCases = scanner.nextInt();
            
            // 효율적인 문자열 연결을 위해 StringBuilder 사용
            StringBuilder resultBuilder = new StringBuilder();
            for (int t = 1; t <= testCases; t++) {
                resultBuilder.append("Case #")
                             .append(t)
                             .append(": ")
                             .append(solveCurrentTestCase(scanner))
                             .append("\n");
            }

            // 표준 출력 사용은 로거로 대체 권장 (S106) - 경쟁 프로그래밍에서는 허용
            System.out.print(resultBuilder.toString());
        }
    }

    private static String solveCurrentTestCase(final Scanner scanner)
    {
        final int rows = scanner.nextInt();
        final int cols = scanner.nextInt();

        // 보스 좌표 (1-based to 0-based)
        final int bossR = scanner.nextInt() - 1;
        final int bossC = scanner.nextInt() - 1;

        // 지역 변수에 final 키워드 사용 권장 (S1121)
        final int[][] heights = new int[rows][cols];
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                heights[r][c] = scanner.nextInt();
            }
        }

        final boolean[][] canReachFromBoss = new boolean[rows][cols];
        // default false
        // Queue 인터페이스 사용, 구현체는 LinkedList
        final Queue<Point> queue = new LinkedList<>();

        // BFS 시작점: 보스 건물
        // 문제 제약상 보스 좌표는 항상 유효함. (1 <= A <= R, 1 <= B <= C)
        queue.offer(new Point(bossR, bossC));
        canReachFromBoss[bossR][bossC] = true;

        while (!queue.isEmpty()) {
            final Point current = queue.poll();
            final int r = current.r;
            final int c = current.c;

            for (int i = 0; i < NUM_DIRECTIONS; i++)
            {
                final int nr = r + DELTA_ROWS[i];
                final int nc = c + DELTA_COLS[i];

                if (isValidCoordinate(nr, nc, rows, cols) && !canReachFromBoss[nr][nc]) {
                    // 역방향 BFS 조건:
                    // 원래 경로에서 (nr,nc) -> (r,c) 이동이 가능했어야 함.
                    // 즉, heights[r][c] <= heights[nr][nc] (원래 문제: 낮은 곳/같은 곳으로만 이동).
                    if (heights[r][c] <= heights[nr][nc]) {
                        canReachFromBoss[nr][nc] = true;
                        queue.offer(new Point(nr, nc));
                    }
                }
            }
        }

        int reachableBoundaryCount = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (isBoundary(r, c, rows, cols)) {
                    if (canReachFromBoss[r][c]) {
                        reachableBoundaryCount++;
                    }
                }
            }
        }

        return Integer.toString(reachableBoundaryCount);
    }

    private static boolean isValidCoordinate(int r, int c, int maxRows, int maxCols) {
        return r >= 0 && r < maxRows && c >= 0 && c < maxCols;
    }

    private static boolean isBoundary(int r, int c, int maxRows, int maxCols) {
        return r == 0 || r == maxRows - 1 || c == 0 || c == maxCols - 1;
    }
}