import java.util.Scanner;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Locale;

public class Main
{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int P = Integer.parseInt(scanner.nextLine());
        for (int i = 1; i <= P; i++) {
            String equationLine = scanner.nextLine();
            System.out.println("Equation " + i);

            String[] parts = equationLine.split(" ");
            long a = Long.parseLong(parts[0].replace("x", ""));
            long b = Long.parseLong(parts[2]);
            long c = Long.parseLong(parts[4]);
            long rightHandSide = c - b;
            if (a == 0) {
                if (rightHandSide == 0) {
                    System.out.println("More than one solution.");
                } else {
                    System.out.println("No solution.");
                }
            } else {
                double solution = (double) rightHandSide / a;
                long temp = (long) (solution * 1_000_000);
                double truncatedSolution = (double) temp / 1_000_000;

                DecimalFormat df = new DecimalFormat("0.000000");
                System.out.println("x = " + df.format(truncatedSolution));
            }
            if (i < P) {
                System.out.println();
            }
        }

        scanner.close();
    }
}