import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public void run() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = reader.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(line);
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int x3 = Integer.parseInt(st.nextToken());
            int y3 = Integer.parseInt(st.nextToken());

            if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0) {
                break;
            }

            int result = solve(x1, y1, x2, y2, x3, y3);
            System.out.println(result);
        }
    }

    private int solve(int x1, int y1, int x2, int y2, int x3, int y3) {
        int minX = Math.min(x1, Math.min(x2, x3));
        int maxX = Math.max(x1, Math.max(x2, x3));
        int minY = Math.min(y1, Math.min(y2, y3));
        int maxY = Math.max(y1, Math.max(y2, y3));

        int coloredPixels = 0;

        for (int i = minX; i < maxX; i++) {
            for (int j = minY; j < maxY; j++) {
                if (isInside(i, j, x1, y1, x2, y2, x3, y3)) {
                    coloredPixels++;
                }
            }
        }

        return coloredPixels;
    }

    private boolean isInside(int pixelI, int pixelJ, int x1, int y1, int x2, int y2, int x3, int y3) {
        long side1 = checkSide(x1, y1, x2, y2, pixelI, pixelJ);
        long side2 = checkSide(x2, y2, x3, y3, pixelI, pixelJ);
        long side3 = checkSide(x3, y3, x1, y1, pixelI, pixelJ);

        return side1 >= 0 && side2 >= 0 && side3 >= 0;
    }

    private long checkSide(long p1x, long p1y, long p2x, long p2y, long pi, long pj) {
        long term1 = (p2x - p1x) * (2L * pj + 1L - 2L * p1y);
        long term2 = (p2y - p1y) * (2L * pi + 1L - 2L * p1x);
        return term1 - term2;
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}