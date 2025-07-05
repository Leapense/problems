import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException {
        final int MAX = 100000;
        final int MOD = 1000000009;
        long[] C = new long[MAX + 1];
        C[0] = 1;
        for (int i = 1; i <= MAX; i++) {
            long sum = C[i - 1];
            if (i - 2 >= 0) sum = (sum + C[i - 2]) % MOD;
            if (i - 3 >= 0) sum = (sum + C[i - 3]) % MOD;
            C[i] = sum;
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            long ans = 0;
            if ((n & 1) == 0) {
                ans = (ans + C[n / 2]) % MOD;
            }
            for (int m = 1; m <= 3; m++) {
                int rem = n - m;
                if (rem >= 0 && (rem & 1) == 0) {
                    ans = (ans + C[rem / 2]) % MOD;
                }
            }
            bw.write(Long.toString(ans));
            bw.newLine();
        }
        bw.flush();
        bw.close();
    }
}