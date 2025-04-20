import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int N = fs.nextInt(); // 총 층수 (사용하지 않지만 읽어야 함)
        int S = fs.nextInt(); // 기숙사 층 "
        for (int i = 0; i < N; i++)
            fs.nextInt(); // 가속기 정보 버퍼링

        String cmd = fs.next(); // 출근 커맨드
        StringBuilder sb = new StringBuilder(cmd);
        sb.reverse(); // 뒤집으면 곧 퇴근 커맨드

        System.out.println(sb.toString());
    }

    /** 빠른 입력용 최소 구현 */
    private static class FastScanner {
        private final byte[] buf = new byte[1 << 16];
        private int idx, len;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int read() throws IOException {
            if (idx >= len) {
                len = in.read(buf);
                idx = 0;
            }
            return len == -1 ? -1 : buf[idx++];
        }

        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            int c;
            while ((c = read()) <= ' ' && c != -1)
                ;
            for (; c > ' '; c = read())
                sb.append((char) c);
            return sb.toString();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}
