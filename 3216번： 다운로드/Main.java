import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] D = new int[N];
        int[] V = new int[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            D[i] = Integer.parseInt(st.nextToken());
            V[i] = Integer.parseInt(st.nextToken());
        }

        int cumDownload = 0;
        int cumListen = 0;
        int answer = 0;

        for (int i = 0; i < N; i++) {
            cumDownload += V[i];
            int requiredWait = cumDownload - cumListen;
            if (requiredWait > answer) {
                answer = requiredWait;
            }
            cumListen += D[i];
        }

        System.out.println(answer);
    }
}