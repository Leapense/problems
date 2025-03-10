import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int scenarios = sc.nextInt();

        for (int i = 1; i <= scenarios; i++) {
            int steps = sc.nextInt();
            sc.nextLine();

            Map<String, List<String>> graph = new HashMap<>();
            Map<String, Integer> inDegree = new HashMap<>();

            Set<String> allNodes = new HashSet<>();

            for (int j = 0; j < steps - 1; j++) {
                String line = sc.nextLine();
                String[] parts = line.split(" ");
                String from = parts[0];
                String to = parts[1];

                allNodes.add(from);
                allNodes.add(to);

                if (!graph.containsKey(from)) {
                    graph.put(from, new ArrayList<>());
                }
                graph.get(from).add(to);
                inDegree.put(to, inDegree.getOrDefault(to, 0) + 1);
            }

            String startNode = null;
            for (String node : allNodes) {
                if (!inDegree.containsKey(node) || inDegree.get(node) == 0) {
                    startNode = node;
                    break;
                }
            }

            System.out.println("Scenario #" + i + ":");

            String currentNode = startNode;
            for (int j = 0; j < steps; j++) {
                System.out.println(currentNode);
                if (graph.containsKey(currentNode) && !graph.get(currentNode).isEmpty()) {
                    currentNode = graph.get(currentNode).get(0);
                }
            }

            System.out.println();
        }

        sc.close();
    }
}