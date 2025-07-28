import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long k = Long.parseLong(st.nextToken());

        int[] inv = new int[n];
        for (int i = 0; i < n; i++) {
            int remain = n - 1 - i;
            int take = (int) Math.min(k, remain);
            inv[i] = take;
            k -= take;
        }

        List<Integer> pool = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            pool.add(i);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int idx = inv[i];
            sb.append(pool.remove(idx));
            if (i + 1 < n) {
                sb.append(' ');
            }
        }

        System.out.println(sb);
    }
}