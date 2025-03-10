import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static void rec(int pos, int limit, int offset, long cur, Map<Long, Long> map) {
        if (pos == limit) {
            map.put(cur, map.getOrDefault(cur, 0L) + 1);
            return;
        }
        rec(pos + 1, limit, offset, cur - (1L << (offset + pos)), map);
        rec(pos + 1, limit, offset, cur, map);
        rec(pos + 1, limit, offset, cur + (1L << (offset + pos)), map);
    }

    public static void main(String... args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        StringTokenizer st;

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            long maxVal = (1L << n) - 1;
            if (Math.abs(x) > maxVal) {
                out.println(0);
                continue;
            }

            int k = n / 2;
            int r = n - k;

            Map<Long, Long> map1 = new HashMap<>();
            Map<Long, Long> map2 = new HashMap<>();
            rec(0, k, 0, 0, map1);
            rec(0, r, k, 0, map2);
            long ans = 0;
            for (Map.Entry<Long, Long> entry : map1.entrySet()) {
                long need = x - entry.getKey();
                if (map2.containsKey(need)) {
                    ans += entry.getValue() * map2.get(need);
                }
            }
            out.println(ans);
        }

        out.flush();
    }
}