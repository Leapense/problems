import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Objects;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    private static final class Point {
        final int r;
        final int c;

        Point(int r, int c) {
            this.r = r;
            this.c = c;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Point point = (Point) o;
            return r == point.r && c == point.c;
        }

        @Override
        public int hashCode() {
            return Objects.hash(r, c);
        }
    }
    private static final class ShapeIdentifier {

        private static final Point[][] BASE_SHAPES;
        private static final Point[][] MIRROR_SHAPES;

        static {
            BASE_SHAPES = new Point[][]{
                {new Point(0, 0), new Point(0, 1), new Point(1, 0), new Point(1, 1)}, // Fig 1: Square
                {new Point(0, 0), new Point(1, 0), new Point(2, 0), new Point(3, 0)}, // Fig 2: Line (4x1)
                {new Point(0, 0), new Point(1, 0), new Point(2, 0), new Point(2, 1)}, // Fig 3: L-block
                {new Point(0, 1), new Point(1, 0), new Point(1, 1), new Point(1, 2)}, // Fig 4: T-block
                {new Point(0, 1), new Point(0, 2), new Point(1, 0), new Point(1, 1)}  // Fig 5: S-block
            };
            MIRROR_SHAPES = new Point[][]{
                null,
                null,
                {new Point(0, 1), new Point(1, 1), new Point(2, 1), new Point(2, 0)}, // Fig 3: J-block (mirror of L)
                null,
                {new Point(0, 0), new Point(0, 1), new Point(1, 1), new Point(1, 2)}  // Fig 5: Z-block (mirror of S)
            };
        }

        private Set<Point> rotate(Set<Point> shape) {
            Set<Point> rotatedShape = new HashSet<>();
            for (Point p : shape) {
                rotatedShape.add(new Point(p.c, -p.r));
            }
            return rotatedShape;
        }

        private Set<Point> normalize(Set<Point> shape) {
            int minR = Integer.MAX_VALUE;
            int minC = Integer.MAX_VALUE;
            for (Point p : shape) {
                minR = Math.min(minR, p.r);
                minC = Math.min(minC, p.c);
            }
            Set<Point> normalizedShape = new HashSet<>();
            for (Point p : shape) {
                normalizedShape.add(new Point(p.r - minR, p.c - minC));
            }
            return normalizedShape;
        }

        private boolean matchesAnyRotation(Set<Point> targetShape, Point[] shapeToTest) {
            Set<Point> currentShape = new HashSet<>(Arrays.asList(shapeToTest));
            for (int r = 0; r < 4; r++) {
                if (normalize(currentShape).equals(targetShape)) {
                    return true;
                }
                currentShape = rotate(currentShape);
            }
            return false;
        }

        public int identify(Set<Point> foundShape) {
            if (foundShape.size() != 4) {
                return -1;
            }
            Set<Point> normalizedFoundShape = normalize(foundShape);
            for (int i = 0; i < BASE_SHAPES.length; i++) {
                if (matchesAnyRotation(normalizedFoundShape, BASE_SHAPES[i])) {
                    return i;
                }
                if (MIRROR_SHAPES[i] != null && matchesAnyRotation(normalizedFoundShape, MIRROR_SHAPES[i])) {
                    return i;
                }
            }
            return -1;
        }
    }

    private static int N, M;
    private static char[][] grid;
    private static boolean[][] visited;
    private static final int[] dr = {-1, -1, -1, 0, 0, 1, 1, 1};
    private static final int[] dc = {-1, 0, 1, -1, 1, -1, 0, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        grid = new char[N][M];
        visited = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            grid[i] = br.readLine().toCharArray();
        }

        ShapeIdentifier identifier = new ShapeIdentifier();
        int[] counts = new int[5];

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (grid[r][c] != '.' && !visited[r][c]) {
                    Set<Point> figurePoints = extractFigure(r, c);
                    int figureType = identifier.identify(figurePoints);
                    if (figureType != -1) {
                        counts[figureType]++;
                    }
                }
            }
        }

        for (int count : counts) {
            System.out.println(count);
        }
    }

    private static Set<Point> extractFigure(int startR, int startC) {
        Set<Point> points = new HashSet<>();
        Queue<Point> queue = new LinkedList<>();
        char color = grid[startR][startC];

        queue.add(new Point(startR, startC));
        visited[startR][startC] = true;
        points.add(new Point(startR, startC));

        while (!queue.isEmpty()) {
            Point current = queue.poll();
            for (int i = 0; i < 8; i++) { // Use 8-way search
                int nextR = current.r + dr[i];
                int nextC = current.c + dc[i];
                if (isValid(nextR, nextC) && !visited[nextR][nextC] && grid[nextR][nextC] == color) {
                    visited[nextR][nextC] = true;
                    Point nextPoint = new Point(nextR, nextC);
                    queue.add(nextPoint);
                    points.add(nextPoint);
                }
            }
        }
        return points;
    }

    private static boolean isValid(int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < M;
    }
}