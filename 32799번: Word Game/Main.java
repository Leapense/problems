import java.util.*;

public class Main {
    static String best;
    static int bestLen;
    static Set<String> seen = new HashSet<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<String> initial = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            initial.add(sc.nextLine());
        }
        best = null;
        bestLen = Integer.MAX_VALUE;
        dfs(initial);
        System.out.println(best == null ? "-1" : best);
    }

    static void dfs(List<String> list) {
        if (list.size() == 1) {
            String s = list.get(0);
            int len = s.length();
            if (len < bestLen || (len == bestLen && s.compareTo(best) < 0)) {
                bestLen = len;
                best = s;
            }
            return;
        }
        List<String> sorted = new ArrayList<>(list);
        Collections.sort(sorted);
        String key = String.join("#", sorted);
        if (!seen.add(key))
            return;

        int sz = list.size();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (i == j)
                    continue;
                String s = list.get(i), t = list.get(j);
                int maxOverlap = Math.min(s.length(), t.length());
                for (int k = maxOverlap; k > 0; k--) {
                    if (s.endsWith(t.substring(0, k))) {
                        String merged = s + t.substring(k);
                        List<String> next = new ArrayList<>();
                        for (int x = 0; x < sz; x++) {
                            if (x != i && x != j)
                                next.add(list.get(x));
                        }
                        next.add(merged);
                        dfs(next);
                    }
                }
            }
        }
    }
}