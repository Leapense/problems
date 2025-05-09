import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine().trim());

        Set<String> distinct = new HashSet<>();
        for (int i = 0; i < N; i++) {
            String word = br.readLine().trim();
            distinct.add(word);
        }

        List<String> words = new ArrayList<>(distinct);

        int answer = 0;
        for (String s : words) {
            boolean isPrefix = false;
            for (String t : words) {
                if (s == t)
                    continue;
                if (t.startsWith(s)) {
                    isPrefix = true;
                    break;
                }
            }
            if (!isPrefix) {
                answer++;
            }
        }

        System.out.println(answer);
        br.close();
    }
}