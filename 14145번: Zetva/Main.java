import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public final class Main {
    private static int rows;
    private static int cols;
    private static char[][] grid;
    private static boolean[][] visited;
    private static final int[] dr = {-1, 1, 0, 0};
    private static final int[] dc = {0, 0, -1, 1};

    private Main() {
        throw new UnsupportedOperationException("This is a utility class and cannot be instantiated");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        rows = Integer.parseInt(st.nextToken());
        cols = Integer.parseInt(st.nextToken());

        grid = new char[rows][cols];
        visited = new boolean[rows][cols];

        for (int i = 0; i < rows; i++) {
            grid[i] = br.readLine().toCharArray();
        }

        List<Field> fields = findFields();
        Collections.sort(fields);

        int[][] resultGrid = createResultGrid(fields);
        printGrid(resultGrid);
    }

    private static List<Field> findFields() {
        List<Field> foundFields = new ArrayList<>();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    foundFields.add(bfs(i, j));
                }
            }
        }

        return foundFields;
    }

    private static Field bfs(int startR, int startC) {
        Queue<Point> queue = new LinkedList<>();
        List<Point> fieldCoordinates = new ArrayList<>();

        queue.add(new Point(startR, startC));
        visited[startR][startC] = true;

        while (!queue.isEmpty()) {
            Point current = queue.poll();
            fieldCoordinates.add(current);

            for (int i = 0; i < 4; i++) {
                int nextR = current.getR() + dr[i];
                int nextC = current.getC() + dc[i];

                if (isValid(nextR, nextC) && grid[nextR][nextC] == '1' && !visited[nextR][nextC]) {
                    visited[nextR][nextC] = true;
                    queue.add(new Point(nextR, nextC));
                }
            }
        }

        return new Field(fieldCoordinates.size(), fieldCoordinates);
    }

    private static int[][] createResultGrid(List<Field> sortedFields) {
        int[][] resultGrid = new int[rows][cols];
        int harvestDay = 1;
        for (Field field : sortedFields) {
            for (Point p : field.getCoordinates()) {
                resultGrid[p.getR()][p.getC()] = harvestDay;
            }

            harvestDay++;
        }

        return resultGrid;
    }

    private static boolean isValid(int r, int c) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    private static void printGrid(int[][] gridToPrint) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sb.append(gridToPrint[i][j]);
            }
            sb.append('\n');
        }

        System.out.print(sb);
    }

    private static final class Point {
        private final int r;
        private final int c;

        public Point(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public int getR() {
            return r;
        }

        public int getC() {
            return c;
        }
    }

    private static final class Field implements Comparable<Field> {
        private final int area;
        private final List<Point> coordinates;

        public Field(int area, List<Point> coordinates) {
            this.area = area;
            this.coordinates = coordinates;
        }

        public List<Point> getCoordinates() {
            return coordinates;
        }

        @Override
        public int compareTo(Field other) {
            return Integer.compare(this.area, other.area);
        }
    }
}