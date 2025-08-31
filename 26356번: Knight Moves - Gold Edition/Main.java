import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    private static final int[] DR = {-2, -2, 2, 2, -1, 1, -1, 1};
    private static final int[] DC = {-1, 1, -1, 1, -2, -2, 2, 2};

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        int t = fs.nextInt();
        StringBuilder out = new StringBuilder();
        for (int caseIdx = 1; caseIdx <= t; caseIdx++) {
            int n = fs.nextInt();
            int r1 = fs.nextInt();
            int c1 = fs.nextInt();
            int r2 = fs.nextInt();
            int c2 = fs.nextInt();
            int ans = solveCase(n, r1 - 1, c1 - 1, r2 - 1, c2 - 1);
            out.append("Case #").append(caseIdx).append(": ").append(ans).append('\n').append('\n');
        }
        System.out.print(out.toString());
    }

    private static int solveCase(int n, int sr, int sc, int tr, int tc) {
        if (sr == tr && sc == tc) {
            return 0;
        }
        boolean[][] visited = new boolean[n][n];
        ArrayDeque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{sr, sc, 0});
        visited[sr][sc] = true;

        while (!q.isEmpty()) {
            int[] cur = q.pollFirst();
            int r = cur[0];
            int c = cur[1];
            int d = cur[2];

            for (int i = 0; i < 8; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                if (!inBounds(nr, nc, n) || visited[nr][nc]) {
                    continue;
                }
                if (nr == tr && nc == tc) {
                    return d + 1;
                }
                visited[nr][nc] = true;
                q.addLast(new int[]{nr, nc, d + 1});
            }
        }

        return -1;
    }

    private static boolean inBounds(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    private static final class FastScanner {
        private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        private StringTokenizer st;

        int nextInt() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) {
                    throw new IOException("Unexpected end of input");
                }
                st = new StringTokenizer(line);
            }

            return Integer.parseInt(st.nextToken());
        }
    }
}