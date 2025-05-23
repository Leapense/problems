import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        final long MOD = 1000000007;

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long A = Long.parseLong(st.nextToken());
            long B = Long.parseLong(st.nextToken());
            long N = Long.parseLong(st.nextToken());

            long result = 0;

            long r = N % 6;
            if (r < 0) {
                r += 6;
            }

            if (r == 1)
                result = A;
            else if (r == 2)
                result = B;
            else if (r == 3)
                result = B - A;
            else if (r == 4)
                result = -A;
            else if (r == 5)
                result = -B;
            else if (r == 0)
                result = A - B;

            result %= MOD;
            if (result < 0) {
                result += MOD;
            }

            System.out.println(result);
        }
    }
}