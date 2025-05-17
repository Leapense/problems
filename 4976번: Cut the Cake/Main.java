import java.io.*;
import java.util.*;

public class Main {
    private static final class Piece {
        int w, d; // 너비, 높이
        int birth; // 0: 기본, 1, 2, ...

        Piece(int w, int d, int birth) {
            this.w = w;
            this.d = d;
            this.birth = birth;
        }

        int area() {
            return w * d;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder(256);

        while (true) {
            int n = fs.nextInt();
            int w = fs.nextInt();
            int d = fs.nextInt();

            if (n == 0 && w == 0 && d == 0)
                break;

            List<Piece> pieces = new ArrayList<>(n + 1);
            pieces.add(new Piece(w, d, 0));

            for (int cutIdx = 1; cutIdx <= n; ++cutIdx) {
                int p = fs.nextInt();
                int s = fs.nextInt();

                Piece victim = pieces.remove(p - 1);
                Piece[] twins = cut(victim, s, cutIdx);

                if (twins[0].area() > twins[1].area()) {
                    Piece tmp = twins[0];
                    twins[0] = twins[1];
                    twins[1] = tmp;
                }

                pieces.add(twins[0]);
                pieces.add(twins[1]);
            }

            int m = pieces.size();
            int[] areas = new int[m];
            for (int i = 0; i < m; ++i)
                areas[i] = pieces.get(i).area();
            Arrays.sort(areas);

            for (int i = 0; i < m; ++i) {
                if (i > 0)
                    out.append(' ');
                out.append(areas[i]);
            }

            out.append('\n');
        }

        System.out.print(out.toString());
    }

    private static Piece[] cut(Piece p, int s, int birth) {
        int W = p.w, D = p.d;
        int perimeter = 2 * (W + D);
        int t = s % perimeter;
        if (t == 0)
            t = perimeter;

        if (t < W) {
            int x = t;
            return new Piece[] {
                    new Piece(x, D, birth),
                    new Piece(W - x, D, birth)
            };
        }

        if (t < W + D) {
            int y = t - W;
            return new Piece[] {
                    new Piece(W, y, birth),
                    new Piece(W, D - y, birth)
            };
        }

        if (t < W + D + W) {
            int x = t - (W + D);
            return new Piece[] {
                    new Piece(W - x, D, birth),
                    new Piece(x, D, birth)
            };
        }

        int y = t - (W + D + W);

        return new Piece[] {
                new Piece(W, D - y, birth),
                new Piece(W, y, birth)
        };
    }

    private static final class FastScanner {
        private final byte[] buf = new byte[1 << 16];
        private int len = 0, ptr = 0;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        int nextInt() throws IOException {
            int c, sgn = 1, val = 0;
            while ((c = read()) <= ' ')
                if (c == -1)
                    return 0;
            if (c == '-' || c == '+') {
                if (c == '-')
                    sgn = -1;
                c = read();
            }
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sgn;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buf);
                ptr = 0;
                if (len <= 0)
                    return -1;
            }

            return buf[ptr++];
        }
    }
}