import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        long maxPaths = n + m - 3L;

        if (k > maxPaths) {
            System.out.println("NO");
            return;
        }
        System.out.println("YES");

        if (k == 0) {
            for (int i = 0; i < n; i++) {
                System.out.println(".".repeat(m));
            }

            return;
        }

        List<long[]> diag = new ArrayList<>();
        for (int s = 3; s <= n + m - 1; s++) {
            long len = Math.min(Math.min(s - 1, n), Math.min(m, n + m + 1 - s));
            diag.add(new long[]{len, s});
        }
        diag.sort(Comparator.comparingLong(a -> a[0]));
        Set<Integer> blockS = new HashSet<>();
        for (int i = 0; i < k; i++) {
            blockS.add((int)diag.get(i)[1]);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int s = i + j;
                if ((i == 1 && j == 1) || (i == n && j == m)) {
                    sb.append('.');
                } else if (blockS.contains(s)) {
                    sb.append('C');
                } else {
                    sb.append('.');
                }
            }
            sb.append('\n');
        }
        System.out.print(sb);
    }
}
