import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long N = Long.parseLong(st.nextToken());
        long R = Long.parseLong(st.nextToken());
        br.close();

        long D = N - R;
        if (D <= 0) {
            System.out.println(0);
            return;
        }

        long sum = 0;
        long sqrtD = (long) Math.sqrt(D);
        for (long i = 1; i <= sqrtD; i++) {
            if (D % i == 0) {
                long j = D / i;
                if (i > R) {
                    sum += i;
                }
                if (j != i && j > R) {
                    sum += j;
                }
            }
        }

        System.out.println(sum);
    }
}