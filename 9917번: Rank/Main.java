import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        int numberOfPlayers = scanner.nextInt();
        int numberOfGames = scanner.nextInt();

        boolean[][] reach = new boolean[numberOfPlayers + 1][numberOfPlayers + 1];

        for (int game = 0; game < numberOfGames; game++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int scoreA = scanner.nextInt();
            int scoreB = scanner.nextInt();

            if (scoreA > scoreB) {
                reach[a][b] = true;
            } else if (scoreB > scoreA) {
                reach[b][a] = true;
            }
        }

        for (int k = 1; k <= numberOfPlayers; k++) {
            for (int i = 1; i <= numberOfPlayers; i++) {
                if (!reach[i][k]) {
                    continue;
                }

                for (int j = 1; j <= numberOfPlayers; j++) {
                    if (reach[k][j]) reach[i][j] = true;
                }
            }
        }

        boolean[] isInCycle = new boolean[numberOfPlayers + 1];
        for (int i = 1; i <= numberOfPlayers; i++) {
            for (int j = i + 1; j <= numberOfPlayers; j++) {
                if (reach[i][j] && reach[j][i]) {
                    isInCycle[i] = true;
                    isInCycle[j] = true;
                }
            }
        }

        int count = 0;
        for (int i = 1; i <= numberOfPlayers; i++) {
            if (isInCycle[i]) {
                count++;
            }
        }

        System.out.println(count);

        scanner.close();
    }
}