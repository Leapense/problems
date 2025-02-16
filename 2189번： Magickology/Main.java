import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int squareCount = 1;

        while (true) {
            int n = sc.nextInt();
            if (n == 0)
                break;

            int[][] square = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    square[i][j] = sc.nextInt();
                }
            }

            String result = classifySquare(square, n);
            System.out.println("Square " + squareCount + ": " + result);
            squareCount++;
        }
        sc.close();
    }

    private static String classifySquare(int[][] square, int n) {
        int S = 0;
        for (int i = 0; i < n; i++) {
            S += square[i][0];
        }

        for (int i = 0; i < n; i++) {
            int rowSum = 0;
            int colSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += square[i][j];
                colSum += square[j][i];
            }

            if (rowSum != S || colSum != S) {
                return "Not a Magick Square";
            }
        }

        int primaryDiag = 0;
        int secondaryDiag = 0;
        for (int i = 0; i < n; i++) {
            primaryDiag += square[i][i];
            secondaryDiag += square[i][n - 1 - i];
        }

        if (primaryDiag != S || secondaryDiag != S) {
            return "Semi-Magick Square";
        }

        Set<Integer> numbers = new HashSet<>();
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int value = square[i][j];
                if (numbers.contains(value)) {
                    return "Weakly-Magick Square";
                }

                numbers.add(value);
                if (value < min)
                    min = value;
                if (value > max)
                    max = value;
            }
        }

        if (max - min == n * n - 1) {
            return "Magically-Magick Square";
        } else {
            return "Strongly-Magick Square";
        }
    }
}