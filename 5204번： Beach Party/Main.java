import java.util.*;
import java.io.*;

public class Main {
    static int s, m, n;
    static int[][] preferences;
    static int maxFriends;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int K = Integer.parseInt(br.readLine());

        for (int dataSet = 1; dataSet <= K; dataSet++) {
            String[] parts = br.readLine().split(" ");
            s = Integer.parseInt(parts[0]);
            m = Integer.parseInt(parts[1]);
            n = Integer.parseInt(parts[2]);
            preferences = new int[n][m];
            for (int i = 0; i < n; i++) {
                parts = br.readLine().split(" ");
                for (int j = 0; j < m; j++) {
                    preferences[i][j] = Integer.parseInt(parts[j]);
                }
            }

            maxFriends = 0;
            List<Integer> current = new ArrayList<>();
            generateCombinations(1, current);
            System.out.println("Data Set " + dataSet + ":");
            System.out.println(maxFriends);
        }
    }

    static void generateCombinations(int start, List<Integer> current) {
        if (current.size() == s) {
            simulate(current);
            return;
        }

        for (int i = start; i <= m; i++) {
            current.add(i);
            generateCombinations(i + 1, current);
            current.remove(current.size() - 1);
        }
    }

    static void simulate(List<Integer> chosen) {
        Set<Integer> chosenSet = new HashSet<>(chosen);
        int[] selectedStyle = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (chosenSet.contains(preferences[i][j])) {
                    selectedStyle[i] = preferences[i][j];
                    break;
                }
            }
        }

        int targetStyle = selectedStyle[0];
        int count = 0;
        for (int style : selectedStyle) {
            if (style == targetStyle)
                count++;
        }

        maxFriends = Math.max(maxFriends, count);
    }
}