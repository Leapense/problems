import java.io.*;
import java.util.*;

public class Main {
    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] value = new int[n + 1];
        int[] pos = new int[n + 1];
        long[] move = new long[n + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            int num = Integer.parseInt(st.nextToken());
            value[i] = num;
            pos[num] = i;
        }

        for (int i = 1; i <= n - 1; i++) {
            int currentPos = pos[i];

            if (currentPos != i) {
                int x = value[i];
                int dist = currentPos - i;

                move[i] += dist;
                move[x] += dist;

                value[currentPos] = x;
                value[i] = i;
                pos[i] = i;
                pos[x] = currentPos;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            sb.append(move[i]);
            if (i != n)
                sb.append(" ");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}