import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static char[][] field;
    static boolean[][] visited;
    static int[] dx = { 1, -1, 0, 0 };
    static int[] dy = { 0, 0, 1, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        field = new char[N][];
        visited = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            field[i] = br.readLine().toCharArray();
        }

        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (field[i][j] == '*' && !visited[i][j]) {
                    count++;
                    dfs(i, j);
                }
            }
        }

        System.out.println(count);
    }

    static void dfs(int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (field[nx][ny] == '*' && !visited[nx][ny]) {
                    dfs(nx, ny);
                }
            }
        }
    }
}