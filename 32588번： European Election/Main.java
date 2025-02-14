import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[][] ballots = new int[n][k + 1];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken());

            Arrays.fill(ballots[i], v + 1);
            for (int j = 1; j <= v; j++) {
                int candidate = Integer.parseInt(st.nextToken());
                ballots[i][candidate] = j;
            }
        }

        boolean[] possibleWinner = new boolean[k + 1];
        Arrays.fill(possibleWinner, true);

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                if (i == j)
                    continue;
                int wins = 0;
                int losses = 0;

                for (int b = 0; b < n; b++) {
                    if (ballots[b][i] < ballots[b][j]) {
                        wins++;
                    } else if (ballots[b][j] < ballots[b][i]) {
                        losses++;
                    }
                }

                if (wins <= losses) {
                    possibleWinner[i] = false;
                    break;
                }
            }
        }

        int winner = -1;

        for (int i = 1; i <= k; i++) {
            if (possibleWinner[i]) {
                if (winner == -1) {
                    winner = i;
                } else {
                    System.out.println("impossible");
                    return;
                }
            }
        }

        if (winner == -1)
            System.out.println("impossible");
        else
            System.out.println(winner);
    }
}