import java.io.*;
import java.util.*;

public class Main {

    private static class Point {
        int x, y;
        Point(int x, int y) { this.x = x; this.y = y; }
    }

    /* ---------- CONSTANTS ---------- */
    private static final int SIZE = 101;          // 0 … 100 inclusive
    private static final char EMPTY = '.';
    private static final char MORTAL = 'O';
    private static final char MIRROR = 'M';

    /* ---------- GLOBAL (per test-case) ---------- */
    private static char[][] board = new char[SIZE][SIZE];
    private static char[][] orient = new char[SIZE][SIZE];  // orientation if board==MIRROR

    /* ---------- DIRECTION TABLE ---------- */
    private static final int[] DX = {0, 0, 1, -1};                  // N S E W
    private static final int[] DY = {1, -1, 0, 0};
    private static final String[] DIR_NAME = {"north", "south", "east", "west"};
    private static final char[] NEED_MIRROR = {'S', 'N', 'W', 'E'}; // see rule table above
    private static final int NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3;

    /* ========================================================= */
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();
        int caseNo = 1;

        while (true) {
            int v = fs.nextInt();
            int o = fs.nextInt();
            int m = fs.nextInt();
            if (v == 0 && o == 0 && m == 0) break;

            // clean the board
            for (int i = 0; i < SIZE; i++) Arrays.fill(board[i], EMPTY);

            /* ---------- read vampires ---------- */
            List<Point> vampires = new ArrayList<>();
            for (int i = 0; i < v; i++) {
                int x = fs.nextInt();
                int y = fs.nextInt();
                vampires.add(new Point(x, y));
            }

            /* ---------- read mortals ---------- */
            for (int i = 0; i < o; i++) {
                int x = fs.nextInt();
                int y = fs.nextInt();
                board[x][y] = MORTAL;
            }

            /* ---------- read mirrors ---------- */
            for (int i = 0; i < m; i++) {
                char face = fs.next().charAt(0);  // N S E W
                int x1 = fs.nextInt(), y1 = fs.nextInt();
                int x2 = fs.nextInt(), y2 = fs.nextInt();

                if (x1 == x2) {                   // vertical segment
                    if (y1 > y2) { int t = y1; y1 = y2; y2 = t; }
                    for (int y = y1; y <= y2; y++) {
                        board[x1][y] = MIRROR;
                        orient[x1][y] = face;
                    }
                } else {                          // horizontal segment
                    if (x1 > x2) { int t = x1; x1 = x2; x2 = t; }
                    for (int x = x1; x <= x2; x++) {
                        board[x][y1] = MIRROR;
                        orient[x][y1] = face;
                    }
                }
            }

            /* ---------- analyse vampires ---------- */
            List<String> embarrassed = new ArrayList<>();

            for (int idx = 0; idx < vampires.size(); idx++) {
                Point p = vampires.get(idx);
                List<String> danger = new ArrayList<>();

                for (int dir = 0; dir < 4; dir++) {
                    int cx = p.x + DX[dir];
                    int cy = p.y + DY[dir];

                    while (inside(cx, cy)) {
                        if (board[cx][cy] == MORTAL) break;          // blocked
                        if (board[cx][cy] == MIRROR) {
                            if (orient[cx][cy] == NEED_MIRROR[dir])  // correct face?
                                danger.add(DIR_NAME[dir]);
                            break;                                   // blocked anyway
                        }
                        cx += DX[dir];
                        cy += DY[dir];
                    }
                }

                if (!danger.isEmpty()) {
                    embarrassed.add(buildLine(idx + 1, danger));
                }
            }

            /* ---------- output ---------- */
            out.append("Case ").append(caseNo++).append(":\n");
            if (embarrassed.isEmpty()) {
                out.append("none\n");
            } else {
                for (String s : embarrassed) out.append(s).append('\n');
            }
        }

        System.out.print(out.toString());
    }

    /* ---------- helpers ---------- */
    private static boolean inside(int x, int y) {
        return 0 <= x && x < SIZE && 0 <= y && y < SIZE;
    }

    private static String buildLine(int vampireNo, List<String> dirs) {
        StringBuilder sb = new StringBuilder();
        sb.append("vampire ").append(vampireNo).append(' ');
        // dirs are already added in alphabetical order by construction (N,S,E,W → east, north, south, west)
        // Need to output alphabetical: east, north, south, west
        // We'll copy them into that order.
        boolean first = true;
        for (String d : List.of("east", "north", "south", "west")) {
            if (dirs.contains(d)) {
                if (!first) sb.append(' ');
                sb.append(d);
                first = false;
            }
        }
        return sb.toString();
    }

    /* ---------- ultra-simple fast scanner ---------- */
    private static class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int len = 0, ptr = 0;
        private final InputStream in;
        FastScanner(InputStream in) { this.in = in; }
        private int readByte() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }
        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            int c;
            while ((c = readByte()) != -1 && c <= ' ') ;
            if (c == -1) return null;
            do { sb.append((char)c); } while ((c = readByte()) > ' ');
            return sb.toString();
        }
        int nextInt() throws IOException { return Integer.parseInt(next()); }
    }
}