import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine().trim();
        Solver solver = new Solver();
        int ans = solver.solve(s);
        System.out.println(ans);
    }
}

class Solver {
    public int solve(String s) {
        int n = s.length();
        String t1 = buildPattern(n, '+');
        String t2 = buildPattern(n, '-');
        int cost1 = countFlipIntervals(s, t1);
        int cost2 = countFlipIntervals(s, t2);

        return Math.min(cost1, cost2);
    }

    private String buildPattern(int n, char start) {
        StringBuilder sb = new StringBuilder(n);
        char cur = start;
        for (int i = 0; i < n; i++) {
            sb.append(cur);
            cur = (cur == '+') ? '-' : '+';
        }

        return sb.toString();
    }

    private int countFlipIntervals(String s, String t) {
        int count = 0;
        int n = s.length();
        int i = 0;

        while (i < n) {
            if (s.charAt(i) != t.charAt(i)) {
                count++;

                while (i < n && s.charAt(i) != t.charAt(i)) {
                    i++;
                }
            } else {
                i++;
            }
        }

        return count;
    }
}