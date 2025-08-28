import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String cStr = br.readLine().trim();
        BigDecimal c = new BigDecimal(cStr);
        BigDecimal cost = new BigDecimal("0.99");
        int purchasable = c.divide(cost, 0, RoundingMode.FLOOR).intValue();
        int k = Math.min(2, Math.max(0, purchasable));
        int n = Integer.parseInt(br.readLine().trim());
        int[] a = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int idx = 0;
        while (st.hasMoreTokens() && idx < n) {
            a[idx++] = Integer.parseInt(st.nextToken());
        }
        while (idx < n) {
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens() && idx < n) {
                a[idx++] = Integer.parseInt(st.nextToken());
            }
        }

        int left = 0;
        int zeros = 0;
        int maxLen = 0;
        int maxSolved = Integer.MIN_VALUE;
        for (int right = 0; right < n; right++) {
            if (a[right] == 0) zeros++;
            while (zeros > k) {
                if (a[left] == 0) zeros--;
                left++;
            }
            int len = right - left + 1;
            if (len > maxLen) maxLen = len;
            if (a[right] > maxSolved) maxSolved = a[right];
        }
        if (n == 0) maxSolved = 0;
        System.out.println(maxLen);
        System.out.println(maxSolved);
    }
}