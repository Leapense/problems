import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine();

        Map<String, Integer> index = new HashMap<>();
        index.put("A", 0);
        index.put("B", 1);
        index.put("C", 2);
        index.put("D", 3);

        int n = 4;

        double[][] P = new double[n][n];

        for (int i = 0; i < M; i++) {
            String[] input = scanner.nextLine().split(" ");
            int start = index.get(input[0]);
            int end = index.get(input[1]);
            double prob = Double.parseDouble(input[2]);
            P[start][end] = prob;
        }

        double[] state = {0.25, 0.25, 0.25, 0.25};

        for (int t = 0; t < T; t++) {
            double[] newState = new double[n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    newState[j] += state[i] * P[i][j];
                }
            }

            state = newState;
        }

        for (double prob : state) {
            System.out.printf("%.2f\n", prob * 100);
        }
        scanner.close();
    }
}