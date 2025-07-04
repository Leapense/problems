import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int usage = scanner.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }
        int target = usage == 1 ? 1 : 0;
        if (target == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        boolean changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < n && !changed; i++) {
                int count = 0;
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        count++;
                    }
                }

                if (count > n / 2 && count < n) {
                    for (int j = 0; j < n; j++) {
                        grid[i][j] = 1;
                    }

                    changed = true;
                }
            }

            for (int j = 0; j < n && !changed; j++) {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    if (grid[i][j] == 1) {
                        count++;
                    }
                }

                if (count > n / 2 && count < n) {
                    for (int i = 0; i < n; i++) {
                        grid[i][j] = 1;
                    }
                    changed = true;
                }
            }
        }

        boolean success = true;
        for (int i = 0; i < n && success; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) {
                    success = false;
                    break;
                }
            }
        }

        System.out.println(success ? 1 : 0);
    }
}