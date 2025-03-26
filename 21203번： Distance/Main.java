import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] s = new int[N];
        int[] a = new int[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            s[i] = Integer.parseInt(st.nextToken());
            a[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(s);
        Arrays.sort(a);

        long total = 0;

        for (int i = 0; i < N; i++) {
            total += (long) s[i] * (2 * i - N + 1);
            total += (long) a[i] * (2 * i - N + 1);
        }

        System.out.println(total);
    }
}