import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = reader.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(line);
            int[] w0 = new int[3];
            int[] h0 = new int[3];
            for (int i = 0; i < 3; i++) {
                w0[i] = Integer.parseInt(st.nextToken());
                h0[i] = Integer.parseInt(st.nextToken());
            }

            if (w0[0] == 0 && h0[0] == 0 && w0[1] == 0 && h0[1] == 0 && w0[2] == 0 && h0[2] == 0) {
                break;
            }
            System.out.println(minUnionArea(w0, h0));
        }
    }

    private static long minUnionArea(int[] w0, int[] h0) {
        long sumAreaBase = 0;
        for (int i = 0; i < 3; i++) {
            sumAreaBase += (long) w0[i] * h0[i];
        }

        long best = Long.MAX_VALUE;
        int[][] pairs = {{0,1}, {0,2}, {1,2}};
        for (int orient = 0; orient < 8; orient++) {
            int[] w = new int[3];
            int[] h = new int[3];
            for (int i = 0; i < 3; i++) {
                if (((orient >> i) & 1) == 1) {
                    w[i] = h0[i];
                    h[i] = w0[i];
                } else {
                    w[i] = w0[i];
                    h[i] = h0[i];
                }
            }
            long sumArea = 0;

            for (int i = 0; i < 3; i++) {
                sumArea += (long) w[i] * h[i];
            }

            long[][] overlap = new long[3][3];
            for (int[] p : pairs) {
                int i = p[0];
                int j = p[1];
                overlap[i][j] = Math.min(w[i], w[j]) * Math.min(h[i], h[j]);
            }

            long tripleOverlap = Math.min(Math.min(w[0], w[1]), w[2]) * Math.min(Math.min(h[0], h[1]), h[2]);
            for (int mask = 0; mask < 8; mask++) {
                long area = sumArea;
                int countPairs = Integer.bitCount(mask);
                for (int k = 0; k < 3; k++) {
                    if (((mask >> k) & 1) == 1) {
                        int i = pairs[k][0];
                        int j = pairs[k][1];
                        area -= overlap[i][j];
                    }
                }
                if (countPairs == 3) {
                    area += tripleOverlap;
                }
                if (area < best) {
                    best = area;
                }
            }
        }

        return best;
    }
}