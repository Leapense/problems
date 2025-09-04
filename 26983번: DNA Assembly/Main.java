import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int overlap(String a, String b) {
        int max = Math.min(a.length(), b.length());
        for (int k = max; k >= 1; k--) {
            boolean ok = true;
            for (int i = 0; i < k; i++) {
                if (a.charAt(a.length() - k + i) != b.charAt(i)) {
                    ok = false;
                    break;
                }
            }
            if (ok) return k;
        }

        return 0;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        List<String> raw = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String s = br.readLine().trim();
            raw.add(s);
        }

        LinkedHashSet<String> dedup = new LinkedHashSet<>(raw);
        List<String> strs = new ArrayList<>(dedup);

        int m = strs.size();
        boolean[] removed = new boolean[m];
        for (int i = 0; i < m; i++) {
            if (removed[i]) continue;
            for (int j = 0; j < m; j++) {
                if (i == j || removed[j]) continue;
                if (strs.get(i).contains(strs.get(j))) {
                    removed[j] = true;
                }
            }
        }

        List<String> sList = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            if (!removed[i]) sList.add(strs.get(i));
        }

        int sz = sList.size();
        if (sz == 0) {
            System.out.println(0);
            return;
        }
        if (sz == 1) {
            System.out.println(sList.get(0).length());
            return;
        }

        int[] len = new int[sz];
        for (int i = 0; i < sz; i++) len[i] = sList.get(i).length();

        int[][] ov = new int[sz][sz];
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (i == j) continue;
                ov[i][j] = overlap(sList.get(i), sList.get(j));
            }
        }

        int full = 1 << sz;
        int[][] dp = new int[full][sz];
        int inf = 1_000_000;
        for (int i = 0; i < full; i++) Arrays.fill(dp[i], inf);
        for (int i = 0; i < sz; i++) dp[1 << i][i] = len[i];
        for (int mask = 0; mask < full; mask++) {
            for (int last = 0; last < sz; last++) {
                if (dp[mask][last] == inf) continue;
                for (int nxt = 0; nxt < sz; nxt++) {
                    if ((mask & (1 << nxt)) != 0) continue;
                    int nmask = mask | (1 << nxt);
                    int add = len[nxt] - ov[last][nxt];
                    int val = dp[mask][last] + add;
                    if (val < dp[nmask][nxt]) dp[nmask][nxt] = val;
                }
            }
        }

        int ans = inf;
        for (int last = 0; last < sz; last++) ans = Math.min(ans, dp[full - 1][last]);
        System.out.println(ans);
    }
}