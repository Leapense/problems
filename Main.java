import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String[]> boards = new ArrayList<>();
        List<String[]> board = new ArrayList<>();

        while (scanner.hasNextLine()) {
            String line = scanner.nextLine().trim();
            if (line.equals("Finished")) {
                if (!board.isEmpty()) {
                    boards.add(board.toArray(new String[0]));
                }
                break;
            } else if (line.isEmpty()) {
                if (!board.isEmpty()) {
                    boards.add(board.toArray(new String[0]));
                }
                board = new ArrayList<>();
            } else {
                board.add(line.split(" "));
            }
        }

        for (String[] b : boards) {
            System.out.println(findSafeMove(b));
        }
    }

    public static int findSafeMove(String[][] board) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j].equals("*")) {
                    if (!isWinningMove(board, "O", i, j) && !isWinningMove(board, "X", i, j)) {
                        return i * 5 + j + 1;
                    }
                }
            }
        }
        return -1;
    }

    public static boolean isWinningMove(String[][] board, String player, int row, int col) {
        board[row][col] = player;
        boolean win = checkWin(board, player);
        board[row][col] = "*";
        return win;
    }

    public static boolean checkWin(String[][] board, String player) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 2; j++) {
                if (allEqual(board[i], player, j, 4) || allEqual(getColumn(board, i), player, j, 4)) {
                    return true;
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (checkDiagonal(board, player, i, j, 4) || checkAntiDiagonal(board, player, i, j, 4)) {
                    return true;
                }
            }
        }
        return false;
    }

    public static boolean allEqual(String[] array, String player, int start, int count) {
        for (int i = start; i < start + count; i++) {
            if (!array[i].equals(player)) {
                return false;
            }
        }
        return true;
    }

    public static String[] getColumn(String[][] board, int col) {
        String[] column = new String[5];
        for (int i = 0; i < 5; i++) {
            column[i] = board[i][col];
        }
        return column;
    }

    public static boolean checkDiagonal(String[][] board, String player, int row, int col, int count) {
        for (int k = 0; k < count; k++) {
            if (!board[row + k][col + k].equals(player)) {
                return false;
            }
        }
        return true;
    }

    public static boolean checkAntiDiagonal(String[][] board, String player, int row, int col, int count) {
        for (int k = 0; k < count; k++) {
            if (!board[row + 3 - k][col + k].equals(player)) {
                return false;
            }
        }
        return true;
    }
}