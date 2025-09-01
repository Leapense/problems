import java.io.*;
import java.util.*;

public class Main {
    static final int[] DR = {-1, 1, 0, 0};
    static final int[] DC = {0, 0, -1, 1};
    static int toolBit(char ch) {
        if (ch == 'G') return 1;
        if (ch == 'B') return 2;
        if (ch == 'R') return 4;
        return 0;
    }

    static int solveOne(char[][] grid, int s) {
        int sr = -1, sc = -1, tr = -1, tc = -1;
        for (int r = 0; r < s; r++) {
            for (int c = 0; c < s; c++) {
                if (grid[r][c] == 'S') { sr = r; sc = c; }
                if (grid[r][c] == 'X') { tr = r; tc = c; }
            }
        }
        int INF = 1_000_000_000;
        int[][][] dist = new int[s][s][8];
        for (int r = 0; r < s; r++) for (int c = 0; c < s; c++) Arrays.fill(dist[r][c], INF);
        Deque<int[]> dq = new ArrayDeque<>();
        dist[sr][sc][0] = 0;
        dq.add(new int[]{sr, sc, 0});

        while (!dq.isEmpty()) {
            int[] cur = dq.pollFirst();
            int r = cur[0], c = cur[1], mask = cur[2];
            int d = dist[r][c][mask];
            if (r == tr && c == tc) continue;
            for (int k = 0; k < 4; k++) {
                int nr = r + DR[k], nc = c + DC[k];
                if (nr < 0 || nr >= s || nc < 0 || nc >= s) continue;
                char cell = grid[nr][nc];
                int bit = toolBit(cell);
                int nmask = mask | bit;
                int w = (nmask == mask) ? 0 : 1;
                if (dist[nr][nc][nmask] > d + w) {
                    dist[nr][nc][nmask] = d + w;
                    if (w == 0) dq.addFirst(new int[]{nr, nc, nmask});
                    else dq.addLast(new int[]{nr, nc, nmask});
                }
            }
        }
        int ans = INF;
        for (int m = 0; m < 8; m++) ans = Math.min(ans, dist[tr][tc][m]);
        return ans;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine().trim());
        for (int tc = 0; tc < t; tc++) {
            String line;
            do { line = br.readLine(); } while (line != null && line.trim().isEmpty());
            int s = Integer.parseInt(line.trim());
            char[][] grid = new char[s][s];
            for (int i = 0; i < s; i++) {
                String row = br.readLine();
                while (row != null && row.length() < s) row += br.readLine();
                grid[i] = row.toCharArray();
            }
            out.append(solveOne(grid, s)).append('\n');
        }
        System.out.print(out.toString());
    }
}