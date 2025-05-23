import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int R = sc.nextInt();
        int K = sc.nextInt();
        sc.nextLine();
        String generation = sc.nextLine();

        for (int k = 0; k < K; k++) {
            StringBuilder nextGeneration = new StringBuilder();

            for (int i = 0; i < generation.length(); i++) {
                int left = (i == 0) ? 0 : (generation.charAt(i - 1) == 'X' ? 1 : 0);
                int center = (generation.charAt(i) == 'X' ? 1 : 0);
                int right = (i == generation.length() - 1) ? 0 : (generation.charAt(i + 1) == 'X' ? 1 : 0);

                int pattern = left * 4 + center * 2 + right;
                int newState = (R >> pattern) & 1;
                nextGeneration.append(newState == 1 ? 'X' : '.');
            }

            System.out.println(nextGeneration.toString());
            generation = nextGeneration.toString();
        }

        sc.close();
    }
}