import java.io.*;
import java.util.*;

public class Main {
    public static void main(String... args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        String s = in.readLine();
        int L = n / m;

        HashMap<String, Deque<Integer>> map = new HashMap<>(m * 2);
        for (int i = 1; i <= m; i++) {
            String t = in.readLine();
            map.computeIfAbsent(t, k -> new ArrayDeque<>()).addLast(i);
        }

        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        for (int j = 0; j < m; j++) {
            String block = s.substring(j * L, j * L + L);
            Deque<Integer> q = map.get(block);
            out.print(q.removeFirst());
            if (j + 1 < m)
                out.print(' ');
        }

        out.println();
        out.flush();
    }
}