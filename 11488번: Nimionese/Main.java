import java.util.*;
import java.io.*;

public class Main {
    static final char[] HARD = { 'b', 'c', 'd', 'g', 'k', 'n', 'p', 't' };
    static final String[] SUFFIXES = { "ah", "oh", "uh" };
    static final int[] VOWEL_POS = { 1, 15, 21 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        String[] words = input.split(" ");
        StringBuilder result = new StringBuilder();
        for (int w = 0; w < words.length; w++) {
            if (words[w].isEmpty())
                continue;
            String nimWord = processWord(words[w]);
            result.append(nimWord);
            if (w < words.length - 1)
                result.append(" ");
        }

        System.out.println(result.toString());
    }

    static String processWord(String word) {
        String[] syllables = word.split("-");
        boolean isUpper = Character.isUpperCase(syllables[0].charAt(0));
        char firstLetter = syllables[0].charAt(0);
        char newFirst = getNearestHard(Character.toLowerCase(firstLetter));
        StringBuilder firstSyllable = new StringBuilder();
        firstSyllable.append(newFirst);
        if (syllables[0].length() > 1) {
            firstSyllable.append(syllables[0].substring(1).toLowerCase());
        }
        String startingHard = String.valueOf(newFirst);

        StringBuilder wordBuilder = new StringBuilder();
        wordBuilder.append(firstSyllable);

        for (int i = 1; i < syllables.length; i++) {
            StringBuilder current = new StringBuilder();
            for (char ch : syllables[i].toCharArray()) {
                char lower = Character.toLowerCase(ch);
                if (isHard(lower)) {
                    current.append(startingHard);
                } else {
                    current.append(lower);
                }
            }

            wordBuilder.append(current);
        }

        String processed = wordBuilder.toString();
        if (!processed.isEmpty() && isHard(processed.charAt(processed.length() - 1))) {
            char lastHard = ' ';
            for (int i = processed.length() - 1; i >= 0; i--) {
                if (isHard(processed.charAt(i))) {
                    lastHard = processed.charAt(i);
                    break;
                }
            }

            String suffix = chooseSuffix(lastHard);
            processed += suffix;
        }

        if (isUpper) {
            processed = Character.toUpperCase(processed.charAt(0)) + processed.substring(1);
        }

        return processed;
    }

    static char getNearestHard(char ch) {
        int pos = ch - 'a' + 1;
        char best = HARD[0];
        int bestDist = Math.abs(pos - (HARD[0] - 'a' + 1));
        for (char candidate : HARD) {
            int candidatePos = candidate - 'a' + 1;
            int dist = Math.abs(pos - candidatePos);
            if (dist < bestDist || (dist == bestDist && candidate < best)) {
                best = candidate;
                bestDist = dist;
            }
        }

        return best;
    }

    static boolean isHard(char ch) {
        for (char hc : HARD) {
            if (hc == ch)
                return true;
        }
        return false;
    }

    static String chooseSuffix(char lastHard) {
        int pos = lastHard - 'a' + 1;
        int bestDiff = Integer.MAX_VALUE;
        String bestSuffix = "";
        for (int i = 0; i < SUFFIXES.length; i++) {
            int diff = Math.abs(pos - VOWEL_POS[i]);
            if (diff < bestDiff || (diff == bestDiff && VOWEL_POS[i] < (bestSuffix.isEmpty() ? Integer.MAX_VALUE
                    : VOWEL_POS[Arrays.asList(SUFFIXES).indexOf(bestSuffix)]))) {
                bestDiff = diff;
                bestSuffix = SUFFIXES[i];
            }
        }

        return bestSuffix;
    }
}