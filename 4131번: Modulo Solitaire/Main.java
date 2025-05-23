import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int s0 = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }

        boolean[] visited = new boolean[m];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] { s0, 0 });
        visited[s0] = true;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int state = cur[0];
            int moves = cur[1];
            if (state == 0) {
                System.out.println(moves);
                return;
            }

            for (int i = 0; i < n; i++) {
                int next = (int) (((long) state * a[i] + b[i]) % m);
                if (!visited[next]) {
                    visited[next] = true;
                    queue.offer(new int[] { next, moves + 1 });
                }
            }
        }

        System.out.println(-1);
    }
}