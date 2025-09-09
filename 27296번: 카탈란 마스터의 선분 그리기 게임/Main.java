import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());

        for (int t = 0; t < T; t++) {
            String line;
            do {
                line = br.readLine();
            } while (line != null && line.trim().isEmpty());
            
            long N = Long.parseLong(line.trim());

            if (N <= 1) {
                out.append("1 0\n");
            } else {
                out.append("0 1\n");
            }
        }

        System.out.print(out.toString());
    }
}