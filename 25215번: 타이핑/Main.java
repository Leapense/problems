import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static final int COST_TYPE = 1;
    private static final int COST_TOGGLE = 1;
    private static final int COST_STAR = 1;
    private static final int INF = 1_000_000_000;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String input = reader.readLine();
        if (input == null) {
            return;
        }
        int result = computeMinimumPresses(input);
        System.out.print(result);
    }

    private static int computeMinimumPresses(String s) {
        int[] current = new int[2];
        int[] next = new int[2];
        current[0] = 0;
        current[1] = COST_TOGGLE;

        for (int i = 0; i < s.length(); i++) {
            int targetCase = Character.isUpperCase(s.charAt(i)) ? 1 : 0;
            next[0] = INF;
            next[1] = INF;
            for (int mode = 0; mode <= 1; mode++) {
                int starNeeded = mode == targetCase ? 0 : COST_STAR;
                int typeCost = COST_TYPE + starNeeded;

                int stayModeCost = current[mode] + typeCost;
                if (stayModeCost < next[mode]) {
                    next[mode] = stayModeCost;
                }
                
                int toggleAfterCost = current[mode] + typeCost + COST_TOGGLE;
                int toggledMode = 1 - mode;
                if (toggleAfterCost < next[toggledMode]) {
                    next[toggledMode] = toggleAfterCost;
                }
            }
            int temp0 = current[0];
            int temp1 = current[1];
            current[0] = next[0];
            current[1] = next[1];
            next[0] = temp0;
            next[1] = temp1;
        }

        return Math.min(current[0], current[1]);
    }
}