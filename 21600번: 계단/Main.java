import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public final class Main {
    private static class SegmentTree {
        private final long[] tree;
        private final int size;

        SegmentTree(long[] src) {
            int n = src.length - 1;
            int pow = 1;
            while (pow < n) {
                pow <<= 1;
            }
            size = pow;
            tree = new long[size << 1];
            for (int i = 1; i <= n; i++) {
                tree[size + i - 1] = src[i];
            }
            for (int i = size - 1; i > 0; i--) {
                tree[i] = Math.min(tree[i << 1], tree[(i << 1) + 1]);
            }
        }

        long query(int l, int r) {
            long res = Long.MAX_VALUE;
            int left = l + size - 1;
            int right = r + size - 1;
            while (left <= right) {
                if ((left & 1) == 1) {
                    res = Math.min(res, tree[left]);
                    left++;
                }
                if ((right & 1) == 0) {
                    res = Math.min(res, tree[right]);
                    right--;
                }

                left >>= 1;
                right >>= 1;
            }
            return res;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        long[] d = new long[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            long height = Long.parseLong(st.nextToken());
            d[i] = height - i;
        }

        SegmentTree seg = new SegmentTree(d);
        int best = 0;

        for (int e = 1; e <= n; e++) {
            int lo = 1;
            int hi = e;
            int localBest = 0;
            while (lo <= hi) {
                int mid = (lo + hi) >>> 1;
                int s = e - mid + 1;
                long minD = seg.query(s, e);
                if (minD >= 1L - s) {
                    localBest = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if (localBest > best) {
                best = localBest;
            }
        }

        System.out.println(best);
    }
}
