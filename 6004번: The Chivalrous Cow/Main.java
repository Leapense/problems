import java.util.*;
import java.io.*;

public class Main {
    static int X, Y;
    static char[][] grid;
    static boolean[][] visited;
    static int[] dx = { 2, 2, -2, -2, 1, 1, -1, -1 };
    static int[] dy = { 1, -1, 1, -1, 2, -2, 2, -2 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());
        grid = new char[Y][X];
        visited = new boolean[Y][X];
        int startX = -1, startY = -1;
        for (int i = 0; i < Y; i++) {
            String line = br.readLine();
            for (int j = 0; j < X; j++) {
                grid[i][j] = line.charAt(j);
                if (grid[i][j] == 'K') {
                    startY = i;
                    startX = j;
                }
            }
        }
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] { startY, startX, 0 });
        visited[startY][startX] = true;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int y = cur[0], x = cur[1], hops = cur[2];
            if (grid[y][x] == 'H') {
                System.out.println(hops);
                return;
            }
            for (int i = 0; i < 8; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if (nx >= 0 && nx < X && ny >= 0 && ny < Y && !visited[ny][nx] && grid[ny][nx] != '*') {
                    visited[ny][nx] = true;
                    queue.offer(new int[] { ny, nx, hops + 1 });
                }
            }
        }
    }
}