import java.io.*;
import java.util.*;

public class Main {
    static final int[] DR = { -1, 1, 0, 0 };
    static final int[] DC = { 0, 0, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int datasets = Integer.parseInt(br.readLine().trim());

        while (datasets-- > 0) {
            int m = Integer.parseInt(br.readLine().trim());
            char[][] grid = new char[m][];
            for (int i = 0; i < m; i++) {
                grid[i] = br.readLine().toCharArray();
            }

            int answer = bfs(grid, m);
            bw.write(String.valueOf(answer));
            bw.newLine();
        }

        bw.flush();
    }

    private static int bfs(char[][] grid, int m) {
        if (grid[0][0] == '*' || grid[m - 1][m - 1] == '*') {
            return -1;
        }

        boolean[][] visited = new boolean[m][m];
        int[][] dist = new int[m][m];

        Deque<int[]> queue = new ArrayDeque<>();
        queue.add(new int[] { 0, 0 });
        visited[0][0] = true;
        dist[0][0] = 0;

        while (!queue.isEmpty()) {
            int[] cur = queue.pollFirst();
            int r = cur[0], c = cur[1];
            if (r == m - 1 && c == m - 1) {
                return dist[r][c];
            }

            int nd = dist[r][c] + 1;

            for (int d = 0; d < 4; d++) {
                int nr = r + DR[d], nc = c + DC[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] != '*') {
                    visited[nr][nc] = true;
                    dist[nr][nc] = nd;
                    queue.addLast(new int[] { nr, nc });
                }
            }
        }

        return -1;
    }
}