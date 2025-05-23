import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            char[][] board = new char[N][N];
            for (int i = 0; i < N; i++) {
                board[i] = br.readLine().toCharArray();
            }

            boolean[][] visited = new boolean[N][N];
            Queue<int[]> queue = new ArrayDeque<>();
            int[][] dirs = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] == 'w') {
                        for (int[] d : dirs) {
                            int ni = i + d[0], nj = j + d[1];
                            if (ni >= 0 && ni < N && nj >= 0 && nj < N && board[ni][nj] == '-' && !visited[ni][nj]) {
                                visited[ni][nj] = true;
                                queue.offer(new int[] { ni, nj });
                            }
                        }
                    }
                }
            }
            int count = 0;
            while (!queue.isEmpty()) {
                int[] cur = queue.poll();
                count++;
                int i = cur[0], j = cur[1];
                for (int[] d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N && board[ni][nj] == '-' && !visited[ni][nj]) {
                        visited[ni][nj] = true;
                        queue.offer(new int[] { ni, nj });
                    }
                }
            }

            out.println(count);
        }
        out.flush();
    }
}