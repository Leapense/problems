import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int maxType = 0;
        st = new StringTokenizer(br.readLine());
        int[] socksTemp = new int[N];
        int[] types = new int[N];

        for (int i = 0; i < N; i++) {
            int t = Integer.parseInt(st.nextToken());
            types[i] = t;
            if (t > maxType)
                maxType = t;
        }

        int Q = Integer.parseInt(br.readLine());
        int[] queryA = new int[Q];
        int[] queryB = new int[Q];

        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            queryA[i] = a;
            queryB[i] = b;

            if (a > maxType)
                maxType = a;
        }

        int[] socks = new int[maxType + 1];
        for (int i = 0; i < N; i++) {
            socks[types[i]]++;
        }

        long totalSets = 0;
        for (int i = 0; i <= maxType; i++) {
            totalSets += socks[i] / K;
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < Q; i++) {
            int type = queryA[i];
            int lost = queryB[i];
            int oldCount = socks[type];
            int newCount = oldCount - lost;

            totalSets = totalSets - (oldCount / K) + (newCount / K);
            socks[type] = newCount;

            bw.write(totalSets + "\n");
        }

        bw.flush();
    }
}