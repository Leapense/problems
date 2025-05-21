import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    // Directions: up, down, left, right, and all diagonals
    private static final int[] DX = { -1, -1, -1, 0, 1, 1, 1, 0 };
    private static final int[] DY = { -1, 0, 1, 1, 1, 0, -1, -1 };

    public static void main(String[] args) throws IOException {
        // Fast IO
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        char[][] grid = new char[h][w];
        for (int i = 0; i < h; i++) {
            String line = br.readLine();
            grid[i] = line.toCharArray();
        }

        boolean[][] visited = new boolean[h][w];
        int maxGrass = 0;

        // Scan all cells
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j] && grid[i][j] == '.') {
                    int componentSize = bfs(grid, visited, i, j, h, w);
                    maxGrass = Math.max(maxGrass, componentSize);
                }
            }
        }

        System.out.println(maxGrass);
    }

    /**
     * BFS to count the size of a connected component of grass.
     */
    private static int bfs(char[][] grid, boolean[][] visited, int startY, int startX, int h, int w) {
        Queue<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[] { startY, startX });
        visited[startY][startX] = true;
        int count = 1;

        while (!queue.isEmpty()) {
            int[] pos = queue.poll();
            int y = pos[0];
            int x = pos[1];

            for (int dir = 0; dir < 8; dir++) {
                int ny = y + DY[dir];
                int nx = x + DX[dir];
                if (isValid(ny, nx, h, w) && !visited[ny][nx] && grid[ny][nx] == '.') {
                    visited[ny][nx] = true;
                    queue.offer(new int[] { ny, nx });
                    count++;
                }
            }
        }
        return count;
    }

    /**
     * Check if the position is inside the grid.
     */
    private static boolean isValid(int y, int x, int h, int w) {
        return y >= 0 && y < h && x >= 0 && x < w;
    }
}
