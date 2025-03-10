import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        for (int t = 1; t <= T; t++) {
            String fraction = sc.nextLine().trim();
            String[] parts = fraction.split("/");
            BigInteger P = new BigInteger(parts[0]);
            BigInteger Q = new BigInteger(parts[1]);
            BigInteger gcd = P.gcd(Q);
            P = P.divide(gcd);
            Q = Q.divide(gcd);
            if (!isPowerOfTwo(Q)) {
                System.out.println("Case #" + t + ": impossible");
                continue;
            }

            int ans = 41;
            for (int k = 1; k <= 40; k++) {
                BigInteger denom = BigInteger.valueOf(2).pow(k);
                if (P.multiply(denom).compareTo(Q) >= 0) {
                    ans = k;
                    break;
                }
            }

            if (ans > 40) {
                System.out.println("Case #" + t + ": impossible");
            } else {
                System.out.println("Case #" + t + ": " + ans);
            }
        }
        sc.close();
    }

    private static boolean isPowerOfTwo(BigInteger n) {
        return n.compareTo(BigInteger.ZERO) > 0 && n.and(n.subtract(BigInteger.ONE)).equals(BigInteger.ZERO);
    }
}