import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        int k = 2 * N - 2;
        BigInteger result = fib(k);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(result.toString());
        bw.newLine();
        bw.flush();
    }

    static BigInteger fib(int n) {
        return fibPair(n)[0];
    }

    static BigInteger[] fibPair(int n) {
        if (n == 0) {
            return new BigInteger[] { BigInteger.ZERO, BigInteger.ONE };
        }
        BigInteger[] half = fibPair(n >>> 1);
        BigInteger a = half[0];
        BigInteger b = half[1];

        BigInteger twoBminusA = b.shiftLeft(1).subtract(a);
        BigInteger c = a.multiply(twoBminusA);
        BigInteger d = a.multiply(a).add(b.multiply(b));

        if ((n & 1) == 0) {
            return new BigInteger[] { c, d };
        } else {
            return new BigInteger[] { d, c.add(d) };
        }
    }
}