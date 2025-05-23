import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        String baseWord = sc.nextLine().trim();
        int[] baseFreq = getFreq(baseWord);
        int countSimilar = 0;

        for (int i = 1; i < n; i++) {
            String candidate = sc.nextLine().trim();
            int[] candidateFreq = getFreq(candidate);
            if (isSimilar(baseFreq, candidateFreq, baseWord.length(), candidate.length())) {
                countSimilar++;
            }
        }

        System.out.println(countSimilar);
        sc.close();
    }

    private static int[] getFreq(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'A']++;
        }

        return freq;
    }

    private static boolean isSimilar(int[] baseFreq, int[] candidateFreq, int baseLen, int candidateLen) {
        boolean same = true;
        for (int i = 0; i < 26; i++) {
            if (baseFreq[i] != candidateFreq[i]) {
                same = false;
                break;
            }
        }

        if (same)
            return true;

        int lenDiff = Math.abs(baseLen - candidateLen);

        int sumAbsDiff = 0;
        for (int i = 0; i < 26; i++) {
            sumAbsDiff += Math.abs(baseFreq[i] - candidateFreq[i]);
        }

        if (lenDiff == 1 && sumAbsDiff == 1)
            return true;
        if (lenDiff == 0 && sumAbsDiff == 2)
            return true;

        return false;
    }
}