import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] mealStartTimes = new int[3];
        int[] mealEndTimes = new int[3];

        st = new StringTokenizer(br.readLine());
        mealStartTimes[0] = Integer.parseInt(st.nextToken());
        mealEndTimes[0] = Integer.parseInt(st.nextToken());
        mealStartTimes[1] = Integer.parseInt(st.nextToken());
        mealEndTimes[1] = Integer.parseInt(st.nextToken());
        mealStartTimes[2] = Integer.parseInt(st.nextToken());
        mealEndTimes[2] = Integer.parseInt(st.nextToken());

        long currentEffectExpiryTime;

        long actualTakeTimeForFirstPill = (long) mealEndTimes[0];
        currentEffectExpiryTime = actualTakeTimeForFirstPill + k;

        for (int pillIndex = 1; pillIndex < 3 * n; pillIndex++) {
            int day = pillIndex / 3;
            int mealTypeIndex = pillIndex % 3;

            long currentPillMinAllowedTakeTime = (long) day * 1440 + mealStartTimes[mealTypeIndex];
            long currentPillMaxAllowedTakeTime = (long) day * 1440 + mealEndTimes[mealTypeIndex];

            long latestPossibleTakeTime = Math.min(currentPillMaxAllowedTakeTime, currentEffectExpiryTime);

            if (currentPillMinAllowedTakeTime > latestPossibleTakeTime) {
                System.out.println("NO");
                return;
            }

            long actualTakeTime = latestPossibleTakeTime;
            currentEffectExpiryTime = actualTakeTime + k;
        }

        System.out.println("YES");
    }
}