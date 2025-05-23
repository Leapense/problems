import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine()) != null) {
            if (line.trim().isEmpty())
                continue;
            String[] parts = line.split("\\s+");
            int w = Integer.parseInt(parts[0]);
            int h = Integer.parseInt(parts[1]);
            if (w == 0 && h == 0)
                break;
            char[][] grid = new char[h][w];
            for (int i = 0; i < h; i++) {
                grid[i] = br.readLine().toCharArray();
            }

            Queue<int[]> queue = new LinkedList<>();
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (grid[i][j] == 'S') {
                        queue.add(new int[] { i, j });
                    }
                }
            }

            int[] dx = { 0, 0, -1, 1 };
            int[] dy = { -1, 1, 0, 0 };

            while (!queue.isEmpty()) {
                int[] pos = queue.poll();
                int x = pos[0];
                int y = pos[1];
                for (int d = 0; d < 4; d++) {
                    int nx = x + dy[d];
                    int ny = y + dx[d];
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == 'T') {
                        grid[nx][ny] = 'S';
                        queue.add(new int[] { nx, ny });
                    }
                }
            }

            for (int i = 0; i < h; i++) {
                System.out.println(new String(grid[i]));
            }
        }
    }
}