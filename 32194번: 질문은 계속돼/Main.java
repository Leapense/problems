import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        int Q = N + 1;

        int[] prefYes = new int[Q + 1];
        prefYes[1] = 1;

        for (int i = 2; i <= Q; i++) {
            st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            int yesCount = prefYes[y] - prefYes[x - 1];
            boolean answerYes;

            if (type == 1) {
                answerYes = (yesCount == (y - x + 1));
            } else {
                int noCount = (y - x + 1) - yesCount;
                answerYes = (noCount == (y - x + 1));
            }

            prefYes[i] = prefYes[i - 1] + (answerYes ? 1 : 0);

            sb.append(answerYes ? "Yes\n" : "No\n");
        }

        System.out.println(sb);
    }
}