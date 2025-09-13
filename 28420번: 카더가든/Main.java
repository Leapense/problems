import java.io.*;

public class Main {
    static class FastScanner {
        BufferedInputStream in;
        byte[] buffer = new byte[1 << 16];
        int ptr = 0, len = 0;
        FastScanner(InputStream is) { in = new BufferedInputStream(is); }
        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c, sgn = 1, val = 0;
            do c = read(); while (c <= 32);
            if (c == '-') {sgn = -1; c = read();}
            while (c > 32) {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sgn;
        }
    }

    static long[][] buildPrefix(int N, int M, int[][] A) {
        long[][] P = new long[N + 1][M + 1];
        for (int i = 1; i <= N; i++) {
            long rowSum = 0;
            for (int j = 1; j <= M; j++) {
                rowSum += A[i - 1][j - 1];
                P[i][j] = P[i - 1][j] + rowSum;
            }
        }

        return P;
    }

    static long rectSum(long[][] P, int r, int c, int h, int w) {
        int r2 = r + h, c2 = c + w;
        return P[r2][c2] - P[r][c2] - P[r2][c] + P[r][c];
    }

    static long solve(int N, int M, int a, int b, int c, int[][] A) {
        long[][] P = buildPrefix(N, M, A);
        int H = Math.max(b, c);

        int[] offCar = new int[3];
        int[] offCam = new int[3];

        offCar[0] = 0;
        offCam[0] = 0;

        offCar[1] = (H - b) / 2;
        offCam[1] = (H - c) / 2;

        offCar[2] = H - b;
        offCam[2] = H - c;

        long ans = Long.MAX_VALUE;
        
        for (int mode = 0; mode < 3; mode++) {
            int oyCar = offCar[mode], oyCam = offCam[mode];
            for (int y = 0; y + H <= N; y++) {
                int carTop = y + oyCar;
                int camTop = y + oyCam;

                for (int x = 0; x + 2 * a <= M; x++) {
                    int carLeft = x;
                    int camLeft = x + a;

                    long costCar = rectSum(P, carTop, carLeft, b, a);
                    long costCam = rectSum(P, camTop, camLeft, c, a);
                    long cost = costCar + costCam;

                    if (cost < ans) ans = cost;
                }
            }
        }

        return ans;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int N = fs.nextInt(), M = fs.nextInt();
        int a = fs.nextInt(), b = fs.nextInt(), c = fs.nextInt();
        int[][] A = new int[N][M];
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++)
                A[i][j] = fs.nextInt();

        long[][] P = buildPrefix(N, M, A);
        long ans = Long.MAX_VALUE;

        for (int y = 0; y + a <= N; y++)
        {
            for (int x = 0; x + b + c <= M; x++)
            {
                long cost = rectSum(P, y, x, a, b + c);
                if (cost < ans) ans = cost;
            }
        }

        for (int y = 0; y + a + b <= N; y++)
        {
            for (int x = 0; x + c + a <= M; x++)
            {
                long cost = rectSum(P, y, x, a, c) + rectSum(P, y + a, x + c, b, a);
                if (cost < ans) ans = cost;
            }
        }

        for (int y = 0; y + a + c <= N; y++)
        {
            for (int x = 0; x + b + a <= M; x++)
            {
                long cost = rectSum(P, y, x, a, b) + rectSum(P, y + a, x + b, c, a);
                if (cost < ans) ans = cost;
            }
        }

        System.out.println(ans);
    }
}