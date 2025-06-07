import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public final class Main
{
    private Main() {}

    public static void main(final String... args) throws Exception {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            final int t = Integer.parseInt(br.readLine().trim());
            final StringBuilder out = new StringBuilder();

            for (int cs = 1; cs <= t; cs++) {
                final StringTokenizer st = new StringTokenizer(br.readLine());
                final int k = Integer.parseInt(st.nextToken());
                final int l = Integer.parseInt(st.nextToken());
                final int s = Integer.parseInt(st.nextToken());

                final String keyboard = br.readLine().trim();
                final String target = br.readLine().trim();

                final double answer = solveCase(k, l, s, keyboard, target);
                out.append("Case #").append(cs).append(": ").append(String.format("%.7f", answer)).append("\n");
            }

            System.out.print(out.toString());
        }
    }

    private static double solveCase(final int k, final int l, final int s, final String keyboard, final String target) {
        final int[] freq = new int[26];
        for (int i = 0; i < k; i++) {
            freq[keyboard.charAt(i) - 'A']++;
        }

        double pWord = 1.0;
        for (int i = 0; i < l; i++) {
            final int idx = target.charAt(i) - 'A';
            if (freq[idx] == 0) {
                return 0.0;
            }

            pWord *= (double) freq[idx] / k;
        }

        final int positions = s - l + 1;
        final double expected = positions * pWord;

        final int border = longestBorder(target);
        final int step = l - border;
        final int maxOcc = 1 + (s - l) / step;

        return Math.max(0.0, maxOcc - expected);
    }

    private static int longestBorder(final String pattern) {
        final int n = pattern.length();
        final int[] pi = new int[n];
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) {
                j = pi[j - 1];
            }
            if (pattern.charAt(i) == pattern.charAt(j)) {
                j++;
                pi[i] = j;
            }
        }
        return pi[n - 1];
    }
}