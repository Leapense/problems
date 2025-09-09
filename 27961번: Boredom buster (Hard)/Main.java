import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        int t = 0;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (!line.isEmpty()) {
                t = Integer.parseInt(line);
                break;
            }
        }

        StringBuilder out = new StringBuilder();
        int cases = 0;

        while (cases < t && (line = br.readLine()) != null ) {
            line = line.trim();
            if (line.isEmpty()) continue;
            long n = Long.parseLong(line);
            long ans = n * (n - 1) / 2;
            out.append(ans).append('\n');
            cases++;
        }

        System.out.print(out.toString());
    }
}