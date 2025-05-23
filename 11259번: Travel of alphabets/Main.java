import java.io.*;
import java.util.*;

public class Main {
    static int R, C, L;
    static char[][] grid;
    static long total = 0;
    static Set<String> unique = new HashSet<>();
    static int[] dx = { 0, -1, 0, 1 };
    static int[] dy = { -1, 0, 1, 0 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] parts = br.readLine().split(" ");
        R = Integer.parseInt(parts[0]);
        C = Integer.parseInt(parts[1]);
        L = Integer.parseInt(parts[2]);
        grid = new char[R][C];

        for (int i = 0; i < R; i++) {
            String line = br.readLine();
            grid[i] = line.toCharArray();
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (isForbidden(grid[i][j]))
                    continue;
                dfs(i, j, 1, new StringBuilder().append(grid[i][j]));
            }
        }

        System.out.println(total);
        System.out.println(unique.size());
    }

    static boolean isForbidden(char ch) {
        return ch == 'a' || ch == 'c' || ch == 'm';
    }

    static void dfs(int x, int y, int depth, StringBuilder word) {
        if (depth == L) {
            total++;
            unique.add(word.toString());
            return;
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;

            char next = grid[nx][ny];
            if (isForbidden(next))
                continue;
            int len = word.length();
            word.append(next);
            dfs(nx, ny, depth + 1, word);
            word.setLength(len);
        }
    }
}