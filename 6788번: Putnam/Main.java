import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    private static final class ScoreInfo implements Comparable<ScoreInfo> {
        final long score;
        final long twoR;

        ScoreInfo(long score, long twoR) {
            this.score = score;
            this.twoR = twoR;
        }

        @Override
        public int compareTo(ScoreInfo other) {
            return Long.compare(other.score, this.score);
        }
    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            final int n = Integer.parseInt(br.readLine().trim());
            ScoreInfo[] list = new ScoreInfo[n];

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                long score = Long.parseLong(st.nextToken());
                long twoR = parseTwoR(st.nextToken());
                list[i] = new ScoreInfo(score, twoR);
            }

            final long myScore = Long.parseLong(br.readLine().trim());
            Arrays.sort(list);

            long better = 0;
            long lowerBound = 0;
            long upperBound = 0;

            for (ScoreInfo info : list) {
                long ties = info.twoR - 2 * better - 1;

                if (info.score == myScore) {
                    lowerBound = better + 1;
                    upperBound = better + ties;
                    break;
                }

                better += ties;
            }

            System.out.println(lowerBound);
            System.out.println(upperBound);
        }
    }

    private static long parseTwoR(String s) {
        BigDecimal bd = new BigDecimal(s).multiply(BigDecimal.valueOf(2L));
        return bd.longValueExact();
    }
}