import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private int solve(int n, int[] columnHeights) {
        if (n == 0) {
            return 0;
        }

        int[] leftRamp = new int[n];
        int[] rightRamp = new int[n];
        
        leftRamp[0] = Math.min(columnHeights[0], 1);
        for (int i = 1; i < n; i++) {
            leftRamp[i] = Math.min(columnHeights[i], leftRamp[i - 1] + 1);
        }

        rightRamp[n - 1] = Math.min(columnHeights[n - 1], 1);
        for (int i = n - 2; i >= 0; i--) {
            rightRamp[i] = Math.min(columnHeights[i], rightRamp[i + 1] + 1);
        }

        int maxTriangleHeight = 0;
        for (int i = 0; i < n; i++) {
            int currentMaxHeight = Math.min(leftRamp[i], rightRamp[i]);
            if (currentMaxHeight > maxTriangleHeight) {
                maxTriangleHeight = currentMaxHeight;
            }
        }

        return maxTriangleHeight;
    }

    public void run() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        int[] columnHeights = new int[n];

        StringTokenizer st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            columnHeights[i] = Integer.parseInt(st.nextToken());
        }

        int result = solve(n, columnHeights);
        System.out.println(result);
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}