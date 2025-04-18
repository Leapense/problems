import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        FastReader in = new FastReader();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        int N = in.nextInt();
        int[] A = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = in.nextInt();
        }

        int M = in.nextInt();
        int[] B = new int[M];
        for (int i = 0; i < M; i++) {
            B[i] = in.nextInt();
        }

        Arrays.sort(A);
        Arrays.sort(B);

        int i = 0, j = 0, count = 0;
        while (i < N && j < M) {
            if (A[i] <= B[j]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        out.println(count);
        out.flush();
        out.close();
    }

    static class FastReader {
        private final BufferedReader br;
        private StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in), 1 << 20);
        }

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) return null;
                st = new StringTokenizer(line);
            }

            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}
