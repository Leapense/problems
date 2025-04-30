import java.io.*;
import java.util.*;

public class Main {
    static final int[] DR = { -1, 0, 1, 0 };
    static final int[] DC = { 0, 1, 0, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        char[][] grid = new char[N][];
        for (int i = 0; i < N; i++) {
            grid[i] = br.readLine().toCharArray();
        }
        br.close();

        boolean[][] seen = new boolean[N][M];
        List<Integer> lakeSizes = new ArrayList<>();
        ArrayDeque<int[]> queue = new ArrayDeque<>(N * M);

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (grid[r][c] == '1' && !seen[r][c]) {
                    // Start a BFS to measure this lake
                    seen[r][c] = true;
                    queue.clear();
                    queue.add(new int[] { r, c });
                    int area = 0;

                    while (!queue.isEmpty()) {
                        int[] cur = queue.removeFirst();
                        area++;

                        for (int d = 0; d < 4; d++) {
                            int nr = cur[0] + DR[d];
                            int nc = cur[1] + DC[d];
                            if (nr >= 0 && nr < N && nc >= 0 && nc < M
                                    && grid[nr][nc] == '1' && !seen[nr][nc]) {
                                seen[nr][nc] = true;
                                queue.addLast(new int[] { nr, nc });
                            }
                        }
                    }

                    lakeSizes.add(area);
                }
            }
        }

        Collections.sort(lakeSizes);

        StringBuilder sb = new StringBuilder();
        sb.append(lakeSizes.size()).append('\n');
        for (int i = 0; i < lakeSizes.size(); i++) {
            if (i > 0)
                sb.append(' ');
            sb.append(lakeSizes.get(i));
        }

        sb.append('\n');

        System.out.println(sb.toString());
    }
}