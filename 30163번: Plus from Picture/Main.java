import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());

        char[][] grid = new char[h][w];
        for (int i = 0; i < h; i++) {
            grid[i] = br.readLine().toCharArray();
        }

        int totalStars = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '*') {
                    totalStars++;
                }
            }
        }

        int centerRow = -1, centerCol = -1;
        boolean found = false;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '*') {
                    if (i > 0 && i < h - 1 && j > 0 && j < w - 1) {
                        if (grid[i - 1][j] == '*' && grid[i + 1][j] == '*' && grid[i][j - 1] == '*'
                                && grid[i][j + 1] == '*') {
                            centerRow = i;
                            centerCol = j;
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (found)
                break;
        }

        if (!found) {
            System.out.println("NO");
            return;
        }

        int up = 0, down = 0, left = 0, right = 0;

        for (int i = centerRow - 1; i >= 0 && grid[i][centerCol] == '*'; i--) {
            up++;
        }

        for (int i = centerRow + 1; i < h && grid[i][centerCol] == '*'; i++) {
            down++;
        }

        for (int j = centerCol - 1; j >= 0 && grid[centerRow][j] == '*'; j--) {
            left++;
        }

        for (int j = centerCol + 1; j < w && grid[centerRow][j] == '*'; j++) {
            right++;
        }

        if (up == 0 || down == 0 || left == 0 || right == 0) {
            System.out.println("NO");
            return;
        }

        int plusCount = 1 + up + down + left + right;

        if (plusCount == totalStars) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}