import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String number = sc.next();
        int k = sc.nextInt();
        String[] parts = number.split("\\.");
        String A_str = parts[0];
        String D_str = parts[1];
        int total_decimal = D_str.length();
        int n = total_decimal - k;
        String B_str = n > 0 ? D_str.substring(0, n) : "0";
        String C_str = D_str.substring(total_decimal - k);
        BigInteger A = new BigInteger(A_str);
        BigInteger B = new BigInteger(B_str);
        BigInteger C = new BigInteger(C_str);
        BigInteger ten = BigInteger.TEN;
        BigInteger ten_n = ten.pow(n);
        BigInteger ten_k = ten.pow(k);
        BigInteger ten_nk = ten.pow(n + k);
        BigInteger D = ten_nk.subtract(ten_n);
        BigInteger term1 = A.multiply(D);
        BigInteger term2 = B.multiply(ten_k.subtract(BigInteger.ONE));
        BigInteger N = term1.add(term2).add(C);
        BigInteger gcd = N.gcd(D);

        N = N.divide(gcd);
        D = D.divide(gcd);

        System.out.println(N + "/" + D);
    }
}