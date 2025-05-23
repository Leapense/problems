import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] guesses = new int[N];
        int[] blacks = new int[N];
        int[] whites = new int[N];

        for (int i = 0; i < N; i++) {
            guesses[i] = sc.nextInt();
            blacks[i] = sc.nextInt();
            whites[i] = sc.nextInt();
        }

        for (int candidate = 1000; candidate <= 9999; candidate++) {
            if (isValid(candidate, guesses, blacks, whites, N)) {
                System.out.println(candidate);
                return;
            }
        }

        System.out.println("NONE");
    }

    public static boolean isValid(int candidate, int[] guesses, int[] blacks, int[] whites, int N) {
        String candidateStr = String.valueOf(candidate);
        for (int i = 0; i < N; i++) {
            String guessStr = String.valueOf(guesses[i]);
            int blackCount = 0;
            for (int j = 0; j < 4; j++) {
                if (candidateStr.charAt(j) == guessStr.charAt(j)) {
                    blackCount++;
                }
            }

            int[] freqCandidate = new int[10];
            int[] freqGuess = new int[10];
            for (int j = 0; j < 4; j++) {
                freqCandidate[candidateStr.charAt(j) - '0']++;
                freqGuess[guessStr.charAt(j) - '0']++;
            }

            int totalMatch = 0;
            for (int d = 0; d < 10; d++) {
                totalMatch += Math.min(freqCandidate[d], freqGuess[d]);
            }

            int whiteCount = totalMatch - blackCount;
            if (blackCount != blacks[i] || whiteCount != whites[i]) {
                return false;
            }
        }

        return true;
    }
}