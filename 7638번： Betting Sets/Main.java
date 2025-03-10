import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            if (N == 0 && M == 0)
                break;
            double[][] cols = new double[M][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    double value = sc.nextDouble();
                    cols[j][i] = value;
                }
            }

            for (int j = 0; j < M; j++) {
                Arrays.sort(cols[j]);
                for (int i = 0; i < N / 2; i++) {
                    double temp = cols[j][i];
                    cols[j][i] = cols[j][N - i - 1];
                    cols[j][N - i - 1] = temp;
                }
            }

            double result = 0.0;
            for (int i = 0; i < N; i++) {
                double prod = 1.0;
                for (int j = 0; j < M; j++) {
                    prod *= cols[j][i];
                }
                result += prod;
            }
            System.out.printf("%.4f\n", result);
        }
        sc.close();
    }
}