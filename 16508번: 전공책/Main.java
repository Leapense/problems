import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String target = scanner.nextLine();
        int n = scanner.nextInt();
        scanner.nextLine();

        int[] costs = new int[n];
        String[] titles = new String[n];

        for (int i = 0; i < n; i++) {
            costs[i] = scanner.nextInt();
            titles[i] = scanner.next();
            scanner.nextLine();
        }

        Map<Character, Integer> targetCount = new HashMap<>();
        for (char c : target.toCharArray()) {
            targetCount.put(c, targetCount.getOrDefault(c, 0) + 1);
        }

        int INF = Integer.MAX_VALUE;
        int minCost = INF;

        for (int i = 0; i < (1 << n); i++) {
            int totalCost = 0;
            Map<Character, Integer> totalCount = new HashMap<>();

            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    totalCost += costs[j];
                    for(char c : titles[j].toCharArray()) {
                        totalCount.put(c, totalCount.getOrDefault(c, 0) + 1);
                    }
                }
            }

            boolean valid = true;
            for (char c : targetCount.keySet()) {
                if (totalCount.getOrDefault(c, 0) < targetCount.get(c)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                minCost = Math.min(minCost, totalCost);
            }
        }

        System.out.println(minCost == INF ? -1 : minCost);
    }
}