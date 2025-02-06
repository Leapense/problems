import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] applause = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                applause[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int A = Integer.parseInt(br.readLine().trim());

        int[] colSum = new int[M];
        for (int j = 0; j < M; j++) {
            int sum = 0;
            for (int i = 0; i < N; i++) {
                sum += applause[i][j];
            }
            colSum[j] = sum;
        }

        long currentSum = 0;
        for (int j = 0; j < A; j++) {
            currentSum += colSum[j];
        }

        long maxSum = currentSum;

        for (int j = 1; j <= M - A; j++) {
            currentSum = currentSum - colSum[j - 1] + colSum[j + A - 1];
            maxSum = Math.max(maxSum, currentSum);
        }

        out.println(maxSum);
        out.flush();
        out.close();
    }
}