import java.util.Scanner;

public class Main
{
    private static final int N = 10;
    private static final int[] DR = {-1, -1, 1, 1};
    private static final int[] DC = {-1, 1, -1, 1};

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int T = Integer.parseInt(sc.nextLine().trim());
        for (int tc = 0; tc < T; tc++)
        {
            // 빈 줄(테스트 케이스 구분) 건너뛰기
            String line = sc.nextLine();
            while (line != null && line.isEmpty())
            {
                line = sc.nextLine();
            }

            char[][] board = new char[N][N];

            // 첫 줄 처리
            if (line != null && line.length() == N) {
                board[0] = line.toCharArray();
            }
            // 나머지 줄 읽기
            for (int i = (line != null && line.length() == N) ? 1 : 0; i < N; i++) {
                board[i] = sc.nextLine().toCharArray();
            }

            int maxCaptures = 0;
            for (int r = 0; r < N; r++)
            {
                for (int c = 0; c < N; c++)
                {
                    if (board[r][c] == 'W')
                    {
                        maxCaptures = Math.max(maxCaptures, dfs(board, r, c));
                    }
                }
            }

            System.out.println(maxCaptures);
        }

        sc.close();
    }

    private static int dfs(char[][] board, int r, int c)
    {
        int max = 0;
        for (int d = 0; d < 4; d++)
        {
            int nr = r + DR[d];
            int nc = c + DC[d];
            int jr = r + 2 * DR[d];
            int jc = c + 2 * DC[d];
            if (isInBounds(jr, jc) && board[nr][nc] == 'B' && board[jr][jc] == '#')
            {
                // 잡기 시뮬레이션
                board[r][c] = '#';
                board[nr][nc] = '#';
                board[jr][jc] = 'W';
                int captures = 1 + dfs(board, jr, jc);
                if (captures > max)
                {
                    max = captures;
                }

                // 상태 복원
                board[r][c] = 'W';
                board[nr][nc] = 'B';
                board[jr][jc] = '#';
            }
        }

        return max;
    }

    private static boolean isInBounds(int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < N;
    }
}