import java.io.*;
import java.util.*;

public class Main {
    private static final int[] DR = { -1, 1, 0, 0 };
    private static final int[] DC = { 0, 0, -1, 1 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        char[][] map = new char[R][C];
        boolean[][] vis = new boolean[R][C];

        int sr = -1, sc = -1;

        for (int i = 0; i < R; i++) {
            String line = br.readLine();
            map[i] = line.toCharArray();
            int idx = line.indexOf('S');
            if (idx != -1) {
                sr = i;
                sc = idx;
            }
        }

        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[] { sr, sc });
        vis[sr][sc] = true;
        int cnt = 0;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            cnt++;
            for (int d = 0; d < 4; d++) {
                int nr = cur[0] + DR[d];
                int nc = cur[1] + DC[d];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                    continue;
                if (vis[nr][nc])
                    continue;
                if (map[nr][nc] == '.')
                    continue;
                vis[nr][nc] = true;
                q.add(new int[] { nr, nc });
            }
        }

        System.out.println(cnt);
    }
}