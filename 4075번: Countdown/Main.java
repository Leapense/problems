import java.util.*;
import java.io.*;

public class Main {
    static Map<String, List<String>> tree;
    static Map<String, Map<Integer, Integer>> memo;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();

        for (int t = 1; t <= T; t++) {
            int n = sc.nextInt();
            int d = sc.nextInt();
            sc.nextLine();
            tree = new HashMap<>();
            Set<String> allNames = new HashSet<>();
            for (int i = 0; i < n; i++) {
                String line = sc.nextLine();
                String[] parts = line.split("\\s+");
                String name = parts[0];
                allNames.add(name);
                int m = Integer.parseInt(parts[1]);
                List<String> children = new ArrayList<>();

                for (int j = 0; j < m; j++) {
                    String child = parts[j + 2];
                    children.add(child);
                    allNames.add(child);
                }

                tree.put(name, children);
            }

            for (String name : allNames) {
                if (!tree.containsKey(name)) {
                    tree.put(name, new ArrayList<>());
                }
            }

            memo = new HashMap<>();
            Map<String, Integer> result = new HashMap<>();
            for (String name : allNames) {
                int count = descendants(name, d);
                if (count > 0) {
                    result.put(name, count);
                }
            }

            List<Map.Entry<String, Integer>> list = new ArrayList<>(result.entrySet());
            Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
                public int compare(Map.Entry<String, Integer> a, Map.Entry<String, Integer> b) {
                    if (!b.getValue().equals(a.getValue()))
                        return b.getValue() - a.getValue();
                    return a.getKey().compareTo(b.getKey());
                }
            });
            System.out.println("Tree " + t + ":");
            if (!list.isEmpty()) {
                int cutoff = list.size() >= 3 ? list.get(2).getValue() : 0;
                for (Map.Entry<String, Integer> entry : list) {
                    if (entry.getValue() >= cutoff) {
                        System.out.println(entry.getKey() + " " + entry.getValue());
                    }
                }
            }
            System.out.println();
        }
        sc.close();
    }

    static int descendants(String name, int gen) {
        if (memo.containsKey(name) && memo.get(name).containsKey(gen)) {
            return memo.get(name).get(gen);
        }

        int count = 0;
        if (gen == 1) {
            count = tree.get(name).size();
        } else {
            for (String child : tree.get(name)) {
                count += descendants(child, gen - 1);
            }
        }

        memo.computeIfAbsent(name, k -> new HashMap<>()).put(gen, count);
        return count;
    }
}