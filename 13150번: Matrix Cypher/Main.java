import java.math.BigInteger;
import java.util.Scanner;

public final class Main
{
    private Main() {

    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            BigInteger a11 = scanner.nextBigInteger();
            BigInteger a12 = scanner.nextBigInteger();
            BigInteger a21 = scanner.nextBigInteger();
            BigInteger a22 = scanner.nextBigInteger();

            String decodedBitString = decode(a11, a12, a21, a22);
            System.out.println(decodedBitString);
        }
    }

    private static String decode(BigInteger a, BigInteger b, BigInteger c, BigInteger d) {
        StringBuilder reversedBitstring = new StringBuilder();
        final BigInteger one = BigInteger.ONE;
        final BigInteger zero = BigInteger.ZERO;

        while (!(a.equals(one) && b.equals(zero) && c.equals(zero))) {
            if (a.compareTo(b) >= 0 && c.compareTo(d) >= 0) {
                reversedBitstring.append('0');
                a = a.subtract(b);
                c = c.subtract(d);
            } else {
                reversedBitstring.append('1');
                b = b.subtract(a);
                d = d.subtract(c);
            }
        }
        return reversedBitstring.reverse().toString();
    }
}