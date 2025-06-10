import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main
{
    private static final int MAX_STONE_INDEX = 100000;
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int springPowerA = Integer.parseInt(st.nextToken());
        int springPowerB = Integer.parseInt(st.nextToken());
        int startIndex = Integer.parseInt(st.nextToken());
        int targetIndex = Integer.parseInt(st.nextToken());

        int minimumMoves = calculateMinimumMoves(springPowerA, springPowerB, startIndex, targetIndex);
        System.out.println(minimumMoves);
    }

    private static int calculateMinimumMoves(int springPowerA, int springPowerB, int startIndex, int targetIndex) {
        boolean[] visited = new boolean[MAX_STONE_INDEX + 1];
        int[] distance = new int[MAX_STONE_INDEX + 1];
        Deque<Integer> queue = new ArrayDeque<>();

        visited[startIndex] = true;
        distance[startIndex] = 0;
        queue.addLast(startIndex);

        while (!queue.isEmpty()) {
            int currentPosition = queue.removeFirst();
            if (currentPosition == targetIndex) {
                break;
            }

            int nextDistance = distance[currentPosition] + 1;
            int[] nextPositions = {
                currentPosition + 1,
                currentPosition - 1,
                currentPosition + springPowerA,
                currentPosition - springPowerA,
                currentPosition + springPowerB,
                currentPosition - springPowerB,
                currentPosition * springPowerA,
                currentPosition * springPowerB
            };

            for (int nextPosition : nextPositions) {
                if (nextPosition >= 0 && nextPosition <= MAX_STONE_INDEX && !visited[nextPosition]) {
                    visited[nextPosition] = true;
                    distance[nextPosition] = nextDistance;
                    queue.addLast(nextPosition);
                }
            }
        }

        return distance[targetIndex];
    }
}