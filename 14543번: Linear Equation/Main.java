import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Scanner;

public final class Main
{
    private Main() {

    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            int p = Integer.parseInt(reader.readLine());
            for (int i = 1; i <= p; i++) {
                String equation = reader.readLine();
                solveAndPrint(equation, i);
            }
        }
    }

    private static void solveAndPrint(String equationStr, int caseNumber) {
        String parsableString = equationStr.replaceAll("[x+=]", " ");
        long coefficientA;
        long constantB;
        long resultC;

        try (Scanner scanner = new Scanner(parsableString)) {
            coefficientA = scanner.nextLong();
            constantB = scanner.nextLong();
            resultC = scanner.nextLong();
        }

        System.out.println("Equation " + caseNumber);

        if (coefficientA != 0) {
            double solution = (double)(resultC - constantB) / coefficientA;
            double truncatedSolution = Math.floor(solution * 1_000_000) / 1_000_000.0;
            System.out.printf("x = %.6f%n", truncatedSolution);
        } else {
            if (constantB == resultC) {
                System.out.println("More than one solution.");
            } else {
                System.out.println("No solution.");
            }
        }

        System.out.println();
    }
}