import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();
        String message = sc.nextLine();

        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = '#';
            }
        }

        int mid = n / 2;
        int r = mid, c = mid;
        int idx = 0;

        if (idx < message.length()) {
            board[r][c] = message.charAt(idx++);
        } else {
            board[r][c] = '#';
        }

        int total = n * n;
        int count = 1;

        int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
        int dirIndex = 0;
        int steps = 1;

        while (count < total) {
            for (int d = 0; d < 2; d++) {
                int dr = dirs[dirIndex][0];
                int dc = dirs[dirIndex][1];
                for (int s = 0; s < steps; s++) {
                    if (count >= total)
                        break;
                    r += dr;
                    c += dc;
                    if (idx < message.length()) {
                        board[r][c] = message.charAt(idx++);
                    } else {
                        board[r][c] = '#';
                    }

                    count++;
                }

                dirIndex = (dirIndex + 1) % 4;
            }

            steps++;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '#') {
                    sb.append(board[i][j]);
                }
            }
        }

        System.out.println(sb.toString());
    }
}