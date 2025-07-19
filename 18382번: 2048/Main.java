import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int score = Integer.parseInt(reader.readLine().trim());
        String moves = reader.readLine().trim();
        String[] cellData = reader.readLine().trim().split(" ");
        int[][] grid = new int[4][4];
        for (int i = 0; i < 16; i++) {
            grid[i / 4][i % 4] = Integer.parseInt(cellData[i]);
        }
        int moveCount = moves.length() / 4;
        for (int k = 0; k < moveCount; k++) {
            int base = k * 4;
            char direction = moves.charAt(base);
            int value = moves.charAt(base + 1) - '0';
            int row = moves.charAt(base + 2) - '0';
            int col = moves.charAt(base + 3) - '0';
            switch (direction) {
                case 'L':
                    score += slideLeft(grid);
                    break;
                case 'R':
                    score += slideRight(grid);
                    break;
                case 'U':
                    score += slideUp(grid);
                    break;
                case 'D':
                    score += slideDown(grid);
                    break;
                default:
                    break;
            }
            grid[row][col] = value;
        }
        System.out.println(score);
    }

    private static int slideLeft(int[][] grid) {
        int gained = 0;
        for (int i = 0; i < 4; i++) {
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] != 0) {
                    list.add(grid[i][j]);
                }
            }
            List<Integer> merged = new ArrayList<>();
            for (int j = 0; j < list.size(); j++) {
                if (j + 1 < list.size() && list.get(j).equals(list.get(j + 1))) {
                    int v = list.get(j) * 2;
                    gained += v;
                    merged.add(v);
                    j++;
                } else {
                    merged.add(list.get(j));
                }
            }
            for (int j = 0; j < merged.size(); j++) {
                grid[i][j] = merged.get(j);
            }
            for (int j = merged.size(); j < 4; j++) {
                grid[i][j] = 0;
            }
        }
        return gained;
    }

    private static int slideRight(int[][] grid) {
        int gained = 0;
        for (int i = 0; i < 4; i++) {
            List<Integer> list = new ArrayList<>();
            for (int j = 3; j >= 0; j--) {
                if (grid[i][j] != 0) {
                    list.add(grid[i][j]);
                }
            }
            List<Integer> merged = new ArrayList<>();
            for (int j = 0; j < list.size(); j++) {
                if (j + 1 < list.size() && list.get(j).equals(list.get(j + 1))) {
                    int v = list.get(j) * 2;
                    gained += v;
                    merged.add(v);
                    j++;
                } else {
                    merged.add(list.get(j));
                }
            }
            for (int j = 0; j < merged.size(); j++) {
                grid[i][3 - j] = merged.get(j);
            }
            for (int j = merged.size(); j < 4; j++) {
                grid[i][3 - j] = 0;
            }
        }
        return gained;
    }

    private static int slideUp(int[][] grid) {
        int gained = 0;
        for (int j = 0; j < 4; j++) {
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < 4; i++) {
                if (grid[i][j] != 0) {
                    list.add(grid[i][j]);
                }
            }
            List<Integer> merged = new ArrayList<>();
            for (int i = 0; i < list.size(); i++) {
                if (i + 1 < list.size() && list.get(i).equals(list.get(i + 1))) {
                    int v = list.get(i) * 2;
                    gained += v;
                    merged.add(v);
                    i++;
                } else {
                    merged.add(list.get(i));
                }
            }
            for (int i = 0; i < merged.size(); i++) {
                grid[i][j] = merged.get(i);
            }
            for (int i = merged.size(); i < 4; i++) {
                grid[i][j] = 0;
            }
        }
        return gained;
    }

    private static int slideDown(int[][] grid) {
        int gained = 0;
        for (int j = 0; j < 4; j++) {
            List<Integer> list = new ArrayList<>();
            for (int i = 3; i >= 0; i--) {
                if (grid[i][j] != 0) {
                    list.add(grid[i][j]);
                }
            }
            List<Integer> merged = new ArrayList<>();
            for (int i = 0; i < list.size(); i++) {
                if (i + 1 < list.size() && list.get(i).equals(list.get(i + 1))) {
                    int v = list.get(i) * 2;
                    gained += v;
                    merged.add(v);
                    i++;
                } else {
                    merged.add(list.get(i));
                }
            }
            for (int i = 0; i < merged.size(); i++) {
                grid[3 - i][j] = merged.get(i);
            }
            for (int i = merged.size(); i < 4; i++) {
                grid[3 - i][j] = 0;
            }
        }
        return gained;
    }
}