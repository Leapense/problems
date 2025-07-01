import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    private static int n;
    private static int m;
    private static int kIndex;
    private static int[][] pref;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stFirst = new StringTokenizer(br.readLine());
        n = Integer.parseInt(stFirst.nextToken());
        m = Integer.parseInt(stFirst.nextToken());
        int kLabel = Integer.parseInt(stFirst.nextToken());
        kIndex = kLabel - 1;

        pref = new int[n][m];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                pref[i][j] = Integer.parseInt(st.nextToken()) - 1;
            }
        }

        int currentWinner = evaluateWinner(0);
        int minWithdrawals = searchMinimalWithdrawals();

        System.out.println(currentWinner + 1);
        System.out.println(minWithdrawals);
    }

    private static int evaluateWinner(int withdrawnMask) {
        int[] votes = new int[m];
        for (int county = 0; county < n; county++) {
            for (int position = 0; position < m; position++) {
                int candidate = pref[county][position];
                if ((withdrawnMask & (1 << candidate)) == 0) {
                    votes[candidate]++;
                    break;
                }
            }
        }
        int best = 0;
        for (int c = 1; c < m; c++) {
            if (votes[c] > votes[best] || (votes[c] == votes[best] && c < best)) {
                best = c;
            }
        }
        return best;
    }

    private static int searchMinimalWithdrawals() {
        int fullMaskWithoutK = (1 << m) - 1 ^ (1 << kIndex);
        int best = m;                                       // upper bound
        for (int mask = 0; mask <= fullMaskWithoutK; mask++) {
            if (Integer.bitCount(mask) >= best) {
                continue;
            }
            int winner = evaluateWinner(mask);
            if (winner == kIndex) {
                best = Integer.bitCount(mask);
            }
        }
        return best;
    }
}