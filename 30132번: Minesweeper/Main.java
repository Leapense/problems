import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static final int[] DX = { -1, -1, -1, 0, 0, 1, 1, 1 };
    private static final int[] DY = { -1, 0, 1, -1, 1, -1, 0, 1 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());

        outer: for (int tc = 0; tc < T; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            char[][] board = new char[n][m];
            for (int i = 0; i < n; i++) {
                board[i] = br.readLine().toCharArray();
            }

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    char cell = board[x][y];
                    if (cell >= '0' && cell <= '8') {
                        int need = cell - '0';
                        int flags = 0;

                        for (int dir = 0; dir < 8; dir++) {
                            int nx = x + DX[dir];
                            int ny = y + DY[dir];
                            if (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] == 'F') {
                                flags++;
                            }
                        }

                        if (flags != need) {
                            System.out.println("Please sweep the mine again!");
                            continue outer;
                        }
                    }
                }
            }

            System.out.println("Well done Clark!");
        }
    }
}