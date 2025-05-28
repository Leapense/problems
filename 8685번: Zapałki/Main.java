import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine().trim());
        int[] h = new int[n + 2];
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 1; i <= n; i++) {
            h[i] = Integer.parseInt(tokenizer.nextToken());
        }

        int[] leftBound = new int[n + 2];
        int[] rightBound = new int[n + 2];

        leftBound[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (h[i - 1] <= h[i]) leftBound[i] = leftBound[i - 1];
            else leftBound[i] = i;
        }

        rightBound[n] = n;
        for (int i = n - 1; i >= 1; i--) {
            if (h[i + 1] <= h[i]) rightBound[i] = rightBound[i + 1];
            else rightBound[i] = i;
        }

        int maxBurn = 0;
        for (int i = 1; i <= n; i++) {
            int burnCount = rightBound[i] - leftBound[i] + 1;
            if (burnCount > maxBurn) maxBurn = burnCount;
        }

        System.out.println(maxBurn);
    }
}