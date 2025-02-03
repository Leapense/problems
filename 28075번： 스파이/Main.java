import java.util.Scanner;

public class Main {
    static int N, M;
    static int[][] score = new int[2][3];
    static int count = 0;

    public static void main(String... args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();

        for (int i = 0; i < 3; i++) {
            score[0][i] = sc.nextInt();
        }

        for (int i = 0; i < 3; i++) {
            score[1][i] = sc.nextInt();
        }

        dfs(0, -1, 0);
        System.out.println(count);
    }

    static void dfs(int day, int prev, int sum) {
        if (day == N) {
            if (sum >= M)
                count++;
            return;
        }

        for (int task = 0; task < 2; task++) {
            for (int loc = 0; loc < 3; loc++) {
                int add = score[task][loc];
                if (loc == prev)
                    add /= 2;
                dfs(day + 1, loc, sum + add);
            }
        }
    }
}