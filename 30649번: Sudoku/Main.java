import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[][] board = new char[9][9];
        int row = 0;

        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            if (line.startsWith("|")) {
                String part1 = line.substring(1, 4);
                String part2 = line.substring(5, 8);
                String part3 = line.substring(9, 12);
                String rowData = part1 + part2 + part3;

                board[row] = rowData.toCharArray();
                row++;
            }
        }

        boolean error = false;

        for (int i = 0; i < 9 && !error; i++) {
            boolean[] seen = new boolean[10];
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int num = c - '0';
                    if (seen[num]) {
                        error = true;
                        break;
                    }
                    seen[num] = true;
                }
            }
        }

        for (int j = 0; j < 9 && !error; j++) {
            boolean[] seen = new boolean[10];
            for (int i = 0; i < 9; i++) {
                char c = board[i][j];
                if (c != '.') {
                    int num = c - '0';
                    if (seen[num]) {
                        error = true;
                        break;
                    }
                    seen[num] = true;
                }
            }
        }

        for (int blockRow = 0; blockRow < 3 && !error; blockRow++) {
            for (int blockCol = 0; blockCol < 3 && !error; blockCol++) {
                boolean[] seen = new boolean[10];
                for (int i = 0; i < 3 && !error; i++) {
                    for (int j = 0; j < 3; j++) {
                        int r = blockRow * 3 + i;
                        int c = blockCol * 3 + j;
                        char ch = board[r][c];
                        if (ch != '.') {
                            int num = ch - '0';
                            if (seen[num]) {
                                error = true;
                                break;
                            }
                            seen[num] = true;
                        }
                    }
                }
            }
        }

        System.out.println(error ? "GRESKA" : "OK");
    }
}