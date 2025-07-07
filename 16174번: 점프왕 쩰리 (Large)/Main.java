import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static final String SUCCESS = "HaruHaru";
    private static final String FAILURE = "Hing";

    private static final class Point {
        final int row;
        final int col;

        Point(int r, int c) {
            this.row = r;
            this.col = c;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine().trim());
        int[][] board = new int[n][n];
        for (int r = 0; r < n; r++) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            for (int c = 0; c < n; c++) {
                board[r][c] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(canReachDestination(board) ? SUCCESS : FAILURE);
    }

    private static boolean canReachDestination(int[][] board) {
        int n = board.length;
        boolean[][] visited = new boolean[n][n];
        Queue<Point> queue = new ArrayDeque<>();
        queue.add(new Point(0, 0));
        visited[0][0] = true;

        while (!queue.isEmpty()) {
            Point current = queue.poll();
            int value = board[current.row][current.col];
            if (value == -1) return true;
            if (value == 0) continue;

            int nextRow = current.row + value;
            int nextCol = current.col + value;

            if (nextRow < n && !visited[nextRow][current.col]) {
                visited[nextRow][current.col] = true;
                queue.add(new Point(nextRow, current.col));
            }
            if (nextCol < n && !visited[current.row][nextCol]) {
                visited[current.row][nextCol] = true;
                queue.add(new Point(current.row, nextCol));
            }
        }
        return false;
    }
}