import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static long levelAfterKills(long n) {
        long s = 1 + 2L * n * (n + 1);
        long r = (long) Math.sqrt(s);
        while ((r + 1) * (r + 1) <= s)
            ++r;
        while (r * r > s)
            --r;
        return (1 + r) >> 1;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            long n = Long.parseLong(br.readLine().trim());
            sb.append(levelAfterKills(n)).append('\n');
        }

        System.out.print(sb.toString());
    }
}