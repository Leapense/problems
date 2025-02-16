import java.util.Scanner;

public class Main {
    static final int SIZE = 19;
    static final int[][] directions = {
            { 0, 1 },
            { 1, 0 },
            { 1, 1 },
            { -1, 1 }
    };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[][] board = new int[SIZE + 1][SIZE + 1];

        for (int move = 1; move <= N; move++) {
            int r = sc.nextInt();
            int c = sc.nextInt();
            int color = (move % 2 == 1) ? 1 : 2;

            board[r][c] = color;

            if (isWinningMove(board, r, c, color)) {
                System.out.println(move);
                return;
            }
        }

        System.out.println(-1);
    }

    private static boolean isWinningMove(int[][] board, int r, int c, int color) {
        for (int[] dir : directions) {
            int count = 1;
            int dr = dir[0];
            int dc = dir[1];

            int nr = r + dr;
            int nc = c + dc;

            while (isInBounds(nr, nc) && board[nr][nc] == color) {
                count++;
                nr += dr;
                nc += dc;
            }

            int revDr = -dr;
            int revDc = -dc;
            int revR = r + revDr;
            int revC = c + revDc;

            while (isInBounds(revR, revC) && board[revR][revC] == color) {
                count++;
                revR += revDr;
                revC += revDc;
            }

            if (count == 5) {
                if (!(isInBounds(nr, nc) && board[nr][nc] == color)
                        && !(isInBounds(revR, revC) && board[revR][revC] == color)) {
                    return true;
                }
            }
        }

        return false;
    }

    private static boolean isInBounds(int r, int c) {
        return r >= 1 && r <= SIZE && c >= 1 && c <= SIZE;
    }
}