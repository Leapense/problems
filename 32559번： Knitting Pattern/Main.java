import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long P = sc.nextLong();
        sc.close();

        long k = (N / P - 1) / 2;
        long used = P * (1 + 2 * k);
        long R = N - used;

        if ((N % 2 == 0) && (P % 2 == 0) && (R >= P)) {
            R -= P;
        }

        System.out.println(R);
    }
}