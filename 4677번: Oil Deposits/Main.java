import java.io.*;

public class Main {
    static int m, n;
    static char[][] grid;
    static boolean[][] visited;
    static int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String[] tokens = br.readLine().split(" ");
            m = Integer.parseInt(tokens[0]);
            n = Integer.parseInt(tokens[1]);

            if (m == 0)
                break;
            grid = new char[m][n];
            visited = new boolean[m][n];
            for (int i = 0; i < m; i++) {
                grid[i] = br.readLine().toCharArray();
            }
            int count = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '@' && !visited[i][j]) {
                        dfs(i, j);
                        count++;
                    }
                }
            }

            System.out.println(count);
        }
    }

    static void dfs(int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (!visited[nx][ny] && grid[nx][ny] == '@') {
                    dfs(nx, ny);
                }
            }
        }
    }
}