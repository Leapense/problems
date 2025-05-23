import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        Set<String> elements = new HashSet<>();
        String[] elementSymbols = {
                "h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar", "k",
                "ca",
                "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb",
                "sr", "y", "zr",
                "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "la",
                "ce", "pr", "nd",
                "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "hf", "ta", "w", "re", "os", "ir",
                "pt", "au", "hg",
                "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk",
                "cf", "es", "fm",
                "md", "no", "lr", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv"
        };

        for (String s : elementSymbols) {
            elements.add(s);
        }

        StringBuilder sb = new StringBuilder();
        for (int t = 0; t < T; t++) {
            String word = br.readLine().toLowerCase();
            int n = word.length();
            boolean[] dp = new boolean[n + 1];
            dp[0] = true;
            for (int i = 0; i < n; i++) {
                if (!dp[i])
                    continue;
                if (i + 1 <= n && elements.contains(word.substring(i, i + 1))) {
                    dp[i + 1] = true;
                }
                if (i + 2 <= n && elements.contains(word.substring(i, i + 2))) {
                    dp[i + 2] = true;
                }
            }
            sb.append(dp[n] ? "YES" : "NO").append("\n");
        }

        System.out.print(sb);
    }
}