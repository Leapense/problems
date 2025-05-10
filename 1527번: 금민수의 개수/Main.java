import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static final long LIMIT = 1_000_000_000L;
    private static final List<Long> lucky = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        dfs(0L);
        Collections.sort(lucky);

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long A = Long.parseLong(st.nextToken());
        long B = Long.parseLong(st.nextToken());

        int left = lowerBound(lucky, A);
        int right = upperBound(lucky, B);

        System.out.println(right - left);
    }

    private static void dfs(long current) {
        if (current != 0)
            lucky.add(current);
        if (current > LIMIT)
            return;

        if (current == 0) {
            dfs(4);
            dfs(7);
        } else {
            long next4 = current * 10 + 4;
            long next7 = current * 10 + 7;
            if (next4 <= LIMIT)
                dfs(next4);
            if (next7 <= LIMIT)
                dfs(next7);
        }
    }

    private static int lowerBound(List<Long> list, long key) {
        int lo = 0, hi = list.size();
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (list.get(mid) < key)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }

    private static int upperBound(List<Long> list, long key) {
        int lo = 0, hi = list.size();
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (list.get(mid) <= key)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
}