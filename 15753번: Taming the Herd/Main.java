import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public final class Main {
    private Main() {
        throw new IllegalStateException("Utility class");
    }

    private static final int INF = 1_000_000_000;

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine().trim());
            int[] log = new int[n + 1];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                log[i] = Integer.parseInt(st.nextToken());
            }

            if (log[1] != -1 && log[1] != 0) {
                System.out.println(-1);
                return;
            }

            log[1] = 0;
            boolean[][] valid = new boolean[n + 1][n + 1];
            for (int s = 1; s <= n; s++) {
                int expected = 0;
                for (int e = s; e <= n; e++) {
                    if (log[e] != -1 && log[e] != expected) {
                        break;
                    }

                    valid[s][e] = true;
                    expected++;
                }
            }

            int[] minBreak = new int[n + 1];
            int[] maxBreak = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                minBreak[i] = INF;
                maxBreak[i] = -INF;
            }

            for (int i = 1; i <= n; i++) {
                for (int s = 1; s <= i; s++) {
                    if (!valid[s][i] || minBreak[s - 1] == INF) {
                        continue;
                    }

                    minBreak[i] = Math.min(minBreak[i], minBreak[s - 1] + 1);
                    maxBreak[i] = Math.max(maxBreak[i], maxBreak[s - 1] + 1);
                }
            }

            if (minBreak[n] == INF) {
                System.out.println(-1);
            } else {
                System.out.println(minBreak[n] + " " + maxBreak[n]);
            }
        }
    }
}