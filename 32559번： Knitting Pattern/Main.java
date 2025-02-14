import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long P = sc.nextLong();
        long remaining = N - P;
        long pairs = remaining / (2 * P);
        long empty = remaining - pairs * 2 * P;

        if (empty == P) {
            empty = 0;
        }

        System.out.println(empty);
    }
}