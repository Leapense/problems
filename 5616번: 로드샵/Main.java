import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    static BigInteger comb(int N, int K) {
        if (K < 0 || K > N)
            return BigInteger.ZERO;
        if (K == 0 || K == N)
            return BigInteger.ONE;
        if (K > N - K)
            K = N - K;

        BigInteger result = BigInteger.ONE;
        for (int i = 1; i <= K; i++) {
            BigInteger num = BigInteger.valueOf(N - K + i);
            BigInteger den = BigInteger.valueOf(i);
            BigInteger g = num.gcd(den);
            num = num.divide(g);
            den = den.divide(g);

            result = result.multiply(num).divide(den);
        }

        return result;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        long minNeeded = 1L * n * m;
        if (r < minNeeded) {
            System.out.println(0);
            return;
        }

        int N = (r - (n * m)) + n - 1;
        int K = n - 1;

        System.out.println(comb(N, K));
    }
}