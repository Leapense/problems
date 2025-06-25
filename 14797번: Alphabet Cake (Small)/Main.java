import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main
{
    private static final char EMPTY = '?';
    public static void main(String[] args) {
        try (Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
            int t = in.nextInt();
            for (int i = 1; i <= t; ++i) {
                int r = in.nextInt();
                int c = in.nextInt();
                char[][] grid = new char[r][c];
                for (int j = 0; j < r; j++) {
                    grid[j] = in.next().toCharArray();
                }

                System.out.println("Case #" + i + ":");
                solve(r, c, grid);
            }
        }
    }

    private static void solve(int rows, int cols, char[][] grid) {
        fillHorizontally(rows, cols, grid);
        fillVertically(rows, cols, grid);
        printGrid(rows, cols, grid);
    }

    private static void fillHorizontally(int rows, int cols, char[][] grid) {
        for (int r = 0; r < rows; r++) {
            char lastChar = EMPTY;
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != EMPTY) {
                    lastChar = grid[r][c];
                } else if (lastChar != EMPTY) {
                    grid[r][c] = lastChar;
                }
            }

            lastChar = EMPTY;
            for (int c = cols - 1; c >= 0; c--) {
                if (grid[r][c] != EMPTY) {
                    lastChar = grid[r][c];
                } else if (lastChar != EMPTY) {
                    grid[r][c] = lastChar;
                }
            }
        }
    }

    private static void fillVertically(int rows, int cols, char[][] grid) {
        char[] lastFilledRow = null;

        // Top to bottom pass
        for (int r = 0; r < rows; r++) {
            if (grid[r][0] != EMPTY) {
                lastFilledRow = grid[r];
            } else if (lastFilledRow != null) {
                System.arraycopy(lastFilledRow, 0, grid[r], 0, cols);
            }
        }
        
        // Bottom to top pass
        lastFilledRow = null;
        for (int r = rows - 1; r >= 0; r--) {
            if (grid[r][0] != EMPTY) {
                lastFilledRow = grid[r];
            } else if (lastFilledRow != null) {
                System.arraycopy(lastFilledRow, 0, grid[r], 0, cols);
            }
        }
    }

    private static void printGrid(int rows, int cols, char[][] grid) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                System.out.print(grid[r][c]);
            }
            System.out.println();
        }
    }
}