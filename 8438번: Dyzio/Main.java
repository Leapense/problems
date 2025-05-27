import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main
{
    private static String s;
    private static int idx;
    private static int maxDepth;
    private static int cutCount;

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(reader.readLine().trim());
            s = reader.readLine().trim();

            idx = 0;
            maxDepth = dfsMaxDepth(0);

            idx = 0;
            cutCount = 0;
            dfsCountCuts(0);

            System.out.println(cutCount);
        }
    }

    private static int dfsMaxDepth(int d) {
        if (s.charAt(idx) == '0') {
            idx++;
            return d;
        }

        idx++;
        int leftMax = dfsMaxDepth(d + 1);
        int rightMax = dfsMaxDepth(d + 1);
        return Math.max(leftMax, rightMax);
    }

    private static boolean dfsCountCuts(int d) {
        if (s.charAt(idx) == '0') {
            idx++;
            return d == maxDepth;
        }

        cutCount++;
        idx++;
        if (dfsCountCuts(d + 1)) {
            return true;
        }

        return dfsCountCuts(d + 1);
    }
}