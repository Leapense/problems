import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    static class Node {
        int d1, d2;

        Node(int d1, int d2) {
            this.d1 = d1;
            this.d2 = d2;
        }
    }

    static Map<Integer, Node> tree = new HashMap<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int P = sc.nextInt();
        for (int i = 1; i <= P - 1; i++) {
            int cn = sc.nextInt();
            int d1 = sc.nextInt();
            int d2 = sc.nextInt();
            tree.put(cn, new Node(d1, d2));
        }

        System.out.println(dfs(1));
    }

    static int dfs(int node) {
        Node cur = tree.get(node);
        int left = cur.d1 == 0 ? 1 : dfs(cur.d1) + 1;
        int right = cur.d2 == 0 ? 1 : dfs(cur.d2) + 1;
        return Math.max(left, right);
    }
}