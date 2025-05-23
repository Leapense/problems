import java.util.Scanner;
import java.util.Locale;

public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextDouble()) {
            double x1 = sc.nextDouble(), y1 = sc.nextDouble();
            double x2 = sc.nextDouble(), y2 = sc.nextDouble();
            double x3 = sc.nextDouble(), y3 = sc.nextDouble();
            double a = Math.hypot(x1 - x2, y1 - y2);
            double b = Math.hypot(x2 - x3, y2 - y3);
            double c = Math.hypot(x3 - x1, y3 - y1);
            double area = Math.abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
            double R = (a * b * c) / (4.0 * area);
            double circumference = 2 * 3.141592653589793 * R;
            System.out.printf("%.2f\n", circumference);
        }

        sc.close();
    }
}