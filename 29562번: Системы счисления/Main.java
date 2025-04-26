import java.io.*;
import java.util.*;

public class Main {
    static int B, C;
    static long[] digits;
    static int L;
    static Long[][][] memo;

    static long countBad(long x) {
        if (x == 0)
            return 0;
        long tmp = x;
        int len = 0;
        while (tmp > 0) {
            tmp /= B;
            len++;
        }

        digits = new long[len];
        tmp = x;
        for (int i = len - 1; i >= 0; --i) {
            digits[i] = tmp % B;
            tmp /= B;
        }
        L = len;
        memo = new Long[L][2][2];
        return dfs(0, 1, 1);
    }

    static long dfs(int pos, int tight, int leadZero) {
        if (pos == L)
            return leadZero == 1 ? 0 : 1;
        if (memo[pos][tight][leadZero] != null)
            return memo[pos][tight][leadZero];

        int maxDigit = (tight == 1) ? (int) digits[pos] : B - 1;
        long res = 0;

        for (int d = 0; d <= maxDigit; ++d) {
            int nextLead = (leadZero == 1 && d == 0) ? 1 : 0;
            if (nextLead == 0 && d >= C)
                continue;
            int nextTight = (tight == 1 && d == maxDigit) ? 1 : 0;
            res += dfs(pos + 1, nextTight, nextLead);
        }

        return memo[pos][tight][leadZero] = res;
    }

    static long countGood(long x) {
        return x - countBad(x);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        long lo = 1, hi = n;
        while (countGood(hi) < n)
            hi <<= 1;

        while (lo < hi) {
            long mid = (lo + hi) >>> 1;
            if (countGood(mid) >= n)
                hi = mid;
            else
                lo = mid + 1;
        }

        System.out.println(lo);
    }
}