import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int rows = in.nextInt();
            int cols = in.nextInt();
            in.nextLine();                       // consume the EOL after the integers

            String[] output = new String[rows];
            int oddRowIndex = 0;                 // counts only rows with odd padding

            for (int i = 0; i < rows; i++) {
                String word = in.nextLine().trim();
                int extra = cols - word.length();

                int left;
                int right;

                if (extra % 2 == 0) {
                    left = extra / 2;
                    right = left;
                } else {
                    oddRowIndex++;
                    if (oddRowIndex % 2 == 1) {  // 1st, 3rd, 5th …
                        left = extra / 2;
                        right = extra - left;   // right is larger
                    } else {                    // 2nd, 4th, 6th …
                        right = extra / 2;
                        left = extra - right;   // left is larger
                    }
                }

                StringBuilder line = new StringBuilder(cols);
                line.append(".".repeat(left))
                    .append(word)
                    .append(".".repeat(right));
                output[i] = line.toString();
            }

            for (String line : output) {
                System.out.println(line);
            }
        }
    }
}