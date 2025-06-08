import java.io.*;
import java.util.*;

public class Main
{
    private static boolean isSafe(int i, double Y, int[] scores, int N, double X) {
        double Si = scores[i] + X * Y;
        double remainingVotes = 1.0 - Y;
        double need = 0.0;

        for (int j = 0; j < N; ++j) {
            if (j == i) continue;
            if (scores[j] >= Si) continue;
            double yj = (Si - scores[j]) / X;
            if (yj < 0) yj = 0;
            need += yj;
        }

        return need > remainingVotes;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; ++tc) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int[] scores = new int[N];
            double X = 0;
            for (int i = 0; i < N; ++i) {
                scores[i] = Integer.parseInt(st.nextToken());
                X += scores[i];
            }

            double[] results = new double[N];
            for (int i = 0; i < N; ++i) {
                double lo = 0.0, hi = 1.0;
                for (int iter = 0; iter < 100; ++iter) {
                    double mid = (lo + hi) / 2;
                    if (isSafe(i, mid, scores, N, X)) {
                        hi = mid;
                    } else {
                        lo = mid;
                    }
                }

                results[i] = hi * 100;
            }

            System.out.print("Case #" + tc + ":");
            for (int i = 0; i < N; ++i) {
                System.out.printf(" %.6f", results[i]);
            }

            System.out.println();
        }
    }
}