import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main
{
    private static long gcdLong(long a, long b) {
        while (b != 0) {
            long tmp = a % b;
            a = b;
            b = tmp;
        }
        
        return a;
    }
    
    private static class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int len = 0, ptr = 0;
        private final InputStream in;
        
        FastScanner(InputStream in) { this.in = in; }
        
        private int readByte() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }
        
        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            int c;
            while ((c = readByte()) != -1 && c <= ' ') ;
            if (c == -1) return null;
            
            do {
                sb.append((char) c);
            } while ((c = readByte()) != -1 && c > ' ');
            
            return sb.toString();
        }
        
        int nextInt() throws IOException { return Integer.parseInt(next()); }
        long nextLong() throws IOException { return Long.parseLong(next()); }
    }
    
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        
        int N = Integer.parseInt(fs.next());
        long[] a = new long[N];
        for (int i = 0; i < N; i++) a[i] = fs.nextLong();
        
        int M = Integer.parseInt(fs.next());
        long[] b = new long[M];
        for (int i = 0; i < M; i++) b[i] = fs.nextLong();
        
        BigInteger gcd = BigInteger.ONE;
        
        for (int i = 0; i < N; i++) {
            long ai = a[i];
            if (ai == 1) continue;
            
            for (int j = 0; j < M && ai != 1; j++) {
                long bj = b[j];
                if (bj == 1) continue;
                
                long g = gcdLong(ai, bj);
                if (g > 1) {
                    ai /= g;
                    bj /= g;
                    a[i] = ai;
                    b[j] = bj;
                    gcd = gcd.multiply(BigInteger.valueOf(g));
                }
            }
        }
        
        String s = gcd.toString();
        if (s.length() > 9) {
            System.out.println(s.substring(s.length() - 9));
        } else {
            System.out.println(s);
        }
    }
}