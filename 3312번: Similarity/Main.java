import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String pattern = br.readLine().trim();
        String text = br.readLine().trim();
        int m = pattern.length();
        int n = text.length();
        int L = n - m + 1;
        int[][] prefix = new int[26][n + 1];

        for (int i = 0; i < n; i++) {
            int letter = text.charAt(i) - 'a';
            for (int j = 0; j < 26; j++) {
                prefix[j][i + 1] = prefix[j][i];
            }
            prefix[letter][i + 1]++;
        }

        long answer = 0;
        for (int j = 0; j < m; j++) {
            int letter = pattern.charAt(j) - 'a';
            answer += prefix[letter][j + L] - prefix[letter][j];
        }

        System.out.println(answer);
    }
}