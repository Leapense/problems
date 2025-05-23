import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int totalRows = 3 * N;
        int totalCols = 8 * M;
        char[][] grid = new char[totalRows][totalCols];
        for (int i = 0; i < totalRows; i++) {
            String line = br.readLine();
            grid[i] = line.toCharArray();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int blockTop = i * 3;
                int blockLeft = j * 8;

                int textRow = blockTop + 1;
                int textCol = blockLeft + 1;

                StringBuilder sb = new StringBuilder();
                for (int k = 0; k < 6; k++) {
                    int col = textCol + k;
                    if (col >= blockLeft + 8)
                        break;
                    char ch = grid[textRow][col];
                    if (ch == '.')
                        break;
                    sb.append(ch);
                }

                String expr = sb.toString();

                int a = expr.charAt(0) - '0';
                int b = expr.charAt(2) - '0';
                int c = 0;

                if (expr.length() == 5) {
                    c = expr.charAt(4) - '0';
                } else if (expr.length() == 6) {
                    c = (expr.charAt(4) - '0') * 10 + (expr.charAt(5) - '0');
                }

                boolean correct = (a + b == c);

                if (correct) {
                    int len = expr.length();
                    for (int k = 0; k < len; k++) {
                        int r = textRow;
                        int cCol = textCol + k;
                        int[] dr = { -1, 1, 0, 0 };
                        int[] dc = { 0, 0, -1, 1 };
                        for (int d = 0; d < 4; d++) {
                            int nr = r + dr[d];
                            int nc = cCol + dc[d];

                            if (nr >= blockTop && nr < blockTop + 3 && nc >= blockLeft && nc < blockLeft + 8) {
                                if (grid[nr][nc] == '.') {
                                    grid[nr][nc] = '*';
                                }
                            }
                        }
                    }
                } else {
                    grid[blockTop + 2][blockLeft + 1] = '/';
                    grid[blockTop + 1][blockLeft + 2] = '/';
                    grid[blockTop][blockLeft + 3] = '/';
                }
            }
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < totalRows; i++) {
            bw.write(grid[i]);
            bw.newLine();
        }
        bw.flush();
        bw.close();
        br.close();
    }
}