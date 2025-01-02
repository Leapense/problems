import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(br.readLine().trim());
        String[] tokens = br.readLine().trim().split("\\s+");
        int[] counts = new int[m];

        for (String token : tokens) {
            double a = Double.parseDouble(token);
            int index = (int)(a * m);
            if (index >= m) index = m - 1;
            counts[index]++;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            sb.append(counts[i]);
            if (i != m - 1) sb.append(" ");
        }

        System.out.println(sb);

        br.close();
    }
}