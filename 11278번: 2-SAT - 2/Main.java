import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public final class Main {
    private static int variableCount;
    private static int clauseCount;
    private static int[][] clauses;

    public static void main(String[] args) throws IOException {
        parseInput();
        Boolean[] fixedVal = new Boolean[variableCount];
        if (!check2SAT(fixedVal)) {
            System.out.println("0");
            return;
        }

        for (int i = 0; i < variableCount; i++) {
            fixedVal[i] = Boolean.FALSE;
            if (check2SAT(fixedVal)) {
                continue;
            }
            fixedVal[i] = Boolean.TRUE;
            if (!check2SAT(fixedVal)) {
                System.out.println("0");
                return;
            }
        }

        System.out.println("1");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < variableCount; i++) {
            sb.append(fixedVal[i] ? "1" : "0");
            if (i < variableCount - 1) {
                sb.append(' ');
            }
        }

        System.out.println(sb);
    }

    private static void parseInput() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] first = reader.readLine().trim().split("\\s+");
        variableCount = Integer.parseInt(first[0]);
        clauseCount = Integer.parseInt(first[1]);

        clauses = new int[clauseCount][2];
        for (int i = 0; i < clauseCount; i++) {
            String[] line = reader.readLine().trim().split("\\s+");
            clauses[i][0] = Integer.parseInt(line[0]);
            clauses[i][1] = Integer.parseInt(line[1]);
        }
    }

    private static boolean check2SAT(Boolean[] fixedVal) {
        int nodeCount = 2 * variableCount;

        @SuppressWarnings("unchecked")
        List<Integer>[] graph = new ArrayList[nodeCount];
        @SuppressWarnings("unchecked")
        List<Integer>[] reverseGraph = new ArrayList[nodeCount];
        for (int i = 0; i < nodeCount; i++) {
            graph[i] = new ArrayList<>();
            reverseGraph[i] = new ArrayList<>();
        }

        for (int i = 0; i < clauseCount; i++) {
            int litA = clauses[i][0];
            int litB = clauses[i][1];
            int idxA = toNodeIndex(litA);
            int idxB = toNodeIndex(litB);
            int notA = idxA ^ 1;
            int notB = idxB ^ 1;

            graph[notA].add(idxB);
            reverseGraph[idxB].add(notA);

            graph[notB].add(idxA);
            reverseGraph[idxA].add(notB);
        }

        for (int i = 0; i < variableCount; i++) {
            if (fixedVal[i] == null) {
                continue;
            }

            if (fixedVal[i]) {
                int idxTrue = toNodeIndex(i + 1);
                int notTrue = idxTrue ^ 1;
                graph[notTrue].add(idxTrue);
                reverseGraph[idxTrue].add(notTrue);
            } else {
                int idxFalse = toNodeIndex(-(i + 1));
                int notFalse = idxFalse ^ 1;
                graph[notFalse].add(idxFalse);
                reverseGraph[idxFalse].add(notFalse);
            }
        }

        boolean[] visited1 = new boolean[nodeCount];
        Deque<Integer> finishOrder = new ArrayDeque<>();
        for (int u = 0; u < nodeCount; u++) {
            if (!visited1[u]) {
                runFirstDfs(u, graph, visited1, finishOrder);
            }
        }

        boolean[] visited2 = new boolean[nodeCount];
        int[] sccId = new int[nodeCount];
        int componentId = 0;
        while (!finishOrder.isEmpty()) {
            int u = finishOrder.pop();
            if (!visited2[u]) {
                runSecondDfs(u, componentId, reverseGraph, visited2, sccId);
                componentId++;
            }
        }

        for (int i = 0; i < variableCount; i++) {
            int idxTrue = 2 * i;
            int idxFalse = idxTrue + 1;
            if (sccId[idxTrue] == sccId[idxFalse]) {
                return false;
            }
        }

        return true;
    }

    private static void runFirstDfs(int node, List<Integer>[] graph, boolean[] visited, Deque<Integer> finishOrder) {
        visited[node] = true;
        for (int nxt : graph[node]) {
            if (!visited[nxt]) {
                runFirstDfs(nxt, graph, visited, finishOrder);
            }
        }

        finishOrder.push(node);
    }

    private static void runSecondDfs(int node, int componentId, List<Integer>[] reverseGraph, boolean[] visited, int[] sccId) {
        visited[node] = true;
        sccId[node] = componentId;
        for (int nxt : reverseGraph[node]) {
            if (!visited[nxt]) {
                runSecondDfs(nxt, componentId, reverseGraph, visited, sccId);
            }
        }
    }

    private static int toNodeIndex(int literal) {
        int varIdx = Math.abs(literal) - 1;
        boolean isPositive = (literal > 0);
        return varIdx * 2 + (isPositive ? 0 : 1);
    }
}