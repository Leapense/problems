import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        Map<Integer, Map<Integer, Integer>> groups = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt(), b = sc.nextInt();
            if (a == b) {
                groups.computeIfAbsent(a, k -> new HashMap<>());
                Map<Integer, Integer> map = groups.get(a);
                map.put(a, map.getOrDefault(a, 0) + 1);
            } else {
                groups.computeIfAbsent(a, k -> new HashMap<>());
                Map<Integer, Integer> mapA = groups.get(a);
                mapA.put(b, mapA.getOrDefault(b, 0) + 1);
                groups.computeIfAbsent(b, k -> new HashMap<>());
                Map<Integer, Integer> mapB = groups.get(b);
                mapB.put(a, mapB.getOrDefault(a, 0) + 1);
            }
        }
        for (int qi = 0; qi < m; qi++) {
            int sumQuery = sc.nextInt();
            long count = 0;
            for (Map<Integer, Integer> freq : groups.values()) {
                for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
                    int x = entry.getKey();
                    int y = sumQuery - x;
                    if (x > y)
                        continue;
                    if (freq.containsKey(y)) {
                        if (x == y) {
                            int f = freq.get(x);
                            count += (long) f * (f - 1) / 2;
                        } else {
                            count += (long) entry.getValue() * freq.get(y);
                        }
                    }
                }
            }
            System.out.println(count);
        }
        sc.close();
    }
}