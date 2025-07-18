import java.io.BufferedReader;
import java.io.InputStreamReader;

public final class Main
{
    private Main() { }

    public static void main(final String[] args) throws Exception {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final long target = Long.parseLong(br.readLine().trim());
        System.out.println(minFastForwardSeconds(target));
    }

    private static long minFastForwardSeconds(final long t) {
        if (t == 0) {
            return 0;
        }
        final long[] pow3 = new long[40];
        pow3[0] = 1L;
        for (int i = 1; i < pow3.length; i++) {
            pow3[i] = pow3[i - 1] * 3L;
        }

        long best = Long.MAX_VALUE;
        for (int m = 0; m < pow3.length; m++) {
            long baseDist = 1L;
            for (int k = 1; k < m; k++) {
                baseDist += 2L * pow3[k];
            }
            if (m >= 1) {
                baseDist += pow3[m];
            }
            if (baseDist > t) {
                continue;
            }

            long diff = t - baseDist;
            long extra = 0L;
            for (int k = m; k >= 0; k--) {
                final long add = diff / pow3[k];
                extra += add;
                diff -= add * pow3[k];
            }

            if (diff == 0) {
                final long baseSec = m == 0 ? 1L : 2L * m;
                final long total = baseSec + extra;
                if (total < best) {
                    best = total;
                }
            }
        }

        return best;
    }
}