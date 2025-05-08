import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder sb = new StringBuilder();
        int t = fs.nextInt();

        while (t-- > 0) {
            int n = fs.nextInt();
            int l = fs.nextInt() - 1;
            int r = fs.nextInt() - 1;

            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = fs.nextLong();

            long segSum = 0;
            for (int i = l; i <= r; i++)
                segSum += a[i];

            long[] left = Arrays.copyOfRange(a, 0, l);
            long[] mid = Arrays.copyOfRange(a, l, r + 1);
            long[] right = Arrays.copyOfRange(a, r + 1, n);

            Arrays.sort(left);
            Arrays.sort(right);
            Arrays.sort(mid);

            long gainLeft = calcGain(left, mid);
            long gainRight = calcGain(right, mid);
            long ans = segSum - Math.max(gainLeft, gainRight);
            sb.append(ans).append('\n');
        }

        System.out.print(sb.toString());
    }

    static long calcGain(long[] outsideAsc, long[] insideAsc) {
        int i = 0, j = insideAsc.length - 1;
        long gain = 0;
        while (i < outsideAsc.length && j >= 0) {
            long diff = insideAsc[j] - outsideAsc[i];
            if (diff > 0) {
                gain += diff;
                i++;
                j--;
            } else
                break;
        }

        return gain;
    }

    static class FastScanner {
        byte[] buffer = new byte[1 << 16];
        int ptr, len;
        InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        int readByte() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0)
                    return -1;
            }

            return buffer[ptr++];
        }

        long nextLong() throws IOException {
            int c;
            while ((c = readByte()) <= ' ')
                ;
            boolean neg = c == '-';
            if (neg)
                c = readByte();
            long val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = readByte();
            }
            return neg ? -val : val;
        }

        int nextInt() throws IOException {
            return (int) nextLong();
        }
    }
}