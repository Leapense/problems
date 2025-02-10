import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int t = 0; t < T; t++) {
            int X = sc.nextInt();
            int Y = sc.nextInt();
            int moveX = sc.nextInt();
            int moveY = sc.nextInt();

            boolean[][] visited = new boolean[Y][X];
            int answer = 0;

            for (int r = 0; r < Y; r++) {
                for (int c = 0; c < X; c++) {
                    if (!visited[r][c]) {
                        int startR = r, startC = c;
                        while (startR - moveY >= 0 && startC - moveX >= 0) {
                            startR -= moveY;
                            startC -= moveX;
                        }

                        int chainLength = 0;
                        int cr = startR, cc = startC;
                        while (cr < Y && cc < X) {
                            if (!visited[cr][cc]) {
                                visited[cr][cc] = true;
                            }

                            chainLength++;
                            cr += moveY;
                            cc += moveX;
                        }

                        answer += (chainLength + 1) / 2;
                    }
                }
            }

            System.out.println(answer);
        }

        sc.close();
    }
}