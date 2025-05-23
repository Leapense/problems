import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    private static final int[][] MOVES = {
            { -2, -1 }, { -2, 1 }, { -1, -2 }, { -1, 2 }, { 1, -2 }, { 1, 2 }, { 2, -1 }, { 2, 1 }
    };

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String line;
            StringBuilder output = new StringBuilder();

            while ((line = br.readLine()) != null && !line.trim().isEmpty()) {
                StringTokenizer st = new StringTokenizer(line);
                int rows = Integer.parseInt(st.nextToken());
                int cols = Integer.parseInt(st.nextToken());
                int startRow = Integer.parseInt(st.nextToken()) - 1;
                int startCol = Integer.parseInt(st.nextToken()) - 1;
                int targetRow = Integer.parseInt(st.nextToken()) - 1;
                int targetCol = Integer.parseInt(st.nextToken()) - 1;

                int result = findShortestPath(rows, cols, startRow, startCol, targetRow, targetCol);

                if (result == -1) {
                    output.append("impossible\n");
                } else {
                    output.append(result).append("\n");
                }
            }

            System.out.println(output);
        }
    }

    private static int findShortestPath(int rows, int cols, int startRow, int startCol, int targetRow, int targetCol) {
        if (startRow == targetRow && startCol == targetCol) {
            return 0;
        }

        boolean[][] visited = new boolean[rows][cols];
        Queue<Position> queue = new ArrayDeque<>();

        queue.offer(new Position(startRow, startCol, 0));
        visited[startRow][startCol] = true;

        while (!queue.isEmpty()) {
            Position current = queue.poll();

            for (int[] move : MOVES) {
                int newRow = current.row + move[0];
                int newCol = current.col + move[1];

                if (isValidPosition(newRow, newCol, rows, cols) && !visited[newRow][newCol]) {
                    if (newRow == targetRow && newCol == targetCol) {
                        return current.distance + 1;
                    }

                    visited[newRow][newCol] = true;
                    queue.offer(new Position(newRow, newCol, current.distance + 1));
                }
            }
        }

        return -1;
    }

    private static boolean isValidPosition(int row, int col, int rows, int cols) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    private static class Position {
        final int row;
        final int col;
        final int distance;

        Position(int row, int col, int distance) {
            this.row = row;
            this.col = col;
            this.distance = distance;
        }
    }
}