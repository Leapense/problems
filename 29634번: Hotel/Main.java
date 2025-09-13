import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static char[][] g;
    static int[][] starPS;
    static int[][] dotPS;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        g = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine().trim();
            for (int j = 0; j < m; j++) g[i][j] = s.charAt(j);
        }

        starPS = new int[n+1][m+1];
        dotPS = new int[n+1][m+1];
        buildPS();

        int best = -1;
        for (int r1 = 1; r1 <= n - 2; r1++) {
            for (int r2 = r1; r2 <= n - 2; r2++) {
                for (int c1 = 1; c1 <= m - 2; c1++) {
                    for (int c2 = c1; c2 <= m - 2; c2++) {
                        if (!hasCorridorBorder(r1, r2, c1, c2)) continue;
                        int area = (r2 - r1 + 1) * (c2 - c1 + 1);
                        if (area > best) best = area;
                    }
                }
            }
        }

        System.out.println(best);
    }

    static void buildPS() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int isStar = g[i-1][j-1] == '*' ? 1 : 0;
                int isDot = g[i-1][j-1] == '.' ? 1 : 0;
                starPS[i][j] = starPS[i-1][j] + starPS[i][j-1] - starPS[i-1][j-1] + isStar;
                dotPS[i][j] = dotPS[i-1][j] + dotPS[i][j-1] - dotPS[i-1][j-1] + isDot;
            }
        }
    }

    static boolean hasCorridorBorder(int r1, int r2, int c1, int c2) {
        if (r1 - 1 < 0 || r2 + 1 >= n || c1 - 1 < 0 || c2 + 1 >= m) return false;

        int h = r2 - r1 + 1;
        int w = c2 - c1 + 1;

        if (rectDots(r1, c1, r2, c2) != h * w) return false;

        if (rectStars(r1 - 1, c1, r1 - 1, c2) != w) return false;
        if (rectStars(r2 + 1, c1, r2 + 1, c2) != w) return false;

        if (rectStars(r1, c1 - 1, r2, c1 - 1) != h) return false;
        if (rectStars(r1, c2 + 1, r2, c2 + 1) != h) return false;

        return true;
    }

    static int rectStars(int r1, int  c1, int r2, int c2) {
        return query(starPS, r1, c1, r2, c2);
    }

    static int rectDots(int r1, int c1, int r2, int c2) {
        return query(dotPS, r1, c1, r2, c2);
    }

    static int query(int[][] ps, int r1, int c1, int r2, int c2) {
        int R1 = r1, C1 = c1, R2 = r2, C2 = c2;
        if (R1 > R2 || C1 > C2) return 0;
        R1++; C1++; R2++; C2++;
        return ps[R2][C2] - ps[R1-1][C2] - ps[R2][C1-1] + ps[R1-1][C1-1];
    }
}