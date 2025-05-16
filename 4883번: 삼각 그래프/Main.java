import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static final long INF = Long.MAX_VALUE / 4; // “infinite” but safe from overflow

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int tc = 1;

        while (true) {
            String line = br.readLine();
            if (line == null)
                break; // safety
            int n = Integer.parseInt(line.trim());
            if (n == 0)
                break; // end-marker

            long[] prev = new long[3];
            long[] cur = new long[3];

            // ──────── read row 0 ────────
            StringTokenizer st0 = new StringTokenizer(br.readLine());
            long a0 = Long.parseLong(st0.nextToken());
            long b0 = Long.parseLong(st0.nextToken()); // start
            long c0 = Long.parseLong(st0.nextToken());

            prev[0] = INF; // cannot start here
            prev[1] = b0; // (0,1)
            prev[2] = b0 + c0; // (0,1) → (0,2)

            // ──────── process rows 1..n-1 ────────
            for (int i = 1; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                long a = Long.parseLong(st.nextToken());
                long b = Long.parseLong(st.nextToken());
                long c = Long.parseLong(st.nextToken());

                cur[0] = Math.min(prev[0], prev[1]) + a;

                cur[1] = Math.min(Math.min(cur[0], prev[0]),
                        Math.min(prev[1], prev[2])) + b;

                cur[2] = Math.min(Math.min(cur[1], prev[1]), prev[2]) + c;

                // slide window
                System.arraycopy(cur, 0, prev, 0, 3);
            }

            out.append(tc++).append(". ").append(prev[1]).append('\n');
        }
        System.out.print(out);
    }
}
