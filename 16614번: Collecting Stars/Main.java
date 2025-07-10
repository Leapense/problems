import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.PriorityQueue;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int k = Integer.parseInt(tokenizer.nextToken());
        int[][] stars = new int[n][2];

        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int t = Integer.parseInt(tokenizer.nextToken());
            int d = Integer.parseInt(tokenizer.nextToken());
            stars[i][0] = d;
            stars[i][1] = t;
        }

        Arrays.sort(stars, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        long totalTime = 0;
        int collectedCount = 0;
        int index = 0;
        while (collectedCount < k) {
            while (index < n && stars[index][0] <= collectedCount) {
                minHeap.add(stars[index][1]);
                index++;
            }
            if (minHeap.isEmpty()) {
                System.out.println("IMPOSSIBLE");
                return;
            }

            totalTime += minHeap.poll();
            collectedCount++;
        }

        System.out.println(totalTime);
    }
}