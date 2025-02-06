import java.util.*;
import java.io.*;

public class Main {
    static int bestWins = -1;
    static List<Pair> bestPairs = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int[] bait = new int[3];

        for (int i = 0; i < 3; i++) {
            bait[i] = sc.nextInt();
        }

        int[] s = new int[6];
        for (int i = 0; i < 6; i++) {
            s[i] = sc.nextInt();
        }

        boolean[] used = new boolean[6];
        List<Pair> currentPairs = new ArrayList<>();
        generatePairs(s, bait, used, currentPairs);

        System.out.println(bestWins);
        for (Pair p : bestPairs) {
            System.out.println(p.a + " " + p.b);
        }

        sc.close();
    }

    static void generatePairs(int[] s, int[] bait, boolean[] used, List<Pair> currentPairs) {
        int n = s.length;
        int count = 0;

        for (boolean b : used)
            if (b)
                count++;
        if (count == n) {
            int wins = calculateWins(currentPairs, bait);
            if (wins > bestWins) {
                bestWins = wins;
                bestPairs = new ArrayList<>(currentPairs);
            }

            return;
        }

        int i;
        for (i = 0; i < n; i++) {
            if (!used[i])
                break;
        }

        used[i] = true;

        for (int j = i + 1; j < n; j++) {
            if (!used[j]) {
                used[j] = true;
                currentPairs.add(new Pair(s[i], s[j]));
                generatePairs(s, bait, used, currentPairs);
                currentPairs.remove(currentPairs.size() - 1);
                used[j] = false;
            }
        }

        used[i] = false;
    }

    static int calculateWins(List<Pair> pairs, int[] bait) {
        int wins = 0;
        for (Pair p : pairs) {
            int pairStrength = p.a + p.b;
            for (int b : bait) {
                if (pairStrength > b)
                    wins++;
            }
        }

        return wins;
    }

    static class Pair {
        int a, b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
}