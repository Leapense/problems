import java.util.*;

public class Main
{
    static final int[] dRow = {-1, 1, 0, 0};
    static final int[] dCol = {0, 0, 1, -1};
    static final char[] dirs = {'N', 'S', 'E', 'W'};

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        while (true)
        {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int startCol = sc.nextInt();

            if (n == 0 && m == 0 && startCol == 0) break;

            sc.nextLine();

            char[][] grid = new char[n][m];
            for (int i = 0; i < n; i++)
            {
                String line = sc.nextLine().trim();
                grid[i] = line.toCharArray();
            }

            solve(grid, n, m, startCol - 1);
        }
        sc.close();
    }

    private static void solve(char[][] grid, int n, int m, int startCol) {
        int[][] visited = new int[n][m];
        int row = 0, col = startCol, step = 0;

        while (true)
        {
            step++;
            if (row < 0 || row >= n || col < 0 || col >= m) {
                System.out.printf("%d step(s) to exit%n", step - 1);
                return;
            }

            if (visited[row][col] != 0) {
                int loopStart = visited[row][col];
                int beforeLoop = loopStart - 1;
                int loopLen = step - loopStart;
                System.out.printf("%d step(s) before a loop of %d step(s)%n", beforeLoop, loopLen);
                return;
            }

            visited[row][col] = step;

            char dir = grid[row][col];
            int d = "NSEW".indexOf(dir);
            row += dRow[d];
            col += dCol[d];
        }
    }
}