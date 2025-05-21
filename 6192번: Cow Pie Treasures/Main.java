import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            final int rows = Integer.parseInt(st.nextToken());
            final int cols = Integer.parseInt(st.nextToken());

            int[][] grid = new int[rows][cols];
            for (int r = 0; r < rows; r++) {
                st = new StringTokenizer(reader.readLine());
                for (int c = 0; c < cols; c++) {
                    grid[r][c] = Integer.parseInt(st.nextToken());
                }
            }

            int[] prev = new int[rows];
            int[] curr = new int[rows];

            final int NEG_INF = Integer.MIN_VALUE / 2;
            for (int r = 0; r < rows; r++) {
                prev[r] = (r == 0) ? grid[0][0] : NEG_INF;
            }
            for (int c = 1; c < cols; c++) {
                for (int r = 0; r < rows; r++) {
                    int best = prev[r];
                    if (r > 0) {
                        best = Math.max(best, prev[r - 1]);
                    }
                    if (r + 1 < rows) {
                        best = Math.max(best, prev[r + 1]);
                    }

                    curr[r] = best + grid[r][c];
                }
                System.arraycopy(curr, 0, prev, 0, rows);
            }

            System.out.println(prev[rows - 1]);
        }
    }
}