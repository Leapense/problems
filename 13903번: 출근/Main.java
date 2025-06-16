import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private int R, C;
    private int[][] board;
    private int[][] moveRules;

    private static class Point {
        int r, c;

        Point(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public int solve() {
        int[][] visited = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                visited[i][j] = -1;
            }
        }

        Queue<Point> queue = new LinkedList<>();
        for (int j = 0; j < C; j++) {
            if (board[0][j] == 1) {
                queue.offer(new Point(0, j));
                visited[0][j] = 0;
            }
        }

        if (queue.isEmpty()) {
            return -1;
        }

        while (!queue.isEmpty()) {
            Point current = queue.poll();

            if (current.r == R - 1) {
                return visited[current.r][current.c];
            }

            for (int[] rule : moveRules) {
                int nextR = current.r + rule[0];
                int nextC = current.c + rule[1];

                if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C
                    && board[nextR][nextC] == 1
                    && visited[nextR][nextC] == -1) {
                        visited[nextR][nextC] = visited[current.r][current.c] + 1;
                        queue.offer(new Point(nextR, nextC));
                }
            }
        }

        return -1;
    }

    public void readInput() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        board = new int[R][C];
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(reader.readLine());
            for (int j = 0; j < C; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int N = Integer.parseInt(reader.readLine());
        moveRules = new int[N][2];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(reader.readLine());
            moveRules[i][0] = Integer.parseInt(st.nextToken());
            moveRules[i][1] = Integer.parseInt(st.nextToken());
        }
    }

    public static void main(String[] args) throws IOException {
        Main main = new Main();
        main.readInput();
        System.out.println(main.solve());
    }
}