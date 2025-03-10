import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[][] matrix = new int[N + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                matrix[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        boolean[] visited = new boolean[N + 1];
        ArrayList<ArrayList<Integer>> levels = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(M);
        visited[M] = true;

        while (!queue.isEmpty()) {
            int size = queue.size();
            ArrayList<Integer> level = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                int cur = queue.poll();
                level.add(cur);
                for (int j = 1; j <= N; j++) {
                    if (matrix[cur][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        queue.add(j);
                    }
                }
            }

            Collections.sort(level);
            levels.add(level);
        }

        StringBuilder sb = new StringBuilder();
        for (ArrayList<Integer> level : levels) {
            for (int num : level) {
                sb.append(num).append(" ");
            }

            sb.setLength(sb.length() - 1);
            sb.append("\n");
        }

        System.out.println(sb.toString());
    }
}