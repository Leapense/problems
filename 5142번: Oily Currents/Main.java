import java.io.*;
import java.util.*;

public class Main {
    private static final int[] DX = { 0, 0, 1, -1 };
    private static final int[] DY = { -1, 1, 0, 0 };
    private static final Map<Character, Integer> DIR_MAP = Map.of(
            'N', 0, 'S', 1, 'E', 2, 'W', 3);

    private static final class Cell {
        final int x, y, t;

        Cell(int x, int y, int t) {
            this.x = x;
            this.y = y;
            this.t = t;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();
        int K = fs.nextInt();
        for (int ds = 1; ds <= K; ds++) {
            int w = fs.nextInt();
            int h = fs.nextInt();
            int x0 = fs.nextInt();
            int y0 = fs.nextInt();
            int limit = fs.nextInt();

            byte[][] strength = new byte[h][w];
            byte[][] dir = new byte[h][w];

            for (int i = 0; i < h; i++) {
                String line = fs.nextToken();

                for (int j = 0, pos = 0; j < w; j++, pos += 2) {
                    dir[i][j] = (byte) DIR_MAP.get(line.charAt(pos + 1));
                }
            }

            boolean[][] oily = new boolean[h][w];
            ArrayDeque<Cell> q = new ArrayDeque<>();
            oily[y0][x0] = true;
            q.add(new Cell(x0, y0, 0));

            while (!q.isEmpty()) {
                Cell c = q.removeFirst();
                if (c.t == limit)
                    continue;

                int d = dir[c.y][c.x];
                int s = strength[c.y][c.x];
                int dx = DX[d], dy = DY[d];

                for (int step = 1; step <= s; step++) {
                    int nx = c.x + dx * step;
                    int ny = c.y + dy * step;
                    if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                        break;
                    if (oily[ny][nx])
                        continue;
                    q.addLast(new Cell(nx, ny, c.t + 1));
                }
            }

            out.append("Data Set ").append(ds).append(":\n");
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    out.append(oily[i][j] ? 'X' : '.');
                }
                out.append('\n');
            }

            System.out.print(out.toString());
        }

        private static final class FastScanner {
            private final byte[] buffer = new byte[1 << 16];
            private int ptr = 0, len = 0;
            private final InputStream in;

            FastScanner(InputStream in) {
                this.in = in;
            }

            private int readByte() throws IOException {
                if (ptr >= len) {
                    len = in.read(buffer);
                    ptr = 0;
                    if (len <= 0)
                        return -1;
                }

                return buffer[ptr++];
            }

            String nextToken() throws IOException {
                StringBuilder sb = new StringBuilder();
                int c;

                while ((c = readByte()) != -1 && c <= ' ')
                    ;
                if (c == -1)
                    return null;

                do {
                    sb.append((char) c);
                } while ((c = readByte()) != -1 && c > ' ');

                return sb.toString();
            }

            int nextInt() throws IOException {
                return Integer.parseInt(nextToken());
            }
        }
    }
}