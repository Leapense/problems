import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int n = Integer.parseInt(br.readLine().trim());
        int e = n + 2;

        List<Integer> divN = new ArrayList<>();
        for (int i = 1; i * (long)i <= n; i++) {
            if (n % i == 0) {
                divN.add(i);
                if (i != n / i) {
                    divN.add(n / i);
                }
            }
        }

        List<Integer> divE = new ArrayList<>();
        for (int i = 1; i * (long)i <= e; i++) {
            if (e % i == 0) {
                divE.add(i);
                if (i != e / i) {
                    divE.add(e / i);
                }
            }
        }

        for (int a : divN) {
            int c = n / a;
            for (int k : divE) {
                int[] bs = {k, -k};
                int[] ds = {-e / k, e / k};

                for (int idx = 0; idx < 2; idx++) {
                    int b = bs[idx];
                    int d = ds[idx];

                    if ((long)a * d + (long)b * c == n + 1L) {
                        pw.printf("%d %d %d %d\n", a, b, c, d);
                        pw.flush();
                        return;
                    }
                }
            }
        }

        pw.println(-1);
        pw.flush();
    }
}
