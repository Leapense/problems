import java.util.Scanner;
import java.text.DecimalFormat;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double p = sc.nextDouble();
        double q = sc.nextDouble();
        double r = sc.nextDouble();

        if (Math.abs(p - r) > 1e-9) {
            System.out.println("0");
        } else {
            double area = 2 * p * (p + q);
            DecimalFormat df = new DecimalFormat("0.0000");
            System.out.println(df.format(area));
        }
        sc.close();
    }
}