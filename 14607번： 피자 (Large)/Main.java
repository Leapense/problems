import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine().trim();
        long N = Long.parseLong(input);

        long totalHappiness = computeMaxHappiness(N);
        System.out.println(totalHappiness);
    }

    private static long computeMaxHappiness(long N) {
        if (N <= 1) {
            return 0;
        }

        return (N * (N - 1)) / 2;
    }
}