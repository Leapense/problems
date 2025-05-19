import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        boolean[][] grid = new boolean[R][C];
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                grid[i][j] = st.nextToken().charAt(0) == '1';
            }
        }

        br.close();

        long answer = 0;
        int maxMask = 1 << R;

        for (int mask = 0; mask < maxMask; mask++) {
            long total = 0;
            for (int j = 0; j < C; j++) {
                int ones = 0;
                for (int i = 0; i < R; i++) {
                    boolean bit = grid[i][j] ^ ((mask & (1 << i)) != 0);
                    if (bit)
                        ones++;
                }

                total += Math.max(ones, R - ones);
            }

            if (total > answer) {
                answer = total;
            }
        }

        System.out.println(answer);
    }
}