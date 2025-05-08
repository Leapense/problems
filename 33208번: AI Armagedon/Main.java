import java.io.*;
import java.util.*;

public class Main {
    static class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int len, ptr;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        int readByte() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0)
                    return -1;
            }

            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c, sign = 1, val = 0;
            do {
                c = readByte();
            } while (c <= ' ');

            if (c == '-') {
                sign = -1;
                c = readByte();
            }
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = readByte();
            }

            return val * sign;
        }
    }

    static class Node {
        int next, color;

        Node(int n, int c) {
            next = n;
            color = c;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int N = fs.nextInt();
        int K = fs.nextInt();

        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = fs.nextInt();
        }

        int[] tmp = a.clone();
        Arrays.sort(tmp);
        int m = 0;

        for (int i = 0; i < N; i++) {
            if (i == 0 || tmp[i] != tmp[i - 1])
                tmp[m++] = tmp[i];
        }

        if (m < K) {
            System.out.println(0);
            return;
        }
        int[] comp = Arrays.copyOf(tmp, m);

        for (int i = 0; i < N; i++) {
            a[i] = Arrays.binarySearch(comp, a[i]);
        }
        int INF = N;
        int[] nextPos = new int[N];
        int[] last = new int[m];

        Arrays.fill(last, INF);
        for (int i = N - 1; i >= 0; i--) {
            int c = a[i];
            nextPos[i] = last[c];
            last[c] = i;
        }

        int[] first = new int[m];
        Arrays.fill(first, -1);
        for (int i = 0; i < N; i++) {
            if (first[a[i]] == -1)
                first[a[i]] = i;
        }

        int[] next = new int[m];
        System.arraycopy(first, 0, next, 0, m);

        PriorityQueue<Node> pq = new PriorityQueue<>((x, y) -> Integer.compare(y.next, x.next));

        for (int c = 0; c < m; c++) {
            pq.add(new Node(next[c], c));
        }

        int script = pq.peek().color;
        long moves = 0;

        for (int i = 0; i < N; i++) {
            int col = a[i];
            if (script == col) {
                moves++;
                while (true) {
                    Node top = pq.poll();
                    if (top == null)
                        throw new RuntimeException();
                    if (top.color == col)
                        continue;
                    if (next[top.color] != top.next)
                        continue;
                    script = top.color;
                    break;
                }
            }

            next[col] = nextPos[i];
            pq.add(new Node(next[col], col));
        }

        System.out.println(moves);
    }
}