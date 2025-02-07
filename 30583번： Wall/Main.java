import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int K = sc.nextInt();
        sc.nextLine();

        String initialGeneration = sc.nextLine();
        int n = initialGeneration.length();
        char[] current = initialGeneration.toCharArray();

        for (int gen = 0; gen < K; gen++) {
            char[] next = new char[n];
            for (int i = 0; i < n; i++) {
                int left = (i - 1 >= 0 && current[i - 1] == 'X') ? 1 : 0;
                int center = (current[i] == 'X') ? 1 : 0;
                int right = (i + 1 < n && current[i + 1] == 'X') ? 1 : 0;

                int pattern = left * 4 + center * 2 + right;
                int bit = (R >> (7 - pattern)) & 1;
                next[i] = (bit == 1) ? 'X' : '.';
            }

            current = next;
            System.out.println(new String(current));
        }

        sc.close();
    }
}