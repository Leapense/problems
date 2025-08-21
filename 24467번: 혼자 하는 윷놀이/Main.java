import java.io.*;

public class Main {
    private static final int[] OUTER_PATH = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    private static final int[] SHORTCUT_5 = {5, 21, 22, 23, 24, 25, 26, 27, 20};
    private static final int[] SHORTCUT_10 = {10, 28, 24, 25, 26, 27, 20};
    private static final int[] SHORTCUT_22 = {22, 23, 24, 25, 26, 27, 20};

    private static class Position {
        int pathType;
        int index;

        Position(int pathType, int index) {
            this.pathType = pathType;
            this.index = index;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Position currentPos = new Position(0, 0);
        int turnCount = 0;
        boolean isWin = false;

        while (turnCount < 10) {
            turnCount++;
            boolean turnEnd = false;

            while (!turnEnd) {
                String yut = br.readLine();
                int move = calculateMove(yut);

                currentPos = movePosition(currentPos, move);
                if (isFinished(currentPos)) {
                    isWin = true;
                }
                if (!yut.equals("0000") && !yut.equals("1111")) {
                    turnEnd = true;
                }
            }
        }

        System.out.println(isWin ? "WIN" : "LOSE");
    }

    private static int calculateMove(String yut) {
        int backCount = 0;
        for (char c : yut.toCharArray()) {
            if (c == '0') backCount++;
        }

        if (backCount == 0) return 5;
        if (backCount == 4) return 4;
        return backCount;
    }

    private static Position movePosition(Position pos, int move) {
        if (isFinished(pos)) {
            return pos;
        }

        int newPathType = pos.pathType;
        int newIndex = pos.index;

        for (int i = 0; i < move; i++) {
            if (newPathType == 0) {
                newIndex++;
                if (newIndex >= OUTER_PATH.length) {
                    newIndex = OUTER_PATH.length;
                    break;
                }

                if (newIndex < OUTER_PATH.length) {
                    int value = OUTER_PATH[newIndex];
                    if (i == move - 1) {
                        if (value == 5) {
                            newPathType = 1;
                            newIndex = 0;
                        } else if (value == 10) {
                            newPathType = 2;
                            newIndex = 0;
                        }
                    }
                }
            } else if (newPathType == 1) {
                newIndex++;
                if (newIndex >= SHORTCUT_5.length) {
                    newPathType = 0;
                    newIndex = OUTER_PATH.length;
                    break;
                }
            } else if (newPathType == 2) {
                newIndex++;
                if (newIndex >= SHORTCUT_10.length) {
                    newPathType = 0;
                    newIndex = OUTER_PATH.length;
                    break;
                }
            } else if (newPathType == 3) {
                newIndex++;
                if (newIndex >= SHORTCUT_22.length) {
                    newPathType = 0;
                    newIndex = OUTER_PATH.length;
                    break;
                }
            }

            if (newPathType == 1 && newIndex > 0 && newIndex < SHORTCUT_5.length) {
                int value = SHORTCUT_5[newIndex];
                if (value == 22 && i == move - 1) {
                    newPathType = 3;
                    newIndex = 0;
                }
            }
        }
        return new Position(newPathType, newIndex);
    }

    private static boolean isFinished(Position pos) {
        return pos.pathType == 0 && pos.index >= OUTER_PATH.length;
    }
}