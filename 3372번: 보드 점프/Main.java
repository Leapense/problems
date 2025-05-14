import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    static int N;
    static int[][] board;
    static BigInteger[][] dp;

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        
        board = new int[N][N];
        dp = new BigInteger[N][N];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                board[i][j] = sc.nextInt();
            }
        }

        BigInteger result = countPaths(0, 0);
        System.out.println(result);

        sc.close();
    }

    static BigInteger countPaths(int r, int c)
    {
        if (r >= N || c >= N)
        {
            return BigInteger.ZERO;
        }

        if (r == N - 1 && c == N - 1)
        {
            return BigInteger.ONE;
        }

        if (dp[r][c] != null)
        {
            return dp[r][c];
        }

        int jumpDistance = board[r][c];

        if (jumpDistance == 0)
        {
            dp[r][c] = BigInteger.ZERO;
            return BigInteger.ZERO;
        }

        BigInteger pathsFromCurrentCeil = BigInteger.ZERO;

        int nextRow = r + jumpDistance;

        pathsFromCurrentCeil = pathsFromCurrentCeil.add(countPaths(nextRow, c));

        int nextCol = c + jumpDistance;

        pathsFromCurrentCeil = pathsFromCurrentCeil.add(countPaths(r, nextCol));

        dp[r][c] = pathsFromCurrentCeil;
        return pathsFromCurrentCeil;
    }
}