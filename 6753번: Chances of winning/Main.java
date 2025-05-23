import java.util.*;

public class Main {
    static int T;
    static int ans = 0;
    static int[] score = new int[5];
    static ArrayList<int[]> games = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        int G = sc.nextInt();
        boolean[][] played = new boolean[5][5];
        for (int i = 0; i < G; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int sa = sc.nextInt();
            int sb = sc.nextInt();
            played[a][b] = true;
            if (sa > sb) {
                score[a] += 3;
            } else if (sa < sb) {
                score[b] += 3;
            } else {
                score[a] += 1;
                score[b] += 1;
            }
        }

        for (int i = 1; i <= 3; i++) {
            for (int j = i + 1; j <= 4; j++) {
                if (!played[i][j]) {
                    games.add(new int[] { i, j });
                }
            }
        }
        dfs(0);
        System.out.println(ans);
    }

    static void dfs(int idx) {
        if (idx == games.size()) {
            if (check())
                ans++;
            return;
        }

        int a = games.get(idx)[0];
        int b = games.get(idx)[1];

        score[a] += 3;
        dfs(idx + 1);
        score[a] -= 3;
        score[b] += 3;
        dfs(idx + 1);
        score[b] -= 3;
        score[a] += 1;
        score[b] += 1;
        dfs(idx + 1);
        score[a] -= 1;
        score[b] -= 1;
    }

    static boolean check() {
        for (int i = 1; i <= 4; i++) {
            if (i == T)
                continue;
            if (score[T] <= score[i])
                return false;
        }

        return true;
    }
}