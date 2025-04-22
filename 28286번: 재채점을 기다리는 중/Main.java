import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    static int N, K;
    static int[] answer;
    static int[] omr;
    static int best = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        answer = new int[N];
        omr = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            answer[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            omr[i] = Integer.parseInt(st.nextToken());
        }

        dfs(0, omr);
        System.out.println(best);
    }

    static void dfs(int depth, int[] current) {
        best = Math.max(best, countCorrect(current));
        if (depth == K) return;

        for (int p = 0; p < N; p++) {
            int[] pulled = shiftPull(current, p);
            dfs(depth + 1, pulled);
            int[] pushed = shiftPush(current, p);
            dfs(depth + 1, pushed);
        }
    }

    static int[] shiftPull(int[] arr, int p) {
        int[] tmp = arr.clone();
        for (int i = p; i < N - 1; i++) {
            tmp[i] = tmp[i + 1];
        }
        tmp[N - 1] = 0;
        return tmp;
    }

    static int[] shiftPush(int[] arr, int p) {
        int[] tmp = arr.clone();
        for (int i = N - 1; i > p; i--) {
            tmp[i] = tmp[i - 1];
        }
        tmp[p] = 0;
        return tmp;
    }

    static int countCorrect(int[] arr) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] != 0 && arr[i] == answer[i]) cnt++;
        }

        return cnt;
    }
}
