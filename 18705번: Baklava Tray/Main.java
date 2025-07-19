import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            double angle = Math.PI / N;
            double s = Math.sin(angle);
            double result = 10000.0 / (s * s);
            System.out.printf("%.5f\n", result);
        }
    }
}