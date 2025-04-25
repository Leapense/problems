import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        HashMap<Integer, Long> countMap = new HashMap<>(n * 2);

        for (int i = 0; i < n; i++) {
            long x = Long.parseLong(st.nextToken());
            int k = 0;

            while ((x & 1) == 0) {
                x >>= 1;
                k++;
            }

            countMap.merge((int) x, 1L << k, Long::sum);
        }

        long answer = 0;
        for (Map.Entry<Integer, Long> entry : countMap.entrySet()) {
            long b = entry.getKey();
            long S = entry.getValue();
            long h = Long.highestOneBit(S);
            long candidate = b * h;

            if (candidate > answer) {
                answer = candidate;
            }
        }

        System.out.println(answer);
    }
}