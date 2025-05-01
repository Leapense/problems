import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long[] A = new long[N], B = new long[N], X = new long[N];
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            A[i] = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            B[i] = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            X[i] = Long.parseLong(st.nextToken());

        long maxAbsD = 0;
        int parity = -1;
        for (int i = 0; i < N; i++) {
            long diff = B[i] - A[i];
            if (diff % X[i] != 0) {
                System.out.println(-1);
                return;
            }
            long Di = diff / X[i];
            long absDi = Math.abs(Di);

            if (absDi > maxAbsD) {
                maxAbsD = absDi;
            }

            int pi = (int) (Di & 1);

            if (parity == -1) {
                parity = pi;
            } else if (parity != pi) {
                System.out.println(-1);
                return;
            }
        }

        long k = maxAbsD;
        if ((k & 1) != parity) {
            k++;
        }

        System.out.println(k);
    }
}