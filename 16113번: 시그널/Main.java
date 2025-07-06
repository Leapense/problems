import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public final class Main {
    private static final int ROWS = 5;
    private static final int COLS_PER_FULL_DIGIT = 3;
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        String raw = in.readLine();
        int width = n / ROWS;
        char[][] grid = new char[ROWS][width];
        for (int r = 0, idx = 0; r < ROWS; r++) {
            for (int c = 0; c < width; c++, idx++) {
                grid[r][c] = raw.charAt(idx);
            }
        }

        Map<String, Character> patterns = buildPatterns();
        StringBuilder answer = new StringBuilder();
        int c = 0;

        while (c < width) {
            if (grid[0][c] == '.') {
                c++;
                continue;
            }
            if (isDigitOne(grid, c, width)) {
                answer.append('1');
                c++;
            } else {
                String key = buildKey(grid, c);
                answer.append(patterns.get(key));
                c += COLS_PER_FULL_DIGIT;
            }
        }

        System.out.println(answer);
    }

    private static Map<String, Character> buildPatterns() {
        Map<String, Character> map = new HashMap<>();
        map.put(join("###", "#.#", "#.#", "#.#", "###"), '0');
        map.put(join("###", "..#", "###", "#..", "###"), '2');
        map.put(join("###", "..#", "###", "..#", "###"), '3');
        map.put(join("#.#", "#.#", "###", "..#", "..#"), '4');
        map.put(join("###", "#..", "###", "..#", "###"), '5');
        map.put(join("###", "#..", "###", "#.#", "###"), '6');
        map.put(join("###", "..#", "..#", "..#", "..#"), '7');
        map.put(join("###", "#.#", "###", "#.#", "###"), '8');
        map.put(join("###", "#.#", "###", "..#", "###"), '9');
        return map;
    }

    private static boolean isDigitOne(char[][] grid, int col, int width) {
        if (col + 1 < width) {
            for (int r = 0; r < ROWS; r++) {
                if (grid[r][col + 1] == '#') {
                    return false;
                }
            }
        }

        for (int r = 0; r < ROWS; r++) {
            if (grid[r][col] != '#') {
                return false;
            }
        }

        return true;
    }

    private static String buildKey(char[][] grid, int startCol) {
        StringBuilder key = new StringBuilder(15);
        for (int r = 0; r < ROWS; r++) {
            for (int c = startCol; c < startCol + COLS_PER_FULL_DIGIT; c++) {
                key.append(grid[r][c]);
            }
        }

        return key.toString();
    }

    private static String join(String a, String b, String c, String d, String e) {
        return a + b + c + d + e;
    }
}