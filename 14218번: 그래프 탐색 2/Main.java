import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main
{
    static List<List<Integer>> adj;
    static int N;

    static int[] bfs(int startNode) {
        int[] distances = new int[N + 1];
        Arrays.fill(distances, -1);

        Queue<Integer> queue = new LinkedList<>();

        distances[startNode] = 0;
        queue.add(startNode);

        while (!queue.isEmpty()) {
            int current = queue.poll();
            for (int neighbor : adj.get(current)) {
                if (distances[neighbor] == -1) {
                    distances[neighbor] = distances[current] + 1;
                    queue.add(neighbor);
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        adj = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }

        for (int k = 0; k < M; k++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        int Q = Integer.parseInt(br.readLine());

        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj.get(u).add(v);
            adj.get(v).add(u);

            int[] distances = bfs(1);
            for (int i = 1; i <= N; i++) {
                bw.write(distances[i] + (i == N ? "" : " "));
            }

            bw.newLine();
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
