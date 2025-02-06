import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(br.readLine());

        int answer = 0;

        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= M; c++) {
                int dist1 = (r - 1) + (c - 1);
                int dist2 = (r - 1) + (M - c);
                int dist3 = (N - r) + (c - 1);
                int dist4 = (N - r) + (M - c);
                int maxDist = Math.max(Math.max(dist1, dist2), Math.max(dist3, dist4));

                if (maxDist < D) {
                    answer++;
                }
            }
        }

        System.out.println(answer);
    }
}