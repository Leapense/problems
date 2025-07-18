import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int nodeCount = Integer.parseInt(tokenizer.nextToken());
        int edgeCount = Integer.parseInt(tokenizer.nextToken());
        List<Integer>[] adjacencyList = new ArrayList[nodeCount + 1];
        for (int index = 1; index <= nodeCount; index++) {
            adjacencyList[index] = new ArrayList<>();
        }

        for (int index = 0; index < edgeCount; index++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int source = Integer.parseInt(tokenizer.nextToken());
            int target = Integer.parseInt(tokenizer.nextToken());
            adjacencyList[source].add(target);
            adjacencyList[target].add(source);
        }

        boolean isSmallWorld = true;
        for (int start = 1; start <= nodeCount; start++) {
            int[] distances = new int[nodeCount + 1];
            Arrays.fill(distances, -1);
            Queue<Integer> queue = new LinkedList<>();
            distances[start] = 0;
            queue.add(start);
            while (!queue.isEmpty()) {
                int current = queue.poll();
                if (distances[current] >= 6) {
                    continue;
                }

                for (int neighbor : adjacencyList[current]) {
                    if (distances[neighbor] < 0) {
                        distances[neighbor] = distances[current] + 1;
                        queue.add(neighbor);
                    }
                }
            }

            for (int index = 1; index <= nodeCount; index++) {
                if (distances[index] < 0 || distances[index] > 6) {
                    isSmallWorld = false;
                    break;
                }
            }
            if (!isSmallWorld) {
                break;
            }
        }

        System.out.println(isSmallWorld ? "Small World!" : "Big World!");
    }
}