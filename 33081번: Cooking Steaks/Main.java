import java.io.*;
import java.util.*;

public class Main {
    static class Pair {
        int level;
        long count;
        Pair(int l, long c) {
            level = l;
            count = c;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine().trim());
        
        long[] T = new long[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N - 1; i++) T[i] = Long.parseLong(st.nextToken());

        long[] A = new long[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) A[i] = Long.parseLong(st.nextToken());
        
        long[] B = new long[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) B[i] = Long.parseLong(st.nextToken());

        long[] P = new long[N + 1];
        for (int i = 1; i <= N - 1; i++) P[i] = P[i - 1] + T[i];

        Deque<Pair> stack = new ArrayDeque<>();
        long ans = 0;

        for (int j = 1; j <= N; j++) {
            long need = B[j] - A[j];
            if (need > 0) {
                while (need > 0 && !stack.isEmpty()) {
                    Pair top = stack.peekLast();
                    int lvl = top.level;
                    long cnt = top.count;
                    long take = Math.min(cnt, need);
                    ans += take * (P[j - 1] - P[lvl - 1]);

                    need -= take;
                    cnt -= take;

                    if (cnt == 0) stack.pollLast();
                    else top.count = cnt;
                }

                if (need > 0) {
                    System.out.println(-1);
                    return;
                }
            } else if (need < 0) {
                stack.addLast(new Pair(j, -need));
            }
        }

        System.out.println(ans);
    }
}