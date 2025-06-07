import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayDeque;
import java.util.Deque;

public final class Main {
    private static int gridRows;
    private static int gridCols;
    private static int targetEnclosed;
    private static int totalCells;
    private static int bestStones;
    private static boolean[] hasStone;
    private static boolean[] visitedEmpty;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(reader.readLine().trim());

        for (int caseIndex = 1; caseIndex <= testCases; caseIndex++) {
            readTestCase(reader);
            int result = computeMinStones();
            System.out.printf("Case #%d: %d%n", caseIndex, result);
        }
    }

    private static void readTestCase(BufferedReader reader) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        gridRows = Integer.parseInt(tokenizer.nextToken());
        gridCols = Integer.parseInt(tokenizer.nextToken());
        targetEnclosed = Integer.parseInt(tokenizer.nextToken());
        totalCells = gridRows * gridCols;
    }

    private static int computeMinStones() {
        hasStone = new boolean[totalCells];
        visitedEmpty = new boolean[totalCells];

        for (int stones = 0; stones <= targetEnclosed; stones++) {
            bestStones = stones;
            if (tryPlaceStones(0, stones, 0)) {
                return stones;
            }
        }

        return targetEnclosed;
    }

    private static boolean tryPlaceStones(int startIndex, int stonesToPlace, int placedCount) {
        if (placedCount == stonesToPlace) {
            return checkCurrentConfiguration(placedCount);
        }

        int remainingPositions = totalCells - startIndex;
        if (remainingPositions < (stonesToPlace - placedCount)) {
            return false;
        }
        for (int idx = startIndex; idx < totalCells; idx++) {
            hasStone[idx] = true;
            if (tryPlaceStones(idx + 1, stonesToPlace, placedCount + 1)) {
                return true;
            }
            hasStone[idx] = false;
        }

        return false;
    }

    private static boolean checkCurrentConfiguration(int stonesPlaced) {
        int emptyCount = totalCells - stonesPlaced;
        if (stonesPlaced + emptyCount < targetEnclosed) {
            return false;
        }

        for (int i = 0; i < totalCells; i++) {
            visitedEmpty[i] = false;
        }

        Deque<Integer> queue = new ArrayDeque<>();

        for (int r = 0; r < gridRows; r++) {
            enqueueIfEmpty(queue, r, 0);
            enqueueIfEmpty(queue, r, gridCols - 1);
        }
        for (int c = 0; c < gridCols; c++) {
            enqueueIfEmpty(queue, 0, c);
            enqueueIfEmpty(queue, gridRows - 1, c);
        }

        while (!queue.isEmpty()) {
            int pos = queue.removeFirst();
            int row = pos / gridCols;
            int col = pos % gridCols;
            for (int[] delta : DELTAS) {
                int nr = row + delta[0];
                int nc = col + delta[1];
                if (isInBounds(nr, nc)) {
                    int nPos = nr * gridCols + nc;
                    if (!hasStone[nPos] && !visitedEmpty[nPos]) {
                        visitedEmpty[nPos] = true;
                        queue.addLast(nPos);
                    }
                }
            }
        }

        int enclosedCount = stonesPlaced;
        for (int i = 0; i < totalCells; i++) {
            if(!hasStone[i] && !visitedEmpty[i]) {
                enclosedCount++;
                if (enclosedCount >= targetEnclosed) {
                    return true;
                }
            }
        }

        return enclosedCount >= targetEnclosed;
    }

    private static void enqueueIfEmpty(Deque<Integer> queue, int row, int col) {
        int pos = row * gridCols + col;
        if (!hasStone[pos] && !visitedEmpty[pos]) {
            visitedEmpty[pos] = true;
            queue.addLast(pos);
        }
    }

    private static boolean isInBounds(int r, int c) {
        return r >= 0 && r < gridRows && c >= 0 && c < gridCols;
    }

    private static final int[][] DELTAS = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
}