import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        long[] A = new long[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            A[i] = Long.parseLong(st.nextToken());
        long[] T = new long[M];
        long[] Q = new long[M];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            T[i] = Long.parseLong(st.nextToken());
            Q[i] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(A);
        reverse(A);

        long S = 0;
        int idx = 0;
        for (int i = 0; i < M; i++) {
            long ti = T[i], qi = Q[i];
            while (S < qi) {
                if (idx == N) {
                    System.out.println(-1);
                    return;
                }
                S += A[idx++] + ti;
            }
        }
        long tM = T[M - 1];
        while (idx < N) {
            S += A[idx++] + tM;
        }

        System.out.println(S);
    }

    static void reverse(long[] a) {
        int i = 0, j = a.length - 1;
        while (i < j) {
            long t = a[i];
            a[i++] = a[j];
            a[j--] = t;
        }
    }
}