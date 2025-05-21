import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        try (
                BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
                BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));) {
            StringTokenizer headerTokens = new StringTokenizer(reader.readLine());
            final int numberOfMerlons = Integer.parseInt(headerTokens.nextToken());
            final long unitRaiseCost = Long.parseLong(headerTokens.nextToken());
            final long unitLowerCost = Long.parseLong(headerTokens.nextToken());

            int[] currentHeights = new int[numberOfMerlons];
            int[] targetHeights = new int[numberOfMerlons];

            for (int i = 0; i < numberOfMerlons; i++) {
                StringTokenizer lineTokens = new StringTokenizer(reader.readLine());
                currentHeights[i] = Integer.parseInt(lineTokens.nextToken());
                targetHeights[i] = Integer.parseInt(lineTokens.nextToken());
            }

            Arrays.sort(currentHeights);
            Arrays.sort(targetHeights);

            long totalCost = 0L;
            for (int i = 0; i < numberOfMerlons; i++) {
                int source = currentHeights[i];
                int goal = targetHeights[i];

                if (goal >= source) {
                    totalCost += (long) (goal - source) * unitRaiseCost;
                } else {
                    totalCost += (long) (source - goal) * unitLowerCost;
                }
            }

            writer.write(Long.toString(totalCost));
            writer.newLine();
            writer.flush();
        } catch (IOException ioEx) {
            throw new RuntimeException("I/O error during execution", ioEx);
        }
    }
}