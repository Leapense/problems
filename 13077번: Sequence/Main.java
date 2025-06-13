import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public final class Main
{
    private Main() {

    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int testCases = Integer.parseInt(br.readLine());
            StringBuilder output = new StringBuilder();

            for (int i = 0; i < testCases; i++) {
                String fractionStr = br.readLine();
                long index = findSequenceIndex(fractionStr);
                output.append(index).append("\n");
            }

            System.out.print(output);
        }
    }

    private static long findSequenceIndex(String fractionStr) {
        String[] parts = fractionStr.split("/");
        long p = Long.parseLong(parts[0]);
        long q = Long.parseLong(parts[1]);

        if (p == 1 && q == 1) {
            return 1;
        }

        StringBuilder pathBinary = new StringBuilder();
        while (p > 1 || q > 1) {
            if (p > q) {
                long k = (p - 1) / q;
                pathBinary.insert(0, "1".repeat((int) k));
                p -= k * q;
            } else {
                long k = (q - 1) / p;
                pathBinary.insert(0, "0".repeat((int) k));
                q -= k * p;
            }
        }

        String nBinaryString = "1" + pathBinary;
        return Long.parseLong(nBinaryString, 2);
    }
}