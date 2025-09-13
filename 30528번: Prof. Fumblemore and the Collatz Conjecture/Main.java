import java.io.*;
import java.math.BigInteger;

public class Main {
    static boolean isValid(String s) {
        if (s == null || s.isEmpty()) return false;
        if (s.charAt(s.length() - 1) != 'O') return false;
        char prev = '\0';
        for (int i = 0 ; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c != 'E' && c != 'O') return false;
            if (c == 'O' && prev == 'O') return false;
            prev = c;
        }
        return true;
    }

    static BigInteger solve(String pat) {
        final BigInteger ONE = BigInteger.ONE;
        final BigInteger TWO = BigInteger.valueOf(2);
        final BigInteger THREE = BigInteger.valueOf(3);

        for (int t = 2; t <= 10000; t += 2) {
            BigInteger x = ONE.shiftLeft(t);
            boolean ok = true;
            for (int i = pat.length() - 1; i >= 0; i--) {
                char ch = pat.charAt(i);
                if (ch == 'O') {
                    BigInteger xm1 = x.subtract(ONE);
                    if (!xm1.mod(THREE).equals(BigInteger.ZERO)) { ok = false; break; }
                    x = xm1.divide(THREE);
                    if (x.signum() <= 0) { ok = false; break; }
                    if (x.and(ONE).equals(BigInteger.ZERO)) { ok = false; break; }
                    if (x.equals(ONE)) { ok = false; break; }
                } else {
                    x = x.shiftLeft(1);
                }
            }
            if (ok) return x;
        }
        return null;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        if (s != null) s = s.trim();
        if (!isValid(s)) {
            System.out.println("INVALID");
            return;
        }
        BigInteger ans = solve(s);
        if (ans == null) System.out.println("INVALID");
        else System.out.println(ans.toString());
    }
}