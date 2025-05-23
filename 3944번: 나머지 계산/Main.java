import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int B = Integer.parseInt(st.nextToken());
            String D = st.nextToken();

            if (B == 2) {
                sb.append("0\n");
                continue;
            }

            int mod = B - 1;
            long sum = 0;
            for (int i = 0; i < D.length(); i++) {
                sum = (sum + (D.charAt(i) - '0')) % mod;
            }

            sb.append(sum % mod).append("\n");
        }

        System.out.print(sb.toString());
    }
}