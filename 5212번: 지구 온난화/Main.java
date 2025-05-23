import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt(), C = sc.nextInt();
        char[][] map = new char[R][C];
        for (int i = 0; i < R; i++) {
            map[i] = sc.next().toCharArray();
        }

        char[][] newMap = new char[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] == 'X') {
                    int count = 0;
                    if (i - 1 < 0 || map[i - 1][j] == '.')
                        count++;
                    if (i + 1 >= R || map[i + 1][j] == '.')
                        count++;
                    if (j - 1 < 0 || map[i][j - 1] == '.')
                        count++;
                    if (j + 1 >= C || map[i][j + 1] == '.')
                        count++;
                    if (count >= 3)
                        newMap[i][j] = '.';
                    else
                        newMap[i][j] = 'X';
                } else {
                    newMap[i][j] = '.';
                }
            }
        }

        int minRow = R, maxRow = 0, minCol = C, maxCol = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (newMap[i][j] == 'X') {
                    minRow = Math.min(minRow, i);
                    maxRow = Math.max(maxRow, i);
                    minCol = Math.min(minCol, j);
                    maxCol = Math.max(maxCol, j);
                }
            }
        }
        for (int i = minRow; i <= maxRow; i++) {
            for (int j = minCol; j <= maxCol; j++) {
                System.out.print(newMap[i][j]);
            }
            System.out.println();
        }
    }
}