import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static String key;
    private static int K;
    private static int X;
    private static int Z;
    private static List<String> results;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        K = scanner.nextInt();
        scanner.nextLine();
        key = scanner.nextLine();
        X = scanner.nextInt();
        Z = scanner.nextInt();

        results = new ArrayList<>();
        boolean[] selected = new boolean[K];
        findCombinations(0, 0, 0, selected);

        for (String result : results) {
            System.out.println(result);
        }

        scanner.close();
    }

    private static void findCombinations(int position, int count, int currentSum, boolean[] selected) {
        if (count == X) {
            if (currentSum == Z) {
                StringBuilder cipher = new StringBuilder();
                for (int i = 0; i < K; i++) {
                    cipher.append(selected[i] ? '1' : '0');
                }
                results.add(cipher.toString());
            }

            return;
        }

        if (position >= K || count + (K - position) < X) {
            return;
        }

        int digit = key.charAt(position) - '0';

        selected[position] = true;
        findCombinations(position + 1, count + 1, currentSum + digit, selected);
        selected[position] = false;

        findCombinations(position + 1, count, currentSum, selected);
    }
}