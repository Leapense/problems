import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        for (int tc = 1; tc <= T; tc++) {
            String[] parts = br.readLine().trim().split("\\s+");
            char[] S = parts[0].toCharArray();
            int K = Integer.parseInt(parts[1]);
            int count = 0;

            for (int i = 0; i <= S.length - K; i++) {
                if (S[i] == '-') {
                    count++;
                    for (int j = i; j < i + K; j++) {
                        S[j] = S[j] == '+' ? '-' : '+';
                    }
                }
            }

            boolean allHappy = true;
            for (char c : S) {
                if (c == '-') {
                    allHappy = false;
                    break;
                }
            }

            if (allHappy) {
                sb.append("Case #").append(tc).append(": ").append(count).append("\n");
            } else {
                sb.append("Case #").append(tc).append(": IMPOSSIBLE\n");
            }
        }

        System.out.print(sb);

        br.close();
    }
}