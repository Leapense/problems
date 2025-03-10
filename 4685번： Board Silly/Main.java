import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            List<String> boardLines = new ArrayList<>();
            for (int i = 0; i < 8; i++) {
                if (!scanner.hasNextLine())
                    break;
                boardLines.add(scanner.nextLine());
            }
            if (boardLines.size() < 8)
                break;
            if (!scanner.hasNextLine())
                break;
            String playerLine = scanner.nextLine();
            char[][] board = new char[8][8];
            for (int r = 0; r < 8; r++) {
                String line = boardLines.get(r);
                for (int c = 0; c < 8; c++) {
                    board[r][c] = line.charAt(c);
                }
            }
            char P = playerLine.charAt(0);
            char Q = (P == 'X') ? 'O' : 'X';
            int[] row_count = new int[8];
            int[] col_count = new int[8];
            int[] diag1 = new int[15]; // r + c
            int[] diag2 = new int[15]; // r - c + 7
            for (int r = 0; r < 8; r++) {
                for (int c = 0; c < 8; c++) {
                    if (board[r][c] == 'X' || board[r][c] == 'O') {
                        row_count[r]++;
                        col_count[c]++;
                        diag1[r + c]++;
                        diag2[r - c + 7]++;
                    }
                }
            }
            int[][] directions = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 }, { -1, 1 }, { -1, -1 }, { 1, 1 },
                    { 1, -1 } };
            List<String> moves = new ArrayList<>();
            for (int r = 0; r < 8; r++) {
                for (int c = 0; c < 8; c++) {
                    if (board[r][c] == P) {
                        for (int[] dir : directions) {
                            int dr = dir[0];
                            int dc = dir[1];
                            int N;
                            if (dr == 0) {
                                N = row_count[r];
                            } else if (dc == 0) {
                                N = col_count[c];
                            } else if (dr == dc) {
                                N = diag2[r - c + 7];
                            } else {
                                N = diag1[r + c];
                            }
                            int dest_r = r + N * dr;
                            int dest_c = c + N * dc;
                            if (dest_r >= 0 && dest_r < 8 && dest_c >= 0 && dest_c < 8) {
                                boolean valid = true;
                                for (int k = 1; k < N; k++) {
                                    int pos_r = r + k * dr;
                                    int pos_c = c + k * dc;
                                    if (board[pos_r][pos_c] == Q) {
                                        valid = false;
                                        break;
                                    }
                                }
                                if (valid && board[dest_r][dest_c] != P) {
                                    String move = "" + (char) ('A' + r) + (c + 1) + "-" + (char) ('A' + dest_r)
                                            + (dest_c + 1);
                                    moves.add(move);
                                }
                            }
                        }
                    }
                }
            }
            if (moves.isEmpty()) {
                System.out.println("No moves are possible");
            } else {
                for (String move : moves) {
                    System.out.println(move);
                }
            }
            System.out.println();
        }
        scanner.close();
    }
}