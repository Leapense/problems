import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main
{
    private static class Row {
        final int[] vals = new int[5];
        boolean active = true;
    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out))) {
            
            int t = Integer.parseInt(reader.readLine().trim());
            for (int tc = 1; tc <= t; tc++) {
                writer.write("Case #" + tc + ":\n");
                StringTokenizer st = new StringTokenizer(reader.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken());
                int m = Integer.parseInt(st.nextToken());
                int n = Integer.parseInt(st.nextToken());

                List<Row> table = generateInitialRows(a, b, x, m, n);

                int q = Integer.parseInt(reader.readLine().trim());
                for (int i = 0; i < q; i++) {
                    st = new StringTokenizer(reader.readLine());
                    String cmd = st.nextToken();
                    switch(cmd) {
                        case "insert" -> handleInsert(table, st);
                        case "remove" -> handleRemove(table, st);
                        case "max" -> writer.write(handleMaxMin(table, st, true) + "\n");
                        case "min" -> writer.write(handleMaxMin(table, st, false) + "\n");
                        case "range" -> writer.write(handleRange(table, st) + "\n");
                        default -> {/*None*/}
                    }
                }
            }
            writer.flush();
        }
    }

    private static List<Row> generateInitialRows(int a, int b, int x, int m, int n) {
        List<Row> table = new ArrayList<>(n + 1);
        int[] prevRow = new int[5];
        for (int r = 1; r <= n; r++) {
            Row row = new Row();
            int leftVal = 0;
            for (int c = 0; c < 5; c++) {
                int above = prevRow[c];
                int fromLeft = leftVal;
                int value = (int)(((long) a * above + (long) b * fromLeft + x) % m);
                row.vals[c] = value;
                leftVal = value;
                prevRow[c] = row.vals[c];
            }
            table.add(row);
        }
        return table;
    }

    private static void handleInsert(List<Row> table, StringTokenizer st) {
        Row row = new Row();
        for (int c = 0; c < 5; c++) {
            row.vals[c] = Integer.parseInt(st.nextToken());
        }
        table.add(row);
    }

    private static void handleRemove(List<Row> table, StringTokenizer st) {
        int r = Integer.parseInt(st.nextToken());
        int idx = r - 1;
        if (idx >= 0 && idx < table.size()) {
            Row target = table.get(idx);
            if (target.active) {
                target.active = false;
            }
        }
    }

    private static int handleMaxMin(List<Row> table, StringTokenizer st, boolean findMax) {
        int c = Integer.parseInt(st.nextToken()) - 1;
        int result = findMax ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        for (Row row : table) {
            if (!row.active) {
                continue;
            }
            int v = row.vals[c];
            if (findMax) {
                if (v > result) {
                    result = v;
                }
            } else {
                if (v < result) {
                    result = v;
                }
            }
        }

        return result;
    }

    private static int handleRange(List<Row> table, StringTokenizer st) {
        int c = Integer.parseInt(st.nextToken()) - 1;
        int low = Integer.parseInt(st.nextToken());
        int high = Integer.parseInt(st.nextToken());
        int count = 0;

        for (Row row : table) {
            if (!row.active) {
                continue;
            }

            int v = row.vals[c];
            if (v >= low && v <= high) {
                count++;
            }
        }

        return count;
    }
}