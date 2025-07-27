import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            solve(a, b, c, sb);
        }
        System.out.print(sb.toString());
    }

    private static void solve(int a, int b, int c, StringBuilder sb) {
        int rows = 2 * b + 2 * c + 1;
        int cols = 2 * b + 2 * a + 1;
        char[][] grid = new char[rows][cols];

        for (int i = 0; i < rows; i++) {
            Arrays.fill(grid[i], '.');
        }

        drawTopFace(a, b, grid);
        drawFrontFace(a, b, c, grid);
        drawRightFace(a, b, c, grid);

        for (int i = 0; i < rows; i++) {
            sb.append(new String(grid[i])).append("\n");
        }
    }

    private static void drawTopFace(int a, int b, char[][] grid) {
        for (int i = 0; i <= b; i++) {
            for (int j = 0; j <= a; j++) {
                int row = 2 * i;
                int col = 2 * (b - i) + 2 * j;
                grid[row][col] = '+';
                if (j < a) {
                    grid[row][col + 1] = '-';
                }
                if (i < b) {
                    grid[row + 1][col - 1] = '/';
                }
            }
        }
    }

    private static void drawFrontFace(int a, int b, int c, char[][] grid) {
        for (int i = 0; i <= c; i++) {
            for (int j = 0; j <= a; j++) {
                int row = 2 * b + 2 * i;
                int col = 2 * j;
                grid[row][col] = '+';
                if (j < a) {
                    grid[row][col + 1] = '-';
                }
                if (i < c) {
                    grid[row + 1][col] = '|';
                }
            }
        }
    }

    private static void drawRightFace(int a, int b, int c, char[][] grid) {
        for (int i = 0; i <= c; i++) {
            for (int j = 0; j <= b; j++) {
                int row = 2 * b + 2 * i - 2 * j;
                int col = 2 * a + 2 * j;
                grid[row][col] = '+';
                if (i < c) {
                    grid[row + 1][col] = '|';
                }
                if (j < b) {
                    grid[row - 1][col + 1] = '/';
                }
            }
        }
    }
}