import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class FoundLocation {
    private final int row;
    private final int col;
    private final String direction;

    public FoundLocation(int row, int col, String direction) {
        this.row = row;
        this.col = col;
        this.direction = direction;
    }

    @Override
    public String toString() {
        return String.format("(%d,%d) - %s", this.row, this.col, this.direction);
    }
}

class WordSearcher {
    private final char[][] grid;
    private final int size;

    private static final int[] DELTA_ROW = {-1, -1, 0, 1, 1, 1, 0, -1};
    private static final int[] DELTA_COL = {0, 1, 1, 1, 0, -1, -1, -1};
    private static final String[] DIRECTIONS = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};

    public WordSearcher(char[][] grid) {
        this.grid = grid;
        this.size = grid.length;
    }

    public List<FoundLocation> search(String word) {
        List<FoundLocation> foundLocations = new ArrayList<>();
        if (word == null || word.isEmpty()) {
            return foundLocations;
        }

        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                if (grid[r][c] == word.charAt(0)) {
                    for (int i = 0; i < DIRECTIONS.length; i++) {
                        if (checkDirection(word, r, c, i)) {
                            foundLocations.add(new FoundLocation(r + 1, c + 1, DIRECTIONS[i]));
                        }
                    }
                }
            }
        }
        return foundLocations;
    }

    private boolean checkDirection(String word, int startRow, int startCol, int dirIndex) {
        int currentRow = startRow;
        int currentCol = startCol;

        for (int i = 1; i < word.length(); i++) {
            int nextRow = currentRow;
            int nextCol = currentCol;
            boolean charFound = false;

            while (true) {
                nextRow += DELTA_ROW[dirIndex];
                nextCol += DELTA_COL[dirIndex];

                if (nextRow < 0 || nextRow >= size || nextCol < 0 || nextCol >= size) {
                    return false;
                }

                if (grid[nextRow][nextCol] != ' ') {
                    if (grid[nextRow][nextCol] == word.charAt(i)) {
                        currentRow = nextRow;
                        currentCol = nextCol;
                        charFound = true;
                    }
                    break;
                }
            }

            if (!charFound) {
                return false;
            }
        }
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int n = Integer.parseInt(scanner.nextLine());
            char[][] grid = new char[n][n];

            for (int i = 0; i < n; i++) {
                String line = scanner.nextLine();
                for (int j = 0; j < n; j++) {
                    if (j < line.length()) {
                        grid[i][j] = line.charAt(j);
                    } else {
                        grid[i][j] = ' ';
                    }
                }
            }

            WordSearcher searcher = new WordSearcher(grid);

            while (scanner.hasNextLine()) {
                String searchWord = scanner.nextLine();
                if (searchWord.trim().isEmpty()) {
                    continue;
                }

                System.out.println(searchWord);

                List<FoundLocation> results = searcher.search(searchWord);

                if (results.isEmpty()) {
                    System.out.println("not found");
                } else {
                    for (FoundLocation loc : results) {
                        System.out.println(loc);
                    }
                }
                System.out.println();
            }
        }
    }
}