import java.io.*;
import java.util.*;

public class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream is) { br = new BufferedReader(new InputStreamReader(is)); }

        String next() throws IOException {
            while (st == null || !st.hasMoreElements()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException { return Integer.parseInt(next()); }
        long nextLong() throws IOException { return Long.parseLong(next()); }
        String nextLine() throws IOException { return br.readLine(); }
    }

    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner(System.in);
        int N = Integer.parseInt(fs.next());
        long[] p = new long[N];
        long sum = 0L;

        HashMap<Long, Integer> freq = new HashMap<>(1 << 20);

        for (int i = 0; i < N; i++) {
            p[i] = Long.parseLong(fs.next());
            sum += p[i];
            long key = p[i];
            freq.put(key, freq.getOrDefault(key, 0) + 1);
        }

        int Q = Integer.parseInt(fs.next());
        StringBuilder out = new StringBuilder();
        long offset = 0L;

        for (int qi = 0; qi < Q; qi++) {
            String s = fs.next();
            if (s.equals("INFLATION")) {
                long x = Long.parseLong(fs.next());
                offset += x;
                sum += (long) N * x;
                out.append(sum).append('\n');
            } else {
                long x = Long.parseLong(fs.next());
                long y = Long.parseLong(fs.next());

                long bx = x - offset;
                long by = y - offset;
                Integer cntObj = freq.get(bx);
                int cnt = (cntObj == null) ? 0 : cntObj;

                if (cnt != 0) {
                    if (cnt == 1) freq.remove(bx);
                    else freq.put(bx, cnt - 1);
                    freq.put(bx, 0);
                }

                if (cnt != 0) {
                    freq.remove(bx);
                    freq.put(by, freq.getOrDefault(by, 0) + cnt);
                    sum += (long) cnt * (y - x);
                }

                out.append(sum).append('\n');
            }
        }

        System.out.print(out.toString());
    }
}