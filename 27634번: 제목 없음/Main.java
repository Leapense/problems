import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
                PrintWriter out = new PrintWriter(System.out)) {

            StringTokenizer st = new StringTokenizer(in.readLine());
            long K = Long.parseLong(st.nextToken());
            long S = Long.parseLong(st.nextToken());
            long N = Long.parseLong(st.nextToken());

            boolean possible = false;

            if (S == 1) {
                if ((N >= K && N <= 2 * K - 2) || (N >= 2 * K && N % 2 == 0)) {
                    possible = true;
                }
            } else {
                if (N >= S * K) {
                    possible = true;
                }
            }

            out.println(possible ? "YES" : "NO");
        }
    }
}