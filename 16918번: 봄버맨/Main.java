import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String firstLine = scanner.nextLine();
        String[] parts = firstLine.split(" ");
        int R = Integer.parseInt(parts[0]);
        int C = Integer.parseInt(parts[1]);
        int N = Integer.parseInt(parts[2]);

        int[][] timer = new int[R][C];
        for (int i = 0; i < R; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < C; j++) {
                timer[i][j] = (line.charAt(j) == 'O') ? 0 : -1;
            }
        }

        for (int t = 1; t <= N; t++) {
            if (t % 2 == 0) {
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        if (timer[i][j] == -1) {
                            timer[i][j] = t;
                        }
                    }
                }
            }
            if (t >= 3 && t % 2 == 1) {
                boolean[][] destroyed = new boolean[R][C];
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        if (timer[i][j] == t - 3) {
                            destroyed[i][j] = true;
                            if (i > 0) destroyed[i - 1][j] = true;
                            if (i < R - 1) destroyed[i + 1][j] = true;
                            if (j > 0) destroyed[i][j - 1] = true;
                            if (j < C - 1) destroyed[i][j + 1] = true;
                        }
                    }
                }
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        if (destroyed[i][j]) {
                            timer[i][j] = -1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                System.out.print((timer[i][j] != -1) ? 'O' : '.');
            }
            System.out.println();
        }
    }
}