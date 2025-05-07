import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        long[] b = new long[N];

        for (int i = 0; i < N; i++) {
            b[i] = Long.parseLong(st.nextToken());
        }

        long[] a = new long[N];
        a[0] = b[0];

        if (a[0] < 1 || a[0] > 1_000_000_000) {
            System.out.println(-1);
            return;
        }

        long S = a[0];

        for (int i = 1; i < N; i++) {
            long bi = b[i];
            long idx = i;
            long ai;

            if ((bi + 1) * idx < S) {
                ai = bi + 1;
            } else if (bi * idx >= S) {
                ai = bi;
            } else {
                System.out.println(-1);
                return;
            }

            if (ai < 1 || ai > 1_000_000_000) {
                System.out.println(-1);
                return;
            }

            a[i] = ai;
            S += ai;
        }

        StringBuilder sb = new StringBuilder();
        for (long ai : a) {
            sb.append(ai).append(' ');
        }

        System.out.println(sb);
    }
}