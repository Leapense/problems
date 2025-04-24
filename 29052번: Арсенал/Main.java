import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] a = new int[n + 2];
        for (int i = 1; i <= n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int maxH = 1000;
        List<int[]>[] runsByHeight = new ArrayList[maxH + 1];
        for (int h = 0; h <= maxH; h++)
            runsByHeight[h] = new ArrayList<>();

        for (int i = 1; i <= n;) {
            int h = a[i], j = i + 1;
            while (j <= n && a[j] == h)
                j++;
            runsByHeight[h].add(new int[] { i, j - 1 });
            i = j;
        }

        List<Integer> heights = new ArrayList<>();
        for (int h = 0; h <= maxH; h++) {
            if (!runsByHeight[h].isEmpty()) {
                heights.add(h);
            }
        }

        heights.sort(Comparator.reverseOrder());

        List<Integer> order = new ArrayList<>(n);
        long minInconvenient = 0;

        for (int h : heights) {
            for (int[] run : runsByHeight[h]) {
                int L = run[0], R = run[1], len = R - L + 1;
                minInconvenient += (len / 2);
                for (int idx = L; idx <= R; idx++) {
                    int offset = idx - L + 1;
                    if (offset % 2 == 0) {
                        order.add(idx);
                    }
                }
                for (int idx = L; idx <= R; idx++) {
                    int offset = idx - L + 1;
                    if (offset % 2 == 1) {
                        order.add(idx);
                    }
                }
            }
        }

        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        pw.println(minInconvenient);
        for (int i = 0; i < n; i++) {
            if (i > 0)
                pw.print(' ');
            pw.print(order.get(i));
        }

        pw.println();
        pw.flush();
    }
}