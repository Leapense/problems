import java.io.BufferedInputStream;
import java.io.IOException;

public class Main {

    // ---------- fast scanner ----------
    private static final class FastScanner {
        private final byte[] buf = new byte[1 << 16];
        private int len = 0, ptr = 0;
        private final BufferedInputStream in;

        FastScanner() {
            in = new BufferedInputStream(System.in);
        }

        private int readByte() throws IOException {
            if (ptr >= len) {
                len = in.read(buf);
                ptr = 0;
                if (len <= 0)
                    return -1;
            }
            return buf[ptr++];
        }

        int nextInt() throws IOException {
            int c, sign = 1, val = 0;
            do
                c = readByte();
            while (c <= ' ');
            if (c == '-') {
                sign = -1;
                c = readByte();
            }
            for (; c > ' '; c = readByte())
                val = (val << 3) + (val << 1) + (c & 15); // val*10 + digit
            return val * sign;
        }
    }

    // ---------- main ----------
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();

        fs.nextInt(); // BPM (사용하지 않음)
        final int X = fs.nextInt();
        final int N = fs.nextInt();

        final byte[][] g = new byte[N][9];
        for (int i = 0; i < N; ++i)
            for (int c = 0; c < 9; ++c)
                g[i][c] = (byte) fs.nextInt();

        long score = 0;
        final int unit = X; // 행 길이의 분자 (분모는 고정 6)

        for (int col = 0; col < 9; ++col) {
            int r = 0;
            while (r < N) {
                byte v = g[r][col];
                if (v == 0) {
                    ++r;
                    continue;
                }

                if (v == 1) { // run of 1's
                    int start = r;
                    while (r < N && g[r][col] == 1)
                        ++r;
                    if (r < N && g[r][col] == 2) { // (3) 끝만 보이는 롱노트
                        int end = r;
                        long L = (long) (end - start + 1);
                        score += (L * unit) / 6;
                        ++r; // 2까지 소비
                    } else { // 일반 노트 run
                        score += 100L * (r - start);
                    }
                } else { // v == 2 (시작)
                    int start = r;
                    ++r;
                    while (r < N && g[r][col] == 1)
                        ++r;
                    if (r < N && g[r][col] == 2) { // (1) 완전 표시
                        int end = r;
                        long L = (long) (end - start + 1);
                        score += 80 + (L * unit) / 6;
                        ++r;
                    } else { // (2) 시작만 표시
                        long L = (long) (N - start);
                        score += 80 + (L * unit) / 6;
                        break; // 열의 끝까지 스캔 완료
                    }
                }
            }
        }
        System.out.println(score);
    }
}
