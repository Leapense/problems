import java.io.*;
import java.util.*;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        public FastReader(InputStream is) { br = new BufferedReader(new InputStreamReader(is)); }
        String nextNonEmptyLine() throws IOException {
            String s;
            while ((s = br.readLine()) != null) {
                if (s.trim().length() > 0) return s.trim();
            }
            return null;
        }
    }

    public static void main(String[] args) throws Exception {
        FastReader fr = new FastReader(System.in);
        String tLine = fr.nextNonEmptyLine();
        int T = Integer.parseInt(tLine);
        StringBuilder out = new StringBuilder();

        for (int tc = 0; tc < T; tc++) {
            String nLine = fr.nextNonEmptyLine();
            while (nLine != null && nLine.isEmpty()) nLine = fr.nextNonEmptyLine();
            int N = Integer.parseInt(nLine);

            char[][] target = new char[N][];
            for (int i = 0; i < N; i++) {
                String row = fr.nextNonEmptyLine();
                while (row.length() < N) {
                    String extra = fr.nextNonEmptyLine();
                    if (extra == null) break;
                    if (extra.length() >= N) {
                        row = extra;
                        break;
                    }
                }
                target[i] = row.toCharArray();
            }

            int K = Integer.parseInt(fr.nextNonEmptyLine());
            char[][] stamp = new char[K][];
            for (int i = 0; i < K; i++) {
                String row = fr.nextNonEmptyLine();
                while (row.length() < K) {
                    String extra = fr.nextNonEmptyLine();
                    if (extra == null) break;
                    if (extra.length() >= K) { row = extra; break; }
                }
                stamp[i] = row.toCharArray();
            }

            boolean ans = solveCase(N, target, K, stamp);
            out.append(ans ? "YES" : "NO").append('\n');
        }

        System.out.print(out.toString());
    }

    static boolean solveCase(int N, char[][] target, int K, char[][] stamp) {
        List<char[][]> rotations = new ArrayList<>();
        rotations.add(copy(stamp));
        rotations.add(rotate90(stamp));
        rotations.add(rotate90(rotations.get(1)));
        rotations.add(rotate90(rotations.get(2)));

        List<int[][]> starsPerRot = new ArrayList<>();
        int totalStarInAnyRot = 0;
        for (char[][] r : rotations) {
            List<int[]> list = new ArrayList<>();
            for (int i = 0; i < K; i++) {
                for (int j = 0; j < K; j++) {
                    if (r[i][j] == '*') list.add(new int[]{i, j});
                }
            }

            int[][] arr = new int[list.size()][2];
            for (int idx = 0; idx < list.size(); idx++) arr[idx] = list.get(idx);
            starsPerRot.add(arr);
            totalStarInAnyRot += arr.length;
        }

        boolean stampHasAnyStar = false;
        for (int[][] arr : starsPerRot) if (arr.length > 0) {
            stampHasAnyStar = true;
            break;
        }
        if (!stampHasAnyStar) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (target[i][j] == '*') return false;
                }
            }

            return true;
        }

        boolean[][] cover = new boolean[N][N];
        for (int rot = 0; rot < 4; rot++) {
            int[][] stars = starsPerRot.get(rot);
            if (stars.length == 0) continue;
            for (int i = 0; i <= N - K; i++) {
                for (int j = 0; j <= N - K; j++) {
                    boolean ok = true;
                    for (int[] uv : stars) {
                        int x = i + uv[0];
                        int y = j + uv[1];
                        if (target[x][y] != '*') {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;
                    for (int[] uv : stars) {
                        int x = i + uv[0];
                        int y = j + uv[1];
                        cover[x][y] = true;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (target[i][j] == '*' && !cover[i][j]) return false;
            }
        }

        return true;
    }

    static char[][] copy(char[][] a) {
        int n = a.length;
        char[][] b = new char[n][n];
        for (int i = 0; i < n; i++) b[i] = Arrays.copyOf(a[i], a[i].length);
        return b;
    }

    static char[][] rotate90(char[][] m) {
        int n = m.length;
        char[][] r = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r[j][n - 1 - i] = m[i][j];
            }
        }

        return r;
    }
}