import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    private static final BigInteger TWO = BigInteger.valueOf(2);
    private static final BigInteger SIX = BigInteger.valueOf(6);

    static class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int bIdx, size;
        private final InputStream in;
        FastScanner (InputStream in) { this.in = in; }

        private int readByte() throws IOException {
            if (bIdx >= size) {
                size = in.read(buffer);
                bIdx = 0;
                if (size == -1) return -1;
            }

            return buffer[bIdx++];
        }

        long nextLong() throws IOException {
            int c, sign = 1;
            while ((c = readByte()) <= ' ') ;
            if (c == '-') { sign = -1; c = readByte(); }
            long val = 0;
            while (c > ' ') { val = val * 10 + (c - '0'); c = readByte(); }
            return val * sign;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();
        int t = (int) fs.nextLong();

        for (int i = 0; i < t; i++) {
            long n = fs.nextLong();
            long m = fs.nextLong();

            long lMin = Math.min(n, m);
            BigInteger L = BigInteger.valueOf(lMin);
            BigInteger bigN = BigInteger.valueOf(n);
            BigInteger bigM = BigInteger.valueOf(m);

            BigInteger term1 = L.multiply(bigN).multiply(bigM);
            BigInteger term2 = bigN.add(bigM)
                                   .multiply(L)
                                   .multiply(L.subtract(BigInteger.ONE))
                                   .divide(TWO);
            BigInteger term3 = L.subtract(BigInteger.ONE)
                                .multiply(L)
                                .multiply(L.multiply(TWO).subtract(BigInteger.ONE))
                                .divide(SIX);
            BigInteger answer = term1.subtract(term2).add(term3);
            out.append(answer).append('\n');
        }
        System.out.print(out);
    }
}
