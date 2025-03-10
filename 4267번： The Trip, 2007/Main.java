import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            if (!sc.hasNextInt())
                break;
            int n = sc.nextInt();
            if (n == 0)
                break;
            int[] bags = new int[n];
            for (int i = 0; i < n; i++) {
                bags[i] = sc.nextInt();
            }

            Arrays.sort(bags);
            int maxFreq = 0, currentFreq = 1;
            for (int i = 1; i < n; i++) {
                if (bags[i] == bags[i - 1]) {
                    currentFreq++;
                } else {
                    maxFreq = Math.max(maxFreq, currentFreq);
                    currentFreq = 1;
                }
            }

            maxFreq = Math.max(maxFreq, currentFreq);
            List<List<Integer>> chains = new ArrayList<>();
            for (int i = 0; i < maxFreq; i++) {
                chains.add(new ArrayList<>());
            }
            for (int i = 0; i < n; i++) {
                chains.get(i % maxFreq).add(bags[i]);
            }
            System.out.println(maxFreq);

            for (List<Integer> chain : chains) {
                StringBuilder sb = new StringBuilder();
                for (int num : chain) {
                    sb.append(num).append(" ");
                }

                System.out.println(sb.toString().trim());
            }
            System.out.println();
        }

        sc.close();
    }
}