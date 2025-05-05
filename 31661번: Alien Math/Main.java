import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner(System.in);

        int B = fs.nextInt();
        Map<String, Integer> digitMap = new HashMap<>(B * 2);

        for (int i = 0; i < B; ++i) {
            digitMap.put(fs.next(), i);
        }

        String X = fs.next();
        long value = 0L;
        StringBuilder token = new StringBuilder(10);

        for (int idx = 0; idx < X.length(); ++idx) {
            token.append(X.charAt(idx));

            Integer digitVal = digitMap.get(token.toString());
            if (digitVal != null) {
                value = value * B + digitVal;
                token.setLength(0);
            }
        }

        if (token.length() != 0) {
            throw new IllegalStateException("Unparsed trailing characters!");
        }

        System.out.println(value);
    }

    private static class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int bId = 0, size = 0;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int readByte() throws IOException {
            if (bId >= size) {
                size = in.read(buffer);
                bId = 0;
                if (size == -1)
                    return -1;
            }
            return buffer[bId++];
        }

        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            int c;
            while ((c = readByte()) != -1 && c <= 32)
                ;

            for (; c != -1 && c > 32; c = readByte()) {
                sb.append((char) c);
            }

            return sb.toString();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}