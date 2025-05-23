import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        HashSet<String> result = new HashSet<>();

        for (int i = 0; i < N; i++) {
            String s = br.readLine();

            for (int j = 0; j < s.length(); j++) {
                String suffix = s.substring(j);

                if (result.contains(suffix)) {
                    result.remove(suffix);
                } else {
                    result.add(suffix);
                }
            }
        }

        System.out.println(result.size());
    }
}