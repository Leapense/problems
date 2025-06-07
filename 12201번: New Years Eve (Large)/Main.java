import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.text.DecimalFormat;

public final class Main {
    private static final double GLASS_CAPACITY = 250.0;
    private static final double BOTTLE_VOLUME = 750.0;
    private static final DecimalFormat FORMAT = new DecimalFormat("0.0000000");

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            int T = Integer.parseInt(reader.readLine().trim());
            StringBuilder output = new StringBuilder();
            for (int caseNum = 1; caseNum <= T; caseNum++) {
                String[] parts = reader.readLine().trim().split("\\s+");
                int B = Integer.parseInt(parts[0]);
                int targetLevel = Integer.parseInt(parts[1]);
                int targetIndex = Integer.parseInt(parts[2]);

                double answer = simulatePour(B, targetLevel, targetIndex);
                output.append("Case #").append(caseNum).append(": ").append(FORMAT.format(answer)).append('\n');
            }

            System.out.print(output.toString());
        }
    }

    private static double simulatePour(int B, int level, int index) {
        double[][][] volume = new double[level + 2][][];
        for (int l = 1; l <= level + 1; l++) {
            volume[l] = new double[l + 2][l + 2];
        }

        volume[1][1][1] = BOTTLE_VOLUME * B;
        for (int l = 1; l < level; l++) {
            for (int i = 1; i <= l; i++) {
                for (int j = 1; j <= i; j++) {
                    double amt = volume[l][i][j];
                    if (amt > GLASS_CAPACITY) {
                        double excess = (amt - GLASS_CAPACITY) / 3.0;
                        volume[l][i][j] = GLASS_CAPACITY;
                        volume[l + 1][i][j] += excess;
                        volume[l + 1][i + 1][j] += excess;
                        volume[l + 1][i + 1][j + 1] += excess;
                    }
                }
            }
        }

        int row = 1;
        while (row * (row + 1) / 2 < index) {
            row++;
        }

        int prevSum = row * (row - 1) / 2;
        int col = index - prevSum;

        double result = volume[level][row][col];
        return result > GLASS_CAPACITY ? GLASS_CAPACITY : result;
    }
}