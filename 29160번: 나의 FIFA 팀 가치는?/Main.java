import java.io.*;

public class Main {
    static class FastReader {
        private final InputStream in;
        private final byte[] buf = new byte[1 << 20];
        private int idx, size;

        FastReader(InputStream in) {
            this.in = in;
        }

        private int read() throws IOException {
            if (size == idx) {
                size = in.read(buf);
                idx = 0;
                if (size < 0)
                    return -1;
            }
            return buf[idx++];
        }

        int nextInt() throws IOException {
            int c, sign = 1;
            for (c = read(); c != -1 && c <= ' '; c = read())
                ;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            int x = 0;
            for (; c >= '0' && c <= '9'; c = read()) {
                x = x * 10 + (c - '0');
            }

            return x * sign;
        }
    }

    public static void main(String... args) throws IOException {
        FastReader fr = new FastReader(System.in);
        int N = fr.nextInt(), K = fr.nextInt();
        final int MAXW = 100_000;

        int[][] cnt = new int[12][MAXW + 1];
        for (int i = 0; i < N; i++) {
            int p = fr.nextInt();
            int w = fr.nextInt();
            cnt[p][w]++;
        }

        int[] maxv = new int[12];
        for (int p = 1; p <= 11; p++) {
            int v = MAXW;
            while (v >= 0 && cnt[p][v] == 0)
                v--;
            maxv[p] = v;
        }

        for (int year = 0; year < K; year++) {
            for (int p = 1; p <= 11; p++) {
                int v = maxv[p];
                if (v < 0)
                    continue;
                cnt[p][v]--;
                int nv = (v > 0 ? v - 1 : 0);
                cnt[p][nv]++;
                if (cnt[p][v] == 0) {
                    int vv = v - 1;
                    while (vv >= 0 && cnt[p][vv] == 0)
                        vv--;
                    maxv[p] = vv;
                }
            }
        }

        long answer = 0;
        for (int p = 1; p <= 11; p++) {
            if (maxv[p] > 0)
                answer += maxv[p];
        }

        System.out.println(answer);
    }
}
