import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public final class Main
{
    private static final int FULL_CIRCLE_DEGREES = 360;
    private static final int DEGREE_TO_SECOND_NUMERATOR = 120;
    private static final int DEGREE_TO_SECOND_DENOMINATOR = 11;
    private static final int SECONDS_PER_HOUR = 3_600;
    private static final int TOTAL_HOURS = 12;
    private static final int DEGREES_PER_HOUR = 30;
    private static final int CYCLE_SECONDS = 12 * SECONDS_PER_HOUR;

    private Main() {

    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int testCount = Integer.parseInt(reader.readLine().trim());
        for (int caseIndex = 1; caseIndex <= testCount; caseIndex++) 
        {
            String line = reader.readLine().trim();
            String[] tokens = line.split("\\s+");
            int angle = Integer.parseInt(tokens[0]);
            String keyword = tokens[1];
            int bHour = Integer.parseInt(tokens[2]);

            long totalSeconds;
            if ("after".equals(keyword)) {
                totalSeconds = calculateAfterSeconds(angle, bHour);
            } else {
                totalSeconds = calculateTilSeconds(angle, bHour);
            }

            String formatted = formatAsTimeString(totalSeconds);
            System.out.printf("Case %d: %s%n", caseIndex, formatted);
        }
    }

    private static long calculateAfterSeconds(int angle, int baseHour) {
        int sum = angle + DEGREES_PER_HOUR * baseHour;
        int remainder = sum % FULL_CIRCLE_DEGREES;
        int effectiveDegrees = (remainder == 0) ? FULL_CIRCLE_DEGREES : remainder;
        double tExact = effectiveDegrees * (DEGREE_TO_SECOND_NUMERATOR / (double) DEGREE_TO_SECOND_DENOMINATOR);
        long tRounded = Math.round(tExact);
        long baseSeconds = (baseHour % 12) * SECONDS_PER_HOUR;
        long rawSeconds = baseSeconds + tRounded;
        return ((rawSeconds % CYCLE_SECONDS) + CYCLE_SECONDS) % CYCLE_SECONDS;
    }

    private static long calculateTilSeconds(int angle, int baseHour) {
        int sum = angle + DEGREES_PER_HOUR * baseHour;
        int remainder = sum % FULL_CIRCLE_DEGREES;

        int effectiveDegrees = (remainder == 0) ? -FULL_CIRCLE_DEGREES : (remainder - FULL_CIRCLE_DEGREES);

        double tExact = effectiveDegrees * (DEGREE_TO_SECOND_NUMERATOR / (double) DEGREE_TO_SECOND_DENOMINATOR);
        long tRounded = Math.round(tExact);

        long baseSeconds = (baseHour % 12) * SECONDS_PER_HOUR;
        long rawSeconds = baseSeconds + tRounded;

        return ((rawSeconds % CYCLE_SECONDS) + CYCLE_SECONDS) % CYCLE_SECONDS;
    }

    private static String formatAsTimeString(long totalSeconds) {
        int hourIndex = (int) (totalSeconds / SECONDS_PER_HOUR);
        int hour = (hourIndex == 0) ? 12 : hourIndex;
        int minute = (int)((totalSeconds % SECONDS_PER_HOUR) / 60);
        int second = (int)((totalSeconds % SECONDS_PER_HOUR) % 60);

        return String.format("%d:%02d:%02d", hour, minute, second);
    }

}