import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(br.readLine().trim());
        String[] tokens = br.readLine().split(" ");
        int[] count = new int[m];

        for (String token : tokens) {
            double x = Double.parseDouble(token);

            int idx = (int) Math.floor(x * m);
            if (idx == m) {
                idx = m - 1;
            }

            count[idx]++;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            sb.append(count[i]);
            if (i < m - 1) {
                sb.append(" ");
            }
        }

        System.out.println(sb.toString());
    }
}