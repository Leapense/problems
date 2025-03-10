import java.util.ArrayList;
import java.util.Scanner;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.LinkedList;
import java.util.List;

class Edge {
    String node1;
    String node2;

    Edge(String n1, String n2) {
        node1 = n1;
        node2 = n2;
    }
}

public class Main {

    private static int solveNeighborhoods(int numNodes, ArrayList<Edge> edges, String target) {
        Map<String, List<String>> graph = new HashMap<>();
        for (Edge edge : edges) {
            graph.computeIfAbsent(edge.node1, k -> new ArrayList<>()).add(edge.node2);
            graph.computeIfAbsent(edge.node2, k -> new ArrayList<>()).add(edge.node1);
        }

        HashSet<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        Map<String, Integer> distance = new HashMap<>();

        visited.add(target);
        queue.add(target);
        distance.put(target, 0);

        while (!queue.isEmpty()) {
            String current = queue.poll();
            int d = distance.get(current);
            if (d == 2)
                continue;
            List<String> neighbors = graph.getOrDefault(current, new ArrayList<>());
            for (String neighbor : neighbors) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    distance.put(neighbor, d + 1);
                    queue.add(neighbor);
                }
            }
        }

        int count = 0;
        for (Map.Entry<String, Integer> entry : distance.entrySet()) {
            if (entry.getValue() > 0 && entry.getValue() <= 2) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTests = sc.nextInt();
        for (int t = 0; t < numTests; t++) {
            int numNodes = sc.nextInt();
            int numEdges = sc.nextInt();
            ArrayList<Edge> edges = new ArrayList<>();
            for (int i = 0; i < numEdges; i++) {
                edges.add(new Edge(sc.next(), sc.next()));
            }
            String target = sc.next();
            int res = solveNeighborhoods(numNodes, edges, target);
            System.out.println("The number of supervillains in 2-hop neighborhood of " + target + " is " + res);
        }
        sc.close();
    }
}