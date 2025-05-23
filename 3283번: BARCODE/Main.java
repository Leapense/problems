import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static char[][] grid;
    static DPResult[][] dp;

    static class DPResult {
        boolean ambiguous;
        String sol;

        DPResult(boolean amb, String s) {
            ambiguous = amb;
            sol = s;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        grid = new char[5][N];
        for (int i = 0; i < 5; i++) {
            String line = br.readLine();
            for (int j = 0; j < N; j++) {
                grid[i][j] = line.charAt(j);
            }
        }
        dp = new DPResult[N + 1][2];
        DPResult resBlack = solve(0, 0);
        DPResult resWhite = solve(0, 1);
        DPResult finalRes = combine(resBlack, resWhite);
        if (finalRes == null || finalRes.ambiguous) {
            System.out.println("UNDETERMINABLE");
        } else {
            System.out.println(finalRes.sol);
        }
    }

    static DPResult combine(DPResult a, DPResult b) {
        if (a == null)
            return b;
        if (b == null)
            return a;
        if (a.ambiguous || b.ambiguous)
            return new DPResult(true, "");
        if (a.sol.equals(b.sol))
            return new DPResult(false, a.sol);
        return new DPResult(true, "");
    }

    static DPResult solve(int pos, int expectedColor) {
        if (pos == N)
            return new DPResult(false, "");
        if (dp[pos][expectedColor] != null)
            return dp[pos][expectedColor];
        DPResult ret = null;
        for (int width = 1; width <= 2; width++) {
            if (pos + width > N)
                continue;
            if (!isValidBar(pos, width, expectedColor))
                continue;
            char digit = (width == 1) ? '0' : '1';
            int nextColor = 1 - expectedColor;
            DPResult nextRes = solve(pos + width, nextColor);
            if (pos + width == N)
                nextRes = new DPResult(false, "");
            if (nextRes == null)
                continue;
            String candidate = digit + nextRes.sol;
            DPResult candidateRes = new DPResult(nextRes.ambiguous, candidate);
            ret = combine(ret, candidateRes);
            if (ret != null && ret.ambiguous)
                break;
        }

        dp[pos][expectedColor] = ret;
        return ret;
    }

    static boolean isValidBar(int start, int width, int expectedColor) {
        char expectedChar = (expectedColor == 0) ? 'X' : '.';
        for (int i = 0; i < 5; i++) {
            for (int j = start; j < start + width; j++) {
                if (grid[i][j] != '?' && grid[i][j] != expectedChar)
                    return false;
            }
        }

        return true;
    }
}