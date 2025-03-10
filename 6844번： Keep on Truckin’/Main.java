import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int N = sc.nextInt();
        ArrayList<Integer> motels = new ArrayList<>();
        int[] base = { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000 };

        for (int x : base) {
            motels.add(x);
        }
        for (int i = 0; i < N; i++) {
            motels.add(sc.nextInt());
        }

        Collections.sort(motels);
        int size = motels.size();
        long[] dp = new long[size];
        dp[0] = 1;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int diff = motels.get(j) - motels.get(i);
                if (diff >= A && diff <= B)
                    dp[j] += dp[i];
                else if (diff > B)
                    break;
            }
        }

        System.out.println(dp[size - 1]);
    }
}