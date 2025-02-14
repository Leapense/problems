import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x_s = sc.nextInt();
        int y_s = sc.nextInt();
        int x_t = sc.nextInt();
        int y_t = sc.nextInt();
        int x_p = sc.nextInt();
        int y_p = sc.nextInt();

        int safeY = 20001;

        System.out.println(2);
        System.out.println(x_s + " " + safeY);
        System.out.println(x_t + " " + safeY);

        sc.close();
    }
}