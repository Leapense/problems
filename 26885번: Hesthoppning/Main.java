import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static final int[] DR = {-2, -2, -1, -1, 1, 1, 2, 2};
    private static final int[] DC = {-1, 1, -2, 2, -2, 2, -1, 1};

    private static final class Cell {
        final int r;
        final int c;
        Cell(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        String firstLine = fs.nextLineSkippingBlanks();
        if (firstLine == null) {
            return;
        }

        StringTokenizer st = new StringTokenizer(firstLine);
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        char[][] grid = new char[n][m];
        List<Cell> horses = new ArrayList<>(2);
        for (int i = 0; i < n; i++) {
            String line = fs.nextNonEmptyLineWithMinLength(m);
            for (int j = 0; j < m; j++) {
                char ch = line.charAt(j);
                grid[i][j] = ch;
                if (ch == 'H') {
                    horses.add(new Cell(i, j));
                }
            }
        }

        boolean reachable = bfsReachable(grid, n, m, horses.get(0), horses.get(1));
        System.out.println(reachable ? "JA" : "NEJ");
    }

    private static boolean bfsReachable(char[][] grid, int n, int m, Cell start, Cell target) {
        boolean[][] visited = new boolean[n][m];
        ArrayDeque<Cell> queue = new ArrayDeque<>();
        queue.add(start);
        visited[start.r][start.c] = true;

        while (!queue.isEmpty()) {
            Cell cur = queue.poll();
            if (cur.r == target.r && cur.c == target.c) {
                return true;
            }
            for (int k = 0; k < 8; k++) {
                int nr = cur.r + DR[k];
                int nc = cur.c + DC[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                    continue;
                }
                if (visited[nr][nc]) {
                    continue;
                }
                char cell = grid[nr][nc];
                if (cell == '#') {
                    continue;
                }

                visited[nr][nc] = true;
                queue.add(new Cell(nr, nc));
            }
        }

        return false;
    }

    private static final class FastScanner {
        private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String nextLineSkippingBlanks() throws IOException {
            String s = br.readLine();
            while (s != null && s.trim().isEmpty()) {
                s = br.readLine();
            }
            return s;
        }

        String nextNonEmptyLineWithMinLength(int minLen) throws IOException {
            String s = nextLineSkippingBlanks();
            while (s != null && s.length() < minLen) {
                s = br.readLine();
            }
            return s == null ? "" : s;
        }
    }
}