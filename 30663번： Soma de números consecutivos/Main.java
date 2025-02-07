import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int n = sc.nextInt();
            if (n == 0)
                break;

            if ((n & (n - 1)) == 0)
                System.out.println("NAO");
            else
                System.out.println("SIM");
        }

        sc.close();
    }
}