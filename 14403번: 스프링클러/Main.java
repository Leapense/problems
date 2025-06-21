import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public final class Main {
    private Main() {

    }

    private static class Pair {
        final long d1;
        final long d2;

        Pair(long d1, long d2) {
            this.d1 = d1;
            this.d2 = d2;
        }
    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            long x1 = Long.parseLong(st.nextToken());
            long y1 = Long.parseLong(st.nextToken());
            long x2 = Long.parseLong(st.nextToken());
            long y2 = Long.parseLong(st.nextToken());

            Pair[] flowers = new Pair[n];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                long x = Long.parseLong(st.nextToken());
                long y = Long.parseLong(st.nextToken());
                
                long dx1 = x - x1;
                long dy1 = y - y1;
                long dx2 = x - x2;
                long dy2 = y - y2;

                long d1 = dx1 * dx1 + dy1 * dy1;
                long d2 = dx2 * dx2 + dy2 * dy2;

                flowers[i] = new Pair(d1, d2);
            }
            Arrays.sort(flowers, (a, b) -> Long.compare(a.d1, b.d1));

            long[] suffixMax = new long[n + 1];
            suffixMax[n] = 0L;
            for (int i = n - 1; i >= 0; i--) {
                suffixMax[i] = Math.max(flowers[i].d2, suffixMax[i + 1]);
            }

            long answer = Long.MAX_VALUE;

            answer = Math.min(answer, suffixMax[0]);

            for (int i = 0; i < n; i++) {
                long r1Sq = flowers[i].d1;
                long r2Sq = suffixMax[i + 1];
                answer = Math.min(answer, r1Sq + r2Sq);
            }

            System.out.println(answer);
        }
    }
}