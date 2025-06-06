import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    private static final long MOD = 1_000_000_007;
    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int testCases = Integer.parseInt(br.readLine());
            StringBuilder resultBuilder = new StringBuilder();

            for (int t = 1; t <= testCases; t++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int c = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int l = Integer.parseInt(st.nextToken());

                long answer = solve(c, v, l);
                resultBuilder.append("Case #").append(t).append(": ").append(answer).append("\n");
            }

            System.out.print(resultBuilder);
        }
    }

    private static long solve(long C, long V, int L)
    {
        if (L == 0) {
            return 0;
        }

        long endsWithVowel = V;
        long endsWithConsonant = C;

        for (int i = 2; i <= L; i++) {
            long prevEndsWithVowel = endsWithVowel;
            long prevEndsWithConsonant = endsWithConsonant;

            endsWithVowel = (prevEndsWithVowel + prevEndsWithConsonant) * V % MOD;

            endsWithConsonant = prevEndsWithVowel * C % MOD;
        }

        return endsWithVowel;
    }
}