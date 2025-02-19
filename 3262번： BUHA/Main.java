import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt(), B = sc.nextInt(), K = sc.nextInt();
        List<Bomb> bombs = new ArrayList<>();

        for (int i = 0; i < K; i++) {
            int R = sc.nextInt(), S = sc.nextInt(), P = sc.nextInt(), T = sc.nextInt();
            bombs.add(new Bomb(R, S, P, T));
        }
        int count = 0;
        for (int i = 1; i <= A; i++) {
            for (int j = 1; j <= B; j++) {
                boolean valid = true;
                for (Bomb bomb : bombs) {
                    int half = (bomb.P - 1) / 2;
                    int r1 = Math.max(1, bomb.R - half);
                    int r2 = Math.min(A, bomb.R + half);
                    int c1 = Math.max(1, bomb.S - half);
                    int c2 = Math.min(B, bomb.S + half);
                    boolean inRange = (i >= r1 && i <= r2 && j >= c1 && j <= c2);

                    if (bomb.T == 1 && !inRange) {
                        valid = false;
                        break;
                    }
                    if (bomb.T == 0 && inRange) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    count++;
            }
        }

        System.out.println(count);
        sc.close();
    }

    static class Bomb {
        int R, S, P, T;

        public Bomb(int R, int S, int P, int T) {
            this.R = R;
            this.S = S;
            this.P = P;
            this.T = T;
        }
    }
}