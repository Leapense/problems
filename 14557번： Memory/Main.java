import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tokens = br.readLine().trim().split("\\s+");
        int R = Integer.parseInt(tokens[0]);
        int C = Integer.parseInt(tokens[1]);

        int N = (R * C) / 2;

        int minActions = N;
        int maxActions = 2 * N - 1;

        System.out.println(minActions + " " + maxActions);
    }
}