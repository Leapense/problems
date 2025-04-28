import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    // 8방향 이동 벡터: 상, 하, 좌, 우, 대각선
    private static final int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
    private static final int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            char[][] board = new char[n][m];
            for (int i = 0; i < n; i++) {
                board[i] = br.readLine().toCharArray();
            }

            sb.append(isCorrect(board, n, m)
                    ? "Well done Clark!\n"
                    : "Please sweep the mine again!\n");
        }

        System.out.print(sb);
    }

    /**
     * 보드가 올바르게 해결되었는지 검사
     *
     * @param board n x m 격자
     * @param n     행 개수
     * @param m     열 개수
     * @return 모든 숫자 칸이 인접 깃발 수와 일치하면 true
     */
    private static boolean isCorrect(char[][] board, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c = board[i][j];
                if (c == 'F') {
                    // 깃발 자체에서 추가 검사 불필요:
                    // 잘못된 깃발은 숫자 검사에서 걸러짐
                    continue;
                }
                // 숫자 칸인 경우
                int expected = c - '0'; // '0'~'8'
                int countF = 0;
                // 8방향 순회
                for (int d = 0; d < 8; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m
                            && board[ni][nj] == 'F') {
                        countF++;
                    }
                }
                if (countF != expected) {
                    return false;
                }
            }
        }
        return true;
    }
}
