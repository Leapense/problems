import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        long p = Long.parseLong(st.nextToken());

        long[] z = new long[n];
        long[] a = new long[n];
        long[] b = new long[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            z[i] = Long.parseLong(st.nextToken());
            a[i] = Long.parseLong(st.nextToken());
            b[i] = Long.parseLong(st.nextToken());
        }
        long low = 0, high = (long)2e12;

        while (low < high) {
            long mid = low + (high - low) / 2;
            if (totalPower(mid, n, z, a, b) >= p) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        System.out.println(low);
    }

    private static long totalPower(long x, int n, long[] z, long[] a, long[] b) {
        long sum = 0;
        for (int i = 0; i < n; i++) {
            if (x <= z[i]) {
                sum += a[i] * x;
            } else {
                sum += a[i] * z[i] + b[i] * (x - z[i]);
            }
            // 오버플로 방지: 이미 충분히 커졌으면 바로 반환
            if (sum < 0) return Long.MAX_VALUE;
        }
        return sum;
    }
}
