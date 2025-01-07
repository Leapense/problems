import java.util.Scanner;

public class Main {
    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    public static String rationalRatio(String input) {
        String[] parts = input.split(" ");
        String decimalStr = parts[0];
        int repeatLen = Integer.parseInt(parts[1]);
    }
}