import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        int N = Integer.parseInt(br.readLine().trim());
        st = new StringTokenizer(br.readLine());

        int maxH = 1_000_000;
        int[] freq = new int[maxH + 1];
        for (int i = 0; i < N; i++) {
            int h = Integer.parseInt(st.nextToken());
            freq[h]++;
        }

        long visibleSum = 0;
        for (int h = 1; h <= maxH; h++) {
            if (freq[h] > 0) {
                visibleSum += Math.min(freq[h], C);
            }
        }

        long capacity = 1L * R * C;
        long answer = Math.min(visibleSum, capacity);

        System.out.println(answer);
    }
}