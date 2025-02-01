import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger N = sc.nextBigInteger();

        long months = 1;
        BigInteger current = N;

        while (true) {
            int len = current.toString().length();
            BigInteger ten = BigInteger.TEN;
            BigInteger lower = ten.pow(len - 1);
            BigInteger upper = ten.pow(len);
            BigInteger repunitL = ten.pow(len).subtract(BigInteger.ONE).divide(BigInteger.valueOf(9));
            BigInteger candidate1 = current.subtract(repunitL);
            if (candidate1.compareTo(lower) >= 0 && candidate1.compareTo(upper) < 0) {
                current = candidate1;
                months++;
                continue;
            }
            if (len > 1) {
                BigInteger lower2 = ten.pow(len - 2);
                BigInteger upper2 = ten.pow(len - 1);
                BigInteger repunitL_1 = ten.pow(len - 1).subtract(BigInteger.ONE).divide(BigInteger.valueOf(9));
                BigInteger candidate2 = current.subtract(repunitL_1);
                if (candidate2.compareTo(lower2) >= 0 && candidate2.compareTo(upper2) < 0) {
                    current = candidate2;
                    months++;
                    continue;
                }
            }

            break;
        }

        System.out.println(months);
    }
}