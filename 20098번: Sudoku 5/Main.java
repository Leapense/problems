import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    private final int n;
    private final int size;
    private final int[][] board;

    private final boolean[][] rows;
    private final boolean[][] cols;
    private final boolean[][] boxes;

    public Main(int n, int[][] initialBoard)
    {
        this.n = n;
        this.size = n * n;
        this.board = initialBoard;

        this.rows = new boolean[size][size + 1];
        this.cols = new boolean[size][size + 1];
        this.boxes = new boolean[size][size + 1];

        initializeState();
    }

    private void initializeState()
    {
        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                if (board[r][c] != 0)
                {
                    placeNumber(r, c, board[r][c]);
                }
            }
        }
    }

    public boolean solve()
    {
        int[] cell = findMostConstrainedCell();
        if (cell == null)
        {
            return true;
        }

        int r = cell[0];
        int c = cell[1];

        for (int num = 1; num <= size; num++)
        {
            if (isValid(r, c, num)) {
                placeNumber(r, c, num);
                if (solve()) {
                    return true;
                }
                removeNumber(r, c, num);
            }
        }

        return false;
    }

    private int[] findMostConstrainedCell() {
        int[] bestCell = null;
        int minPossibilities = size + 1;

        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                if (board[r][c] == 0) {
                    int possibilities = countPossibilities(r, c);
                    if (possibilities < minPossibilities) {
                        minPossibilities = possibilities;
                        bestCell = new int[]{r, c};
                    }
                }
            }
        }

        return bestCell;
    }

    private int countPossibilities(int r, int c) {
        int count = 0;
        for (int num = 1; num <= size; num++) {
            if (isValid(r, c, num)) {
                count++;
            }
        }

        return count;
    }

    private boolean isValid(int r, int c, int num) {
        int boxIndex = (r / n) * n + (c / n);
        return !rows[r][num] && !cols[c][num] && !boxes[boxIndex][num];
    }

    private void placeNumber(int r, int c, int num) {
        board[r][c] = num;
        rows[r][num] = true;
        cols[c][num] = true;
        boxes[(r / n) * n + (c / n)][num] = true;
    }

    private void removeNumber(int r, int c, int num) {
        board[r][c] = 0;
        rows[r][num] = false;
        cols[c][num] = false;
        boxes[(r / n) * n + (c / n)][num] = false;
    }

    public void printBoard() {
        StringBuilder sb = new StringBuilder();
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                sb.append(board[r][c]).append(c == size - 1 ? "" : " ");
            }
            sb.append("\n");
        }
        System.out.print(sb.toString());
    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            int size = n * n;
            int[][] board = new int[size][size];

            for (int i = 0; i < size; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < size; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            Main solver = new Main(n, board);
            if (solver.solve()) {
                solver.printBoard();
            }
        }
    }
}