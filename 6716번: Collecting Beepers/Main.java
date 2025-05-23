import java.util.*;
import java.io.*;

public class Main {
    static int startX, startY;
    static int[][] beepers;
    static int n;
    static boolean[] visited;
    static int minDistance;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int scenarios = sc.nextInt();
        for (int s = 0; s < scenarios; s++) {
            int worldX = sc.nextInt();
            int worldY = sc.nextInt();
            startX = sc.nextInt();
            startY = sc.nextInt();
            n = sc.nextInt();
            beepers = new int[n][2];
            for (int i = 0; i < n; i++) {
                beepers[i][0] = sc.nextInt();
                beepers[i][1] = sc.nextInt();
            }

            visited = new boolean[n];
            minDistance = Integer.MAX_VALUE;
            dfs(startX, startY, 0, 0);
            System.out.println("The shortest path has length " + minDistance);
        }
    }

    static void dfs(int x, int y, int count, int distance) {
        if (distance >= minDistance)
            return;
        if (count == n) {
            distance += manhattanDistance(x, y, startX, startY);
            if (distance < minDistance)
                minDistance = distance;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                int newDistance = distance + manhattanDistance(x, y, beepers[i][0], beepers[i][1]);
                dfs(beepers[i][0], beepers[i][1], count + 1, newDistance);
                visited[i] = false;
            }
        }
    }

    static int manhattanDistance(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }
}