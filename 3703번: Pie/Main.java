import java.io.*;
import java.util.*;

public class Main
{
    private static final double PI = Math.PI;

    public static void main(String[] args) throws Exception
    {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();
        int tests = fs.nextInt();

        while (tests-- > 0)
        {
            int N = fs.nextInt();
            int F = fs.nextInt();
            int people = F + 1;

            double[] areas = new double[N];
            double hi = 0;

            for (int i = 0; i < N; i++)
            {
                int r = fs.nextInt();
                areas[i] = PI * r * r;
                if (areas[i] > hi) hi = areas[i];
            }

            double lo = 0, mid = 0;

            for (int it = 0; it < 60; it++)
            {
                mid = (lo + hi) * 0.5;
                if (canCut(areas, mid, people)) lo = mid;
                else hi = mid;
            }
            out.append(String.format(Locale.US, "%.4f%n", lo));
        }

        System.out.println(out.toString());
    }

    private static boolean canCut(double[] areas, double vol, int need)
    {
        if (vol == 0) return true;
        int cnt = 0;
        for (double a : areas)
        {
            cnt += (int)(a / vol);
            if (cnt >= need) return true;
        }

        return false;
    }

    private static class FastScanner
    {
        private final byte[] buffer = new byte[1 << 16];
        private int bId = 0, size = 0;
        private final InputStream in;
        FastScanner(InputStream in) { this.in = in; }
        private byte read() throws IOException
        {
            if (bId == size)
            {
                size = in.read(buffer);
                bId = 0;
                if (size == -1) return -1;
            }
            return buffer[bId++];
        }

        int nextInt() throws IOException
        {
            int c, sign = 1, res = 0;
            do c = read(); while (c <= ' ');
            if (c == '-') { sign = -1; c = read(); }
            for (; c > ' '; c = read()) res = res * 10 + (c - '0');
            return res * sign;
        }
    }
}