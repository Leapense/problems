import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public final class Main
{
    private Main() {

    }

    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            final int testCaseCount = parseInteger(reader.readLine());
            for (int caseIndex = 1; caseIndex <= testCaseCount; caseIndex++) {
                final String inputLine = reader.readLine();
                final StringTokenizer tokenizer = new StringTokenizer(inputLine);
                final int destinationDistance = parseInteger(tokenizer.nextToken());
                final int maxRange = parseInteger(tokenizer.nextToken());
                final int stationCount = parseInteger(tokenizer.nextToken());

                final List<Integer> stationDistances = new ArrayList<>();
                for (int i = 0; i < stationCount; i++) {
                    stationDistances.add(parseInteger(tokenizer.nextToken()));
                }

                final List<Integer> refuelStops = computeRefuelPlan(destinationDistance, maxRange, stationDistances);

                if (refuelStops.isEmpty()) {
                    System.out.printf("Case #%d: out of petrol%n", caseIndex);
                } else {
                    System.out.printf("Case #%d:", caseIndex);
                    for (final Integer stop : refuelStops) {
                        System.out.print(" " + stop);
                    }

                    System.out.println();
                }
            }
        } catch (IOException exception) {
            System.err.println("입출력 예외가 발생했습니다: " + exception.getMessage());
        }
    }

    public static List<Integer> computeRefuelPlan(final int destinationDistance, final int maxRange, final List<Integer> stationDistances) {
        final List<Integer> extendedStations = new ArrayList<>(stationDistances);
        extendedStations.add(destinationDistance);

        final List<Integer> refuelStops = new ArrayList<>();

        int currentPosition = 0;
        int currentIndex = -1;

        while (true)
        {
            final int maxReachableDistance = currentPosition + maxRange;
            int nextIndex = currentIndex;

            for (int idx = currentIndex + 1; idx < extendedStations.size() && extendedStations.get(idx) <= maxReachableDistance; idx++) {
                nextIndex = idx;
            }

            if (nextIndex == currentIndex) {
                return new ArrayList<>();
            }

            currentIndex = nextIndex;
            currentPosition = extendedStations.get(nextIndex);

            if (currentPosition == destinationDistance) {
                break;
            }

            refuelStops.add(currentPosition);
        }

        return refuelStops;
    }

    private static int parseInteger(final String text)
    {
        return Integer.parseInt(text);
    }
}