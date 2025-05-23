import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        String[] s = br.readLine().split(" ");

        int[] lengths = new int[n];

        for (int i = 0; i < n; i++) {
            lengths[i] = s[i].length();
        }

        int i = 0;
        int currentLength = 0;
        StringBuilder sb = new StringBuilder();

        while (i < n) {
            if (currentLength + lengths[i] > k) {
                sb.deleteCharAt(sb.length() - 1);
                sb.append("\n");
                currentLength = 0;
            }

            sb.append(s[i] + " ");
            currentLength += lengths[i];
            i++;
        }
        sb.deleteCharAt(sb.length() - 1);
        System.out.println(sb);
    }
}