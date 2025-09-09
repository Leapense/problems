import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static char[][] grid;
    static boolean[][] vis;

    static final int[] DR = {-1, 1, 0, 0};
    static final int[] DC = {0, 0, -1, 1};

    static boolean isEntrance(char c) {
        return c >= 'A' && c <= 'W';
    }

    static boolean isWall(char c) {
        return c == 'X';
    }

    static boolean isTraversable(char c) {
        return c == ' ' || c == '.' || isEntrance(c);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] first = br.readLine().trim().split("\\s+");
        n = Integer.parseInt(first[0]);
        m = Integer.parseInt(first[1]);

        grid = new char[n][m];
        for (int i = 0; i < n; i++) {
            String line = br.readLine();

            if (line.length() < m) {
                StringBuilder sb = new StringBuilder(line);
                while (sb.length() < m) sb.append(' ');
                line = sb.toString();
            }

            for (int j = 0; j < m; j++) {
                grid[i][j] = line.charAt(j);
            }
        }

        vis = new boolean[n][m];

        int minEntrances = 0;
        int unreachableDots = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (!vis[r][c] && isTraversable(grid[r][c])) {
                    int dotCount = 0;
                    boolean hasEntrance = false;

                    ArrayDeque<int[]> dq = new ArrayDeque<>();
                    dq.offer(new int[]{r, c});
                    vis[r][c] = true;

                    while (!dq.isEmpty()) {
                        int[] cur = dq.poll();
                        int cr = cur[0], cc = cur[1];
                        char curCh = grid[cr][cc];

                        if (curCh == '.') dotCount++;
                        if (isEntrance(curCh)) hasEntrance = true;

                        for (int k = 0; k < 4; k++) {
                            int nr = cr + DR[k];
                            int nc = cc + DC[k];
                            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                            if (vis[nr][nc]) continue;
                            char nextCh = grid[nr][nc];
                            if (!isTraversable(nextCh)) continue;

                            if (isEntrance(curCh) && isEntrance(nextCh)) continue;
                            vis[nr][nc] = true;
                            dq.offer(new int[]{nr, nc});
                        }
                    }
                    if (dotCount > 0) {
                        if (hasEntrance) minEntrances += 1;
                        else unreachableDots += dotCount;
                    }
                }
            }
        }
        
        System.out.println(minEntrances + " " + unreachableDots);
    }
}