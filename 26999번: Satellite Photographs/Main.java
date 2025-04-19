import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    private static final int[] DX = {1, -1, 0, 0};
    private static final int[] DY = {0, 0, 1, -1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int W = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());

        char[][] grid = new char[H][W];
        for (int r = 0; r < H; r++) {
            String line = br.readLine();
            grid[r] = line.toCharArray();     // 길이 W 보장
        }

        boolean[][] visited = new boolean[H][W];
        int maxArea = 0;

        ArrayDeque<int[]> q = new ArrayDeque<>();
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (grid[y][x] == '*' && !visited[y][x]) {
                    visited[y][x] = true;
                    q.clear();
                    q.add(new int[]{y, x});
                    int area = 0;

                    while (!q.isEmpty()) {
                        int[] cur = q.poll();
                        area++;

                        for (int dir = 0; dir < 4; dir++) {
                            int ny = cur[0] + DY[dir];
                            int nx = cur[1] + DX[dir];

                            if (0 <= ny && ny < H && 0 <= nx && nx < W &&
                                    grid[ny][nx] == '*' && !visited[ny][nx]) {
                                visited[ny][nx] = true;
                                q.add(new int[]{ny, nx});
                            }
                        }
                    }
                    if (area > maxArea) maxArea = area;
                }
            }
        }
        System.out.println(maxArea);
    }
}
