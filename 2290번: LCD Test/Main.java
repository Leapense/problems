import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        String n = sc.next();
        sc.close();

        boolean[][] segments = {
                { true, true, true, false, true, true, true }, // 0
                { false, false, true, false, false, true, false }, // 1
                { true, false, true, true, true, false, true }, // 2
                { true, false, true, true, false, true, true }, // 3
                { false, true, true, true, false, true, false }, // 4
                { true, true, false, true, false, true, true }, // 5
                { true, true, false, true, true, true, true }, // 6
                { true, false, true, false, false, true, false }, // 7
                { true, true, true, true, true, true, true }, // 8
                { true, true, true, true, false, true, true } // 9
        };

        int rows = 2 * s + 3;
        int colsPerDigit = s + 2;

        StringBuilder[] output = new StringBuilder[rows];
        for (int i = 0; i < rows; i++) {
            output[i] = new StringBuilder();
        }

        for (int d = 0; d < n.length(); d++) {
            int digit = n.charAt(d) - '0';

            for (int row = 0; row < rows; row++) {
                if (row == 0) {
                    output[row].append(" ");
                    output[row].append(segments[digit][0] ? repeatChar('-', s) : repeatChar(' ', s));
                    output[row].append(" ");
                } else if (row > 0 && row < s + 1) {
                    output[row].append(segments[digit][1] ? "|" : " ");
                    output[row].append(repeatChar(' ', s));
                    output[row].append(segments[digit][2] ? "|" : " ");
                } else if (row == s + 1) {
                    output[row].append(" ");
                    output[row].append(segments[digit][3] ? repeatChar('-', s) : repeatChar(' ', s));
                    output[row].append(" ");
                } else if (row > s + 1 && row < rows - 1) {
                    output[row].append(segments[digit][4] ? "|" : " ");
                    output[row].append(repeatChar(' ', s));
                    output[row].append(segments[digit][5] ? "|" : " ");
                } else if (row == rows - 1) {
                    output[row].append(" ");
                    output[row].append(segments[digit][6] ? repeatChar('-', s) : repeatChar(' ', s));
                    output[row].append(" ");
                }

                if (d != n.length() - 1) {
                    output[row].append(" ");
                }
            }
        }

        for (StringBuilder line : output) {
            System.out.println(line.toString());
        }
    }

    private static String repeatChar(char c, int count) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < count; i++) {
            sb.append(c);
        }

        return sb.toString();
    }
}