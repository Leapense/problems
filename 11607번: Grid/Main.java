import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public final class Main {
    private static final int MAX_N = 500;
    private static final int MAX_M = 500;

    private static final int[] DR = {-1, 1, 0, 0};
    private static final int[] DC = {0, 0, -1, 1};

    private static final class Point {
        final int row;
        final int col;

        Point(final int row, final int col) {
            this.row = row;
            this.col = col;
        }
    }

    public static void main(final String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());

        int[][] grid = new int[n][m];

        for (int i = 0; i < n; i++) {
            String line = reader.readLine().trim();
            for (int j = 0; j < m; j++) {
                grid[i][j] = line.charAt(j) - '0';
            }
        }

        int[][] dist = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dist[i][j] = -1;
            }
        }

        Deque<Point> queue = new ArrayDeque<>();

        dist[0][0] = 0;
        queue.offerLast(new Point(0, 0));

        while (!queue.isEmpty()) {
            Point current = queue.pollFirst();
            int r = current.row;
            int c = current.col;
            int jumps = grid[r][c];

            if (jumps == 0) {
                continue;
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + DR[d] * jumps;
                int nc = c + DC[d] * jumps;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    queue.offerLast(new Point(nr, nc));
                }
            }
        }

        int answer = dist[n - 1][m - 1];
        if (answer < 0) {
            System.out.println("IMPOSSIBLE");
        } else {
            System.out.println(answer);
        }
    }
}