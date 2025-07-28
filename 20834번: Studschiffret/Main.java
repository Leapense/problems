import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] parts = br.readLine().split(" ");
        int N = Integer.parseInt(parts[0]);
        int M = Integer.parseInt(parts[1]);
        String cipher = br.readLine();
        int K = cipher.length();

        boolean[][] occupied = new boolean[N][M];
        List<int[]> positions = new ArrayList<>();
        int r = 0, c = 0, dr = 1, dc = 1;
        occupied[0][0] = true;
        positions.add(new int[]{0, 0});

        while (positions.size() < K) {
            if (r + dr < 0 || r + dr >= N) dr = -dr;
            if (c + dc < 0 || c + dc >= M) dc = -dc;
            r += dr;
            c += dc;
            if (!occupied[r][c]) {
                occupied[r][c] = true;
                positions.add(new int[]{r, c});
            }
        }

        char[][] grid = new char[N][M];
        int idx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (occupied[i][j]) {
                    grid[i][j] = cipher.charAt(idx++);
                }
            }
        }

        StringBuilder original = new StringBuilder();
        for (int[] p : positions) {
            original.append(grid[p[0]][p[1]]);
        }

        System.out.println(original);
    }
}