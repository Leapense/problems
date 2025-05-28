import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        long[] A = new long[n + 1];
        st = new StringTokenizer(reader.readLine());
        for (int i = 1; i <= n; i++) {
            A[i] = A[i - 1] + Integer.parseInt(st.nextToken());
        }

        long[] B = new long[m + 1];
        st = new StringTokenizer(reader.readLine());
        for (int j = 1; j <= m; j++) {
            B[j] = B[j - 1] + Integer.parseInt(st.nextToken());
        }

        int z = Integer.parseInt(reader.readLine());
        StringBuilder output = new StringBuilder();

        for (int qi = 0; qi < z; qi++) {
            st = new StringTokenizer(reader.readLine());
            int d = Integer.parseInt(st.nextToken());
            int mm = Integer.parseInt(st.nextToken());
            char c = st.nextToken().charAt(0);

            long[] src = (c == 'A') ? A : B;
            long[] dst = (c == 'A') ? B : A;

            long dayOfYear = src[mm - 1] + d;

            int idx = Arrays.binarySearch(dst, dayOfYear);
            if (idx < 0) {
                idx = -idx - 1;
            }

            long dayInMonth = dayOfYear - dst[idx - 1];
            output.append(dayInMonth).append(' ').append(idx).append('\n');
        }

        System.out.print(output);
    }
}