import java.util.*;

public class Main {
    static int N, target;
    static char[][] pref;
    static int[] ans;
    static boolean found = false;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            N = sc.nextInt();
            target = sc.nextInt();
            pref = new char[N][N];

            for (int i = 0; i < N; i++) {
                pref[i] = sc.next().toCharArray();
            }

            ans = new int[N];
            found = false;
            boolean[] used = new boolean[N];
            ArrayList<Integer> order = new ArrayList<>();
            for (int i = 0; i < N && !found; i++) {
                order.clear();
                Arrays.fill(used, false);
                order.add(i);
                used[i] = true;
                rec(order, used, i);
            }
            System.out.print("Case #" + t + ":");

            if (!found) {
                System.out.println(" IMPOSSIBLE");
            } else {
                for (int x : ans) {
                    System.out.print(" " + x);
                }
                System.out.println();
            }
        }
        sc.close();
    }

    static void rec(ArrayList<Integer> order, boolean[] used, int current) {
        if (found)
            return;
        if (order.size() == N) {
            if (current == target) {
                for (int i = 0; i < N; i++) {
                    ans[i] = order.get(i);
                }
                found = true;
            }

            return;
        }

        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                used[i] = true;
                order.add(i);
                int newCurrent = (pref[current][i] == 'Y') ? current : i;
                rec(order, used, newCurrent);
                if (found)
                    return;

                order.remove(order.size() - 1);
                used[i] = false;
            }
        }
    }
}