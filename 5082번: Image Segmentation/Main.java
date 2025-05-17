import java.io.*;
import java.util.*;

public class Main {
    static int H, W, S, L;
    static int[][][] image;
    static boolean[][] visited;

    static final int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static final int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (true) {
            line = br.readLine();
            if (line == null)
                break;
            String[] header = line.trim().split(" ");
            H = Integer.parseInt(header[0]);
            W = Integer.parseInt(header[1]);
            S = Integer.parseInt(header[2]);
            L = Integer.parseInt(header[3]);
            if (H == 0 && W == 0 && S == 0 && L == 0)
                break;

            image = new int[H][W][3];
            visited = new boolean[H][W];

            for (int i = 0; i < H; i++) {
                int idx = 0;
                String[] pixelLine;

                while (true) {
                    pixelLine = br.readLine().trim().split(" ");
                    if (pixelLine.length == 0)
                        continue;
                    break;
                }
                for (int j = 0; j < W; j++) {
                    int r = Integer.parseInt(pixelLine[idx++]);
                    int g = Integer.parseInt(pixelLine[idx++]);
                    int b = Integer.parseInt(pixelLine[idx++]);
                    image[i][j][0] = r / S;
                    image[i][j][1] = g / S;
                    image[i][j][2] = b / S;
                }
            }

            int areaCount = solve();
            System.out.println(areaCount);
        }
    }

    static int solve() {
        int areas = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!visited[i][j]) {
                    int areaSize = bfs(i, j, image[i][j]);
                    if (areaSize >= L)
                        areas++;
                }
            }
        }

        return areas;
    }

    static int bfs(int x, int y, int[] band) {
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[] { x, y });
        visited[x][y] = true;
        int cnt = 1;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cx = cur[0], cy = cur[1];
            for (int d = 0; d < 8; d++) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;
                if (visited[nx][ny])
                    continue;
                if (Arrays.equals(image[nx][ny], band)) {
                    visited[nx][ny] = true;
                    q.offer(new int[] { nx, ny });
                    cnt++;
                }
            }
        }

        return cnt;
    }
}