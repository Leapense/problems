import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    private static int numBales;
    private static int numCows;
    private static int[] hayBales;

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            numBales = Integer.parseInt(st.nextToken());
            numCows = Integer.parseInt(st.nextToken());

            hayBales = new int[numBales];
            for (int i = 0; i < numBales; i++) {
                hayBales[i] = Integer.parseInt(br.readLine());
            }
        }

        Arrays.sort(hayBales);

        int left = 0;
        int right = hayBales[numBales - 1] - hayBales[0];
        int result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canCoverAllWithRadius(mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        System.out.println(result);
    }

    private static boolean canCoverAllWithRadius(int radius) {
        int cowsUsed = 0;
        int i = 0;

        while (i < numBales) {
            cowsUsed++;
            if (cowsUsed > numCows) {
                return false;
            }

            long coverageEnd = (long) hayBales[i] + 2L * radius;

            int nextIndex = i + 1;
            while (nextIndex < numBales && hayBales[nextIndex] <= coverageEnd) {
                nextIndex++;
            }

            i = nextIndex;
        }

        return true;
    }
}