import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 1 << 20);

        String[] sp = br.readLine().split(" ");
        int n = Integer.parseInt(sp[0]);
        sp = br.readLine().split(" ");
        int x = Integer.parseInt(sp[0]);
        int y = Integer.parseInt(sp[1]);
        sp = br.readLine().split(" ");

        long a = Long.parseLong(sp[0]);
        long b = Long.parseLong(sp[1]);
        long c = Long.parseLong(sp[2]);
        long d = Long.parseLong(sp[3]);

        int[] t = new int[n];
        t[0] = x;
        t[1] = y;
        long total = x + (long) y;
        for (int i = 2; i < n; i++) {
            long val = (a * t[i - 2] + b * t[i - 1] + c) % d;
            t[i] = (int) val;
            total += val;
        }

        long S = total;
        int bestLen = n + 1, bestL = 0, bestR = n - 1;
        long sum = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {
            sum += t[r];
            while (l <= r && sum * 2 >= S) {
                int len = r - l + 1;
                if (len < bestLen) {
                    bestLen = len;
                    bestL = l;
                    bestR = r;
                }

                sum -= t[l++];
            }
        }

        System.out.printf("%d %d%n", bestL + 1, bestR + 1);
    }
}