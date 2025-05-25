import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public final class Main {
    private Main() {

    }

    public static void main(final String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tokens = br.readLine().trim().split("\\s+");
        long k = Long.parseLong(tokens[0]);
        long r = Long.parseLong(tokens[1]);

        long ceilR = (r + k - 1) / k;
        long t = ceilR - 1;

        long c = 0;
        if (r % k == 0) {
            long R = r / k;
            long rSquared = R * R;

            for (long x = 1; x < R; x++) {
                long y2 = rSquared - x * x;
                long y = (long) Math.sqrt(y2);
                if (y > 0 && y * y == y2) {
                    c++;
                }
            }
        }

        long quarter = 2 * t - c + 1;
        long result = 4 * quarter;
        System.out.println(result);
    }
}