import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        sc.close();

        long leftCount = 0, rightCount = 0;

        while (!(A == 1 && B == 1)) {
            if (A > B) {
                long quotient = (A - 1) / B;
                leftCount += quotient;
                A -= quotient * B;
            } else {
                long quotient = (B - 1) / A;
                rightCount += quotient;
                B -= quotient * A;
            }
        }

        System.out.println(leftCount + " " + rightCount);
    }
}