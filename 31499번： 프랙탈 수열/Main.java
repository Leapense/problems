import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        long result = 1;

        for (int i = 1; i <= N; i++) {
            result = (result * i) % M;
        }

        System.out.println(result);
        sc.close();
    }
}