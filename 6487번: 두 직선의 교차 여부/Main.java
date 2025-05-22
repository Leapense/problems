import java.util.Locale;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int T = scanner.nextInt();
            StringBuilder output = new StringBuilder();

            for (int tc = 0; tc < T; tc++) {
                double x1 = scanner.nextDouble();
                double y1 = scanner.nextDouble();
                double x2 = scanner.nextDouble();
                double y2 = scanner.nextDouble();
                double x3 = scanner.nextDouble();
                double y3 = scanner.nextDouble();
                double x4 = scanner.nextDouble();
                double y4 = scanner.nextDouble();

                double dx1 = x2 - x1;
                double dy1 = y2 - y1;
                double dx2 = x4 - x3;
                double dy2 = y4 - y3;

                double denom = determinant(dx1, dy1, dx2, dy2);

                if (isZero(denom)) {
                    if (isZero(determinant(dx1, dy1, x3 - x1, y3 - y1))) {
                        output.append("LINE\n");
                    } else {
                        output.append("NONE\n");
                    }
                } else {
                    double det1 = determinant(x1, y1, x2, y2);
                    double det2 = determinant(x3, y3, x4, y4);

                    double x = determinant(det2, dx2, det1, dx1) / denom;
                    double y = determinant(det2, dy2, det1, dy1) / denom;

                    output.append(String.format("POINT %.2f %.2f%n", x, y));
                }
            }

            System.out.print(output);
        }
    }

    private static double determinant(double ax, double ay, double bx, double by) {
        return ax * by - ay * bx;
    }

    private static boolean isZero(double v) {
        return Math.abs(v) < 1e-10;
    }
}