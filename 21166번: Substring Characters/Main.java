import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    private static final int LOWER_OFFSET = 0;
    private static final int UPPER_OFFSET = 26;
    private static final int DIGIT_OFFSET = 52;

    private static int idx(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return ch - 'a' + LOWER_OFFSET;
        }
        if (ch >= 'A' && ch <= 'Z') {
            return ch - 'A' + UPPER_OFFSET;
        }
        return ch - '0' + DIGIT_OFFSET;
    }

    private static long mask(String s, int l, int r) {
        long m = 0L;
        for (int i = l; i <= r; i++) {
            m |= 1L << idx(s.charAt(i));
        }
        return m;
    }

    private static int solve(String s) {
        int n = s.length();
        if (n <= 1) {
            return 0;
        }
        long full = mask(s, 0, n - 1);
        Set<String> set = new HashSet<>();
        for (int l = 0; l < n - 1; l++) {
            for (int r = l; r < n; r++) {
                if (l == 0 && r == n - 1) {
                    continue;
                }
                long cur = mask(s, l, r);
                if (cur != full) {
                    continue;
                }
                boolean leftTrimOk = l + 1 <= r && mask(s, l + 1, r) == full;
                if (leftTrimOk) {
                    continue;
                }
                boolean rightTrimOk = l <= r - 1 && mask(s, l, r - 1) == full;
                if (rightTrimOk) {
                    continue;
                }
                set.add(s.substring(l, r + 1));
            }
        }
        return set.size();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String line;
        while ((line = br.readLine()) != null) {
            sb.append(solve(line)).append('\n');
        }
        System.out.print(sb.toString());
    }
}