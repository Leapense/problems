import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

public class Main {
    private static final char WHITE = 'V';
    private static final char BLACK = 'S';
    private static final char EMPTY = '.';

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in, StandardCharsets.UTF_8));
        String first = readNonEmptyLine(reader);
        int n = Integer.parseInt(first.trim());
        char[][] grid = new char[n][n];
        for (int i = 0; i < n; i++) {
            String line = readNonEmptyLine(reader);
            while (line.length() < n) {
                String extra = reader.readLine();
                if (extra == null) {
                    break;
                }
                line = line + extra;
            }

            String trimmed = line.trim();
            grid[i] = trimmed.toCharArray();
        }

        Context ctx = buildContext(n, grid);
        Solution sol = solve(ctx);
        if (sol == null) {
            System.out.println();
            System.out.println();
            return;
        }

        StringBuilder orderBuilder = new StringBuilder();
        StringBuilder colorBuilder = new StringBuilder();
        for (int id : sol.topoOrder) {
            if (ctx.isRow[id]) {
                orderBuilder.append(ctx.indexForLine[id] + 1);
            } else {
                orderBuilder.append((char)('A' + ctx.indexForLine[id]));
            }

            colorBuilder.append(sol.assignedColors[id]);
        }
        System.out.println(orderBuilder.toString());
        System.out.println(colorBuilder.toString());
    }

    private static String readNonEmptyLine(BufferedReader reader) throws Exception {
        String s = reader.readLine();
        while (s != null && s.trim().isEmpty()) {
            s = reader.readLine();
        }

        return s == null ? "" : s;
    }

    private static Context buildContext(int n, char[][] grid) {
        boolean[] rowPaintable = new boolean[n];
        boolean[] colPaintable = new boolean[n];
        Arrays.fill(rowPaintable, true);
        Arrays.fill(colPaintable, true);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == EMPTY) {
                    rowPaintable[i] = false;
                    colPaintable[j] = false;
                }
            }
        }

        char[] rowForced = new char[n];
        char[] colForced = new char[n];
        Arrays.fill(rowForced, '?');
        Arrays.fill(colForced, '?');

        for (int i = 0; i < n; i++) {
            if (!rowPaintable[i]) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (!colPaintable[j]) {
                    char t = grid[i][j];
                    if (rowForced[i] == '?') {
                        rowForced[i] = t;
                    } else if (rowForced[i] != t) {
                        rowForced[i] = '\0';
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (!colPaintable[j]) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                if (!rowPaintable[i]) {
                    char t = grid[i][j];
                    if (colForced[j] == '?') {
                        colForced[j] = t;
                    } else if (colForced[j] != t) {
                        colForced[j] = '\0';
                    }
                }
            }
        }

        int[] rowToLineId = new int[n];
        int[] colToLineId = new int[n];
        Arrays.fill(rowToLineId, -1);
        Arrays.fill(colToLineId, -1);

        int lineCount = 0;
        for (int i = 0; i < n; i++) {
            if (rowPaintable[i]) {
                rowToLineId[i] = lineCount++;
            }
        }

        for (int j = 0; j < n; j++) {
            if (colPaintable[j]) {
                colToLineId[j] = lineCount++;
            }
        }

        boolean[] isRow = new boolean[lineCount];
        int[] indexForLine = new int[lineCount];
        char[] forcedColor = new char[lineCount];
        Arrays.fill(forcedColor, '?');

        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (rowPaintable[i]) {
                isRow[idx] = true;
                indexForLine[idx] = i;
                char f = rowForced[i];
                if (f == WHITE || f == BLACK) {
                    forcedColor[idx] = f;
                }
                idx++;
            }
        }

        for (int j = 0; j < n; j++) {
            if (colPaintable[j]) {
                isRow[idx] = false;
                indexForLine[idx] = j;
                char f = colForced[j];
                if (f == WHITE || f == BLACK) {
                    forcedColor[idx] = f;
                }

                idx++;
            }
        }

        Context ctx = new Context();
        ctx.n = n;
        ctx.grid = grid;
        ctx.rowPaintable = rowPaintable;
        ctx.colPaintable = colPaintable;
        ctx.rowToLineId = rowToLineId;
        ctx.colToLineId = colToLineId;
        ctx.isRow = isRow;
        ctx.indexForLine = indexForLine;
        ctx.forcedColor = forcedColor;
        ctx.lineCount = lineCount;
        return ctx;
    }

    private static Solution solve(Context ctx) {
        if (ctx.lineCount == 0) {
            if (allDots(ctx.grid)) {
                Solution s = new Solution();
                s.topoOrder = new int[0];
                s.assignedColors = new char[0];
                return s;
            }

            return null;
        }

        int[] order = buildAssignmentOrder(ctx.forcedColor);
        char[] assigned = new char[ctx.lineCount];
        Arrays.fill(assigned, '?');

        List<Integer> topoOrderHolder = new ArrayList<>();
        boolean ok = backtrackAssign(0, order, assigned, ctx, topoOrderHolder);
        if (!ok) {
            return null;
        }

        Solution s = new Solution();
        s.topoOrder = topoOrderHolder.stream().mapToInt(Integer::intValue).toArray();
        s.assignedColors = assigned.clone();
        return s;
    }

    private static int[] buildAssignmentOrder(char[] forcedColor) {
        List<Integer> forced = new ArrayList<>();
        List<Integer> free = new ArrayList<>();
        for (int i = 0; i < forcedColor.length; i++) {
            if (forcedColor[i] == WHITE || forcedColor[i] == BLACK) {
                forced.add(i);
            } else {
                free.add(i);
            }
        }
        int[] order = new int[forced.size() + free.size()];
        int p = 0;
        for (int v : forced) {
            order[p++] = v;
        }
        for (int v : free) {
            order[p++] = v;
        }

        return order;
    }

    private static boolean backtrackAssign(int pos, int[] order, char[] assigned, Context ctx, List<Integer> topoOrderHolder) {
        if (pos == order.length) {
            int[] topo = buildTopoOrderOrNull(ctx, assigned);
            if (topo == null) {
                return false;
            }
            topoOrderHolder.clear();
            for (int v : topo) {
                topoOrderHolder.add(v);
            }

            return true;
        }

        int line = order[pos];
        char forced = ctx.forcedColor[line];
        if (forced == WHITE || forced == BLACK) {
            assigned[line] = forced;
            if (isPartialConsistent(ctx, assigned)) {
                if (backtrackAssign(pos + 1, order, assigned, ctx, topoOrderHolder)) {
                    return true;
                }
            }
            assigned[line] = '?';
            return false;
        }

        assigned[line] = WHITE;
        if (isPartialConsistent(ctx, assigned)) {
            if (backtrackAssign(pos + 1, order, assigned, ctx, topoOrderHolder)) {
                return true;
            }
        }

        assigned[line] = BLACK;
        if (isPartialConsistent(ctx, assigned)) {
            if (backtrackAssign(pos + 1, order, assigned, ctx, topoOrderHolder)) {
                return true;
            }
        }

        assigned[line] = '?';
        return false;
    }

    private static boolean isPartialConsistent(Context ctx, char[] assigned) {
        int n = ctx.n;
        for (int i = 0; i < n; i++) {
            int r = ctx.rowToLineId[i];
            boolean rPaint = r != -1;
            for (int j = 0; j < n; j++) {
                int c = ctx.colToLineId[j];
                boolean cPaint = c != -1;
                char t = ctx.grid[i][j];

                if (!rPaint && !cPaint) {
                    if (t != EMPTY) {
                        return false;
                    }
                    continue;
                }
                if (rPaint && !cPaint) {
                    char rc = assigned[r];
                    if (rc != '?' && rc != t) {
                        return false;
                    }
                    continue;
                }
                if (!rPaint && cPaint) {
                    char cc = assigned[c];
                    if (cc != '?' && cc != t) {
                        return false;
                    }
                    continue;
                }

                char rc = assigned[r];
                char cc = assigned[c];
                if (rc != '?' && cc != '?') {
                    if (rc != t && cc != t) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    private static int[] buildTopoOrderOrNull(Context ctx, char[] assigned) {
        int n = ctx.n;
        int m = ctx.lineCount;
        List<List<Integer>> adj = new ArrayList<>(m);
        for (int i = 0; i < m; i++) {
            adj.add(new ArrayList<>());
        }

        int[] indeg = new int[m];

        for (int i = 0; i < n; i++) {
            int r = ctx.rowToLineId[i];
            boolean rPaint = r != -1;
            for (int j = 0; j < n; j++) {
                int c = ctx.colToLineId[j];
                boolean cPaint = c != -1;
                char t = ctx.grid[i][j];

                if (!rPaint && !cPaint) {
                    if (t != EMPTY) {
                        return null;
                    }
                    continue;
                }
                if (rPaint && !cPaint) {
                    if (assigned[r] != t) {
                        return null;
                    }
                    continue;
                }
                if (!rPaint && cPaint) {
                    if (assigned[c] != t) {
                        return null;
                    }
                    continue;
                }

                char rc = assigned[r];
                char cc = assigned[c];
                if (rc == t && cc == t) {
                    continue;
                } else if (rc == t && cc != t) {
                    adj.get(c).add(r);
                    indeg[r]++;
                } else if (cc == t && rc != t) {
                    adj.get(r).add(c);
                    indeg[c]++;
                } else {
                    return null;
                }
            }
        }

        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 0; i < m; i++) {
            if (indeg[i] == 0) {
                dq.add(i);
            }
        }
        int[] order = new int[m];
        int p = 0;
        while (!dq.isEmpty()) {
            int v = dq.removeFirst();
            order[p++] = v;
            for (int nx : adj.get(v)) {
                indeg[nx]--;
                if (indeg[nx] == 0) {
                    dq.addLast(nx);
                }
            }
        }

        if (p != m) {
            return null;
        }
        return order;
    }

    private static boolean allDots(char[][] grid) {
        for (char[] row : grid) {
            for (char ch : row) {
                if (ch != EMPTY) {
                    return false;
                }
            }
        }

        return true;
    }

    private static final class Context {
        int n;
        char[][] grid;
        boolean[] rowPaintable;
        boolean[] colPaintable;
        int[] rowToLineId;
        int[] colToLineId;
        boolean[] isRow;
        int[] indexForLine;
        char[] forcedColor;
        int lineCount;
    }

    private static final class Solution {
        int[] topoOrder;
        char[] assignedColors;
    }
}