import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    private static char[] pattern;

    private static boolean valid(int l, int r) {
        if (l >= r)
            return true;

        int mid = (l + r) >> 1;

        for (int i = 1; mid - i >= l; i++) {
            if (pattern[mid - i] == pattern[mid + i]) {
                return false;
            }
        }

        return valid(l, mid - 1) && valid(mid + 1, r);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        int T = Integer.parseInt(br.readLine().trim());

        while (T-- > 0) {
            pattern = br.readLine().trim().toCharArray();
            boolean ok = valid(0, pattern.length - 1);
            out.append(ok ? "YES" : "NO").append('\n');
        }

        System.out.print(out.toString());
    }
}