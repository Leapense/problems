import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N_cols;
    static int M_rows;
    static char[][] battlefield;
    static boolean[][] visited;

    static int[] dr = { -1, 1, 0, 0 };
    static int[] dc = { 0, 0, -1, 1 };

    static int currentGroupSize;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N_cols = Integer.parseInt(st.nextToken());
        M_rows = Integer.parseInt(st.nextToken());

        battlefield = new char[M_rows][N_cols];
        visited = new boolean[M_rows][N_cols];

        for (int i = 0; i < M_rows; i++) {
            String line = br.readLine();
            for (int j = 0; j < N_cols; j++) {
                battlefield[i][j] = line.charAt(j);
            }
        }

        long totalWhitePower = 0;
        long totalBluePower = 0;

        for (int r = 0; r < M_rows; r++) {
            for (int c = 0; c < N_cols; c++) {
                if (!visited[r][c]) {
                    currentGroupSize = 0;
                    char teamColor = battlefield[r][c];
                    dfs(r, c, teamColor);

                    long groupPower = (long) currentGroupSize * currentGroupSize;

                    if (teamColor == 'W') {
                        totalWhitePower += groupPower;
                    } else {
                        totalBluePower += groupPower;
                    }
                }
            }
        }

        System.out.println(totalWhitePower + " " + totalBluePower);
    }

    static void dfs(int r, int c, char teamColor) {
        if (r < 0 || r >= M_rows || c < 0 || c >= N_cols)
            return;
        if (visited[r][c] || battlefield[r][c] != teamColor)
            return;

        visited[r][c] = true;
        currentGroupSize++;

        for (int i = 0; i < 4; i++) {
            dfs(r + dr[i], c + dc[i], teamColor);
        }
    }
}