import java.io.*;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int K = N;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int L = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());
            K = Math.min(K, R - L + 1);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            int xi = (i % K) + 1;
            sb.append(xi).append(i + 1 < N ? ' ' : '\n');
        }

        bw.write(sb.toString());
        bw.flush();
    }
}