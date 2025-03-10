import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    static int[] initial = new int[5];
    static int X, Y;
    static int[] masks;
    static int[] colMasks = new int[5];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        for (int j = 0; j < 5; j++) {
            int mask = 0;
            for (int i = 0; i < 5; i++) {
                mask |= (1 << (i * 5 + j));
            }

            colMasks[j] = mask;
        }

        int freeIndex = 12;
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                initial[j] = Integer.parseInt(st.nextToken());
            }

            X = Integer.parseInt(st.nextToken());
            Y = Integer.parseInt(st.nextToken());

            char[][][] patterns = new char[X][5][5];
            for (int i = 0; i < 5; i++) {
                st = new StringTokenizer(br.readLine());
                for (int p = 0; p < X; p++) {
                    String token = st.nextToken();
                    for (int j = 0; j < 5; j++) {
                        patterns[p][i][j] = token.charAt(j);
                    }
                }
            }

            masks = new int[X];

            for (int p = 0; p < X; p++) {
                int mask = 0;
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (patterns[p][i][j] == 'X') {
                            mask |= (1 << (i * 5 + j));
                        }
                    }
                }

                masks[p] = mask;
            }

            int minAdditional = Integer.MAX_VALUE;
            int totalSubsets = 1 << X;

            for (int subset = 1; subset < totalSubsets; subset++) {
                if (Integer.bitCount(subset) < Y)
                    continue;
                int unionMask = 0;
                for (int p = 0; p < X; p++) {
                    if ((subset & (1 << p)) != 0) {
                        unionMask |= masks[p];
                    }
                }

                int additional = 0;

                for (int j = 0; j < 5; j++) {
                    int colCount = Integer.bitCount(unionMask & colMasks[j]);
                    if (j == 2 && ((unionMask & (1 << freeIndex)) != 0)) {
                        colCount--;
                    }
                    additional += Math.max(0, colCount - initial[j]);
                }
                minAdditional = Math.min(minAdditional, additional);
            }
            sb.append(minAdditional).append("\n");
        }
        System.out.print(sb.toString());
    }
}