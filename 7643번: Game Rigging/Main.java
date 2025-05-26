import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer tokenizer;
            while (true) {
                tokenizer = new StringTokenizer(reader.readLine());
                int n = Integer.parseInt(tokenizer.nextToken());
                int k = Integer.parseInt(tokenizer.nextToken());
                int m = Integer.parseInt(tokenizer.nextToken());
                if (n == 0 && k == 0 && m == 0) {
                    break;
                }

                // 친구 인덱스 읽기
                tokenizer = new StringTokenizer(reader.readLine());
                boolean[] isFriend = new boolean[n + 1];
                for (int i = 0; i < k; i++) {
                    int f = Integer.parseInt(tokenizer.nextToken());
                    isFriend[f] = true;
                }

                // 그래프 구축
                List<List<Integer>> graph = new ArrayList<>(n + 1);
                for (int i = 0; i <= n; i++) {
                    graph.add(new ArrayList<>());
                }
                for (int i = 0; i < m; i++) {
                    tokenizer = new StringTokenizer(reader.readLine());
                    int a = Integer.parseInt(tokenizer.nextToken());
                    int b = Integer.parseInt(tokenizer.nextToken());
                    graph.get(a).add(b);
                }

                // 멀티소스 BFS로 도달 가능한 모든 노드 찾기
                boolean[] visited = new boolean[n + 1];
                Deque<Integer> queue = new ArrayDeque<>();
                for (int player = 1; player <= n; player++) {
                    if (isFriend[player]) {
                        visited[player] = true;
                        queue.add(player);
                    }
                }

                int visitedCount = 0;
                while (!queue.isEmpty()) {
                    int current = queue.poll();
                    visitedCount++;
                    for (int next : graph.get(current)) {
                        if (!visited[next]) {
                            visited[next] = true;
                            queue.add(next);
                        }
                    }
                }

                // 결과 출력
                System.out.println(visitedCount == n ? "yes" : "no");
            }
        }
    }
}