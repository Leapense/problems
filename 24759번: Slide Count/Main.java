import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long c = Long.parseLong(st.nextToken());

        int[] weights = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            weights[i] = Integer.parseInt(st.nextToken());
        }

        int[] delta = new int[n + 2];
        int start = 1;
        int end = 1;
        long currentSum = 0;
        if (n > 0) {
            currentSum = weights[0];
        }
        while(start <= n) {
            if (start <= end) {
                delta[start]++;
                delta[end + 1]--;
            }
            if (end + 1 > n) {
                currentSum -= weights[start - 1];
                start++;
            } else if (currentSum + weights[end] > c) {
                currentSum -= weights[start - 1];
                start++;
            } else {
                currentSum += weights[end];
                end++;
            }
        }

        StringBuilder sb = new StringBuilder();
        long currentCount = 0;
        for (int i = 1; i <= n; i++) {
            currentCount += delta[i];
            sb.append(currentCount).append("\n");
        }

        System.out.print(sb.toString());
    }
}