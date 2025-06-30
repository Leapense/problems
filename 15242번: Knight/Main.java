import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    private static final int BOARD_SIZE = 8;
    private static final int[] DX = {-2, -2, -1, -1, 1, 1, 2, 2};
    private static final int[] DY = {-1, 1, -2, 2, -2, 2, -1, 1};

    private static class SquareState {
        private final int x;
        private final int y;
        private final int moves;

        public SquareState(int x, int y, int moves) {
            this.x = x;
            this.y = y;
            this.moves = moves;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public int getMoves() {
            return moves;
        }
    }

    private static int solve(String startPos, String endPos) {
        if (startPos.equals(endPos)) {
            return 0;
        }

        int startX = startPos.charAt(0) - 'a';
        int startY = startPos.charAt(1) - '1';
        int endX = endPos.charAt(0) - 'a';
        int endY = endPos.charAt(1) - '1';

        Queue<SquareState> queue = new LinkedList<>();
        boolean[][] visited = new boolean[BOARD_SIZE][BOARD_SIZE];

        queue.add(new SquareState(startX, startY, 0));
        visited[startX][startY] = true;

        while (!queue.isEmpty()) {
            SquareState current = queue.poll();
            if (current.getX() == endX && current.getY() == endY) {
                return current.getMoves();
            }

            for (int i = 0; i < DX.length; i++) {
                int nextX = current.getX() + DX[i];
                int nextY = current.getY() + DY[i];

                if (isValid(nextX, nextY) && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    queue.add(new SquareState(nextX, nextY, current.getMoves() + 1));
                }
            }
        }

        return -1;
    }

    private static boolean isValid(int x, int y) {
        return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            String startPos = scanner.nextLine();
            String endPos = scanner.nextLine();
            int result = solve(startPos, endPos);
            System.out.println(result);
        }
    }
}