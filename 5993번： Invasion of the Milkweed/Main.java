import java.io.*;
import java.util.*;

public class Main {
    static int X, Y, startX, startY;
    static char[][] field;
    static int[][] week;
    static int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());
        startX = Integer.parseInt(st.nextToken()) - 1;
        startY = Integer.parseInt(st.nextToken()) - 1;
        field = new char[Y][X];
        week = new int[Y][X];

        for (int i = 0; i < Y; i++) {
            String line = br.readLine();
            field[Y - 1 - i] = line.toCharArray();
        }

        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                week[i][j] = -1;
            }
        }

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] { startY, startX });
        week[startY][startX] = 0;
        int maxWeek = 0;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int cy = cur[0], cx = cur[1];
            for (int d = 0; d < 8; d++) {
                int ny = cy + dy[d];
                int nx = cx + dx[d];

                if (ny < 0 || ny >= Y || nx < 0 || nx >= X)
                    continue;
                if (field[ny][nx] == '*')
                    continue;
                if (week[ny][nx] != -1)
                    continue;
                week[ny][nx] = week[cy][cx] + 1;
                maxWeek = Math.max(maxWeek, week[ny][nx]);
                queue.offer(new int[] { ny, nx });
            }
        }

        System.out.println(maxWeek);
    }
}