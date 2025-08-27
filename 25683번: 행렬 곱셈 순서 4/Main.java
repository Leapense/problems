import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        int[] dims = new int[n + 1];

        StringTokenizer st = new StringTokenizer(reader.readLine());
        dims[0] = Integer.parseInt(st.nextToken());
        dims[1] = Integer.parseInt(st.nextToken());

        for(int i = 2; i <= n; i++) {
            st = new StringTokenizer(reader.readLine());
            st.nextToken();
            dims[i] = Integer.parseInt(st.nextToken());
        }

        long totalCost = 0;
        if (n > 1) {
            long lastColDim = dims[n];
            for (int i = 1; i < n; i++) {
                long cost = (long) dims[i - 1] * dims[i] * lastColDim;
                totalCost += cost;
            }
            long firstMultiplicationCost = (long) dims[n - 2] * dims[n - 1] * dims[n];
            totalCost = firstMultiplicationCost;

            for (int i = n - 2; i >= 1; i--) {
                long cost = (long) dims[i - 1] * dims[i] * lastColDim;
                totalCost += cost;
            }
        }

        System.out.println(totalCost);
    }
}