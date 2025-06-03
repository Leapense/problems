import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public final class Main
{
    private static final int LIMIT = 10_000_000;
    private static final boolean[] IS_PRIME = new boolean[LIMIT + 1];
    private static final int[] PREFIX = new int[LIMIT + 1];

    public static void main(String[] args) throws IOException {
        preprocessPrimes();
        List<Integer> answers = readAndSolveQueries();
        writeAnswers(answers);
    }

    private static void preprocessPrimes() {
        if (LIMIT >= 0) {
            IS_PRIME[0] = false;
        }
        if (LIMIT >= 1) {
            IS_PRIME[1] = false;
        }

        for (int i = 2; i <= LIMIT; i++) {
            IS_PRIME[i] = true;
        }
        final int sqrt = (int) Math.sqrt(LIMIT);
        for (int i = 2; i <= sqrt; i++) {
            if (!IS_PRIME[i]) continue;

            for (int j = i * i; j <= LIMIT; j += i) {
                IS_PRIME[j] = false;
            }
        }

        PREFIX[0] = 0;
        for (int i = 1; i <= LIMIT; i++) {
            PREFIX[i] = PREFIX[i - 1] + (IS_PRIME[i] ? 1 : 0);
        }
    }

    private static List<Integer> readAndSolveQueries() throws IOException {
        List<Integer> result = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) {
                    continue;
                }
                StringTokenizer st = new StringTokenizer(line);
                int m = Integer.parseInt(st.nextToken());
                int n = Integer.parseInt(st.nextToken());
                result.add(countPrimesInRange(m, n));
            }
        }

        return result;
    }

    private static int countPrimesInRange(int m, int n) {
        return PREFIX[n] - PREFIX[m - 1];
    }

    private static void writeAnswers(List<Integer> answers) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0, size = answers.size(); i < size; i++) {
            sb.append(answers.get(i));
            if (i < size - 1) {
                sb.append('\n').append('\n');
            }
        }

        System.out.print(sb);
    }
}