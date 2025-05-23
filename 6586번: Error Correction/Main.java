import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder output = new StringBuilder();

        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) {
                break;
            }

            int[][] matrix = new int[n][n];
            int[] rowSums = new int[n];
            int[] colSums = new int[n];

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = Integer.parseInt(st.nextToken());
                    rowSums[i] += matrix[i][j];
                    colSums[j] += matrix[i][j];
                }
            }

            int oddRowCount = 0;
            int oddColCount = 0;
            int oddRowIndex = -1;
            int oddColIndex = -1;

            for (int i = 0; i < n; i++) {
                if (rowSums[i] % 2 == 1) {
                    oddRowCount++;
                    oddRowIndex = i;
                }
                if (colSums[i] % 2 == 1) {
                    oddColCount++;
                    oddColIndex = i;
                }
            }

            if (oddRowCount == 0 && oddColCount == 0) {
                output.append("OK\n");
            } else if (oddRowCount == 1 && oddColCount == 1) {
                output.append("Change bit (")
                        .append(oddRowIndex + 1)
                        .append(",")
                        .append(oddColIndex + 1)
                        .append(")\n");
            } else {
                output.append("Corrupt\n");
            }
        }

        System.out.print(output);
    }
}