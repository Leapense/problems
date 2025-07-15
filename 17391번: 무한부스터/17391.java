import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    private static int n;
    private static int m;
    private static int[][] map;
    private static int[][] dist;

    static class Point {
        int r;
        int c;

        public Point(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            map = new int[n][m];
            dist = new int[n][m];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < m; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
                Arrays.fill(dist[i], Integer.MAX_VALUE);
            }

            int result = solve();
            System.out.println(result);
        }
    }

    private static int solve() {
        Queue<Point> queue = new ArrayDeque<>();
        dist[0][0] = 1;
        queue.offer(new Point(0, 0));

        int minStops = Integer.MAX_VALUE;

        while (!queue.isEmpty()) {
            Point current = queue.poll();
            int r = current.r;
            int c = current.c;
            int currentStops = dist[r][c];

            if (currentStops >= minStops) {
                continue;
            }

            int boosters = map[r][c];

            if (r == n - 1 && c == m - 1) {
                minStops = Math.min(minStops, currentStops);
                continue;
            }

            if (r == n - 1) {
                int distToDest = (m - 1) - c;
                if (distToDest > 0 && distToDest <= boosters) {
                    minStops = Math.min(minStops, currentStops);
                }
            }
            if (c == m - 1) {
                int distToDest = (n - 1) - r;
                if (distToDest > 0 && distToDest <= boosters) {
                    minStops = Math.min(minStops, currentStops);
                }
            }
            for (int i = 1; i <= boosters; i++) {
                int nextR = r + i;
                if (nextR < n && dist[nextR][c] > currentStops + 1) {
                    dist[nextR][c] = currentStops + 1;
                    queue.offer(new Point(nextR, c));
                }
            }

            for (int i = 1; i <= boosters; i++) {
                int nextC = c + i;
                if (nextC < m && dist[r][nextC] > currentStops + 1) {
                    dist[r][nextC] = currentStops + 1;
                    queue.offer(new Point(r, nextC));
                }
            }
        }

        return minStops;
    }
}