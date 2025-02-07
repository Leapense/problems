import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            String line = br.readLine();
            if (line == null)
                break;
            int n = Integer.parseInt(line.trim());

            if (n == 0)
                break;

            if ((n & (n - 1)) == 0) {
                sb.append("NAO\n");
            } else {
                sb.append("SIM\n");
            }
        }

        System.out.print(sb);
    }
}