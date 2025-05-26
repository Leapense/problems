import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main
{
    public static final int[] DX = {1, 2, 2, 1, -1, -2, -2, -1};
    public static final int[] DY = {2, 1, -1, -2, -2, -1, 1, 2};

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine().trim());
        StringBuilder output = new StringBuilder();

        for (int tc = 1; tc <= n; tc++) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());

            var solver = new KnightTourSolver(p, q);
            String result = solver.findTour();
            output.append("Scenario #").append(tc).append(":\n");
            output.append(result).append("\n\n");
        }

        System.out.print(output);
    }
}

class KnightTourSolver {
    private final int rows;
    private final int cols;
    private final boolean[][] visited;
    private final List<String> path;
    private boolean found;

    KnightTourSolver(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.visited = new boolean[rows][cols];
        this.path = new ArrayList<>(rows * cols);
        this.found = false;
    }

    String findTour() {
        int total = rows * cols;
        for (int r = 0; r < rows && !found; r++) {
            for (int c = 0; c < cols && !found; c++) {
                backtrack(r, c, total);
            }
        }

        if (!found) {
            return "impossible";
        }
        var sb = new StringBuilder();
        for (String sq : path) {
            sb.append(sq);
        }

        return sb.toString();
    }

    private void backtrack(int r, int c, int total) {
        if (found || visited[r][c]) {
            return;
        }

        visited[r][c] = true;
        path.add(encode(r, c));

        if (path.size() == total) {
            found = true;
            return;
        }

        List<Move> moves = validMoves(r, c);
        Collections.sort(moves);

        for (Move m : moves) {
            if (found) {
                break;
            }

            backtrack(m.r, m.c, total);
        }

        if (found) {
            return;
        }
        visited[r][c] = false;
        path.remove(path.size() - 1);
    }

    private List<Move> validMoves(int r, int c) {
        var list = new ArrayList<Move>();
        for (int i = 0; i < 8; i++) {
            int nr = r + Main.DY[i];
            int nc = c + Main.DX[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                list.add(new Move(nr, nc, encode(nr, nc)));
            }
        }

        return list;
    }

    private static String encode(int r, int c) {
        char colChar = (char) ('A' + c);
        int rowNum = r + 1;
        return "" + colChar + rowNum;
    }

    private static class Move implements Comparable<Move> {
        final int r;
        final int c;
        final String name;

        Move(int r, int c, String name) {
            this.r = r;
            this.c = c;
            this.name = name;
        }

        @Override
        public int compareTo(Move other) {
            return this.name.compareTo(other.name);
        }
    }
}