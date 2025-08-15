import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;

public class Main {
    private static int n;
    private static int[] a;
    private static int[] b;
    private static int mismatchCount;
    private static boolean matched;

    public static void main(String[] args) throws Exception {
        FastScanner scanner = new FastScanner(System.in);
        n = scanner.nextInt();
        a = new int[n];
        b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt();
        }
        
        mismatchCount = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                mismatchCount++;
            }
        }

        if (mismatchCount == 0) {
            System.out.println(1);
            return;
        }

        quickSortIterative(0, n - 1);
        System.out.println(matched ? 1 : 0);
    }

    private static void quickSortIterative(int p, int r) {
        ArrayDeque<int[]> stack = new ArrayDeque<>();
        stack.addLast(new int[]{p, r});
        while (!stack.isEmpty() && !matched) {
            int[] seg = stack.pollLast();
            int left = seg[0];
            int right = seg[1];
            if (left < right) {
                int q = partition(left, right);
                if (matched) {
                    break;
                }
                if (q + 1 < right) {
                    stack.addLast(new int[]{q + 1, right});
                }
                if (left < q - 1) {
                    stack.addLast(new int[]{left, q - 1});
                }
            }
        }
    }

    private static int partition(int p, int r) {
        int x = a[r];
        int i = p - 1;
        for (int j = p; j <= r - 1; j++) {
            if (a[j] <= x) {
                i++;
                swapAndCheck(i, j);
                if (matched) {
                    return -1;
                }
            }
        }
        if (i + 1 != r) {
            swapAndCheck(i + 1, r);
            if (matched) {
                return -1;
            }
        }

        return i + 1;
    }

    private static void swapAndCheck(int i, int j) {
        int before = 0;
        if (a[i] != b[i]) {
            before++;
        }
        if (i != j && a[j] != b[j]) {
            before++;
        }
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;

        int after = 0;
        if (a[i] != b[i]) {
            after++;
        }
        if (i != j && a[j] != b[j]) {
            after++;
        }

        mismatchCount += (after - before);
        if (mismatchCount == 0) {
            matched = true;
        }
    }

    private static final class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0;
        private int len = 0;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) {
                    return -1;
                }
            }

            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c;
            do { 
                c = read();
            } while (c <= 32);
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            int val = 0;
            while (c > 32) {
                val = val * 10 + (c - '0');
                c = read();
            }

            return val * sign;
        }
    }
}