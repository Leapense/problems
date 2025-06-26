import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public final class Main {
    private static final int DAY_MINUTES = 24 * 60;
    private static final int HALF_DAY = 12 * 60;
    private static final int OWNER_C = 0;
    private static final int OWNER_J = 1;
    private static final int INF = 1 << 29;

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

            int t = Integer.parseInt(br.readLine().trim());
            StringBuilder out = new StringBuilder();

            for (int tc = 1; tc <= t; tc++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int aC = Integer.parseInt(st.nextToken());
                int aJ = Integer.parseInt(st.nextToken());

                /* forced[m] = -1 : free, 0 : must be C, 1 : must be J */
                int[] forced = new int[DAY_MINUTES];
                for (int i = 0; i < DAY_MINUTES; i++) {
                    forced[i] = -1;
                }

                // Cameron's personal activities  →  Jamie must hold the baby
                for (int i = 0; i < aC; i++) {
                    st = new StringTokenizer(br.readLine());
                    int s = Integer.parseInt(st.nextToken());
                    int e = Integer.parseInt(st.nextToken());
                    markInterval(forced, s, e, OWNER_J);
                }

                // Jamie's personal activities   →  Cameron must hold the baby
                for (int i = 0; i < aJ; i++) {
                    st = new StringTokenizer(br.readLine());
                    int s = Integer.parseInt(st.nextToken());
                    int e = Integer.parseInt(st.nextToken());
                    markInterval(forced, s, e, OWNER_C);
                }

                int answer = solve(forced);
                out.append("Case #").append(tc).append(": ").append(answer).append('\n');
            }
            System.out.print(out.toString());
        }
    }

    private static void markInterval(int[] forced, int start, int end, int owner) {
        for (int m = start; m < end; m++) {
            forced[m] = owner;
        }
    }

    private static int solve(int[] forced) {
        int[][][] cur = new int[HALF_DAY + 1][2][2];
        int[][][] nxt = new int[HALF_DAY + 1][2][2];
        initDp(cur);

        for (int owner = 0; owner <= 1; owner++) {
            if (forced[0] != -1 && forced[0] != owner) {
                continue;
            }

            int cMin = (owner == OWNER_C) ? 1 : 0;
            cur[cMin][owner][owner] = 0;
        }

        for (int m = 1; m < DAY_MINUTES; m++) {
            initDp(nxt);

            for (int c = 0; c <= HALF_DAY; c++) {
                for (int last = 0; last <= 1; last++) {
                    for (int first = 0; first <= 1; first++) {
                        int best = cur[c][last][first];
                        if (best == INF) {
                            continue;
                        }

                        for (int owner = 0; owner <= 1; owner++) {
                            if (forced[m] != -1 && forced[m] != owner) {
                                continue;
                            }

                            int newC = c + ((owner == OWNER_C) ? 1 : 0);
                            if (newC > HALF_DAY) {
                                continue;
                            }

                            int extra = (owner == last) ? 0 : 1;
                            int cand = best + extra;

                            if (cand < nxt[newC][owner][first]) {
                                nxt[newC][owner][first] = cand;
                            }
                        }
                    }
                }
            }

            int[][][] tmp = cur;
            cur = nxt;
            nxt = tmp;
        }

        int result = INF;
        for (int last = 0; last <= 1; last++) {
            for (int first = 0; first <= 1; first++) {
                int val = cur[HALF_DAY][last][first];
                if (val == INF) {
                    continue;
                }
                if (last != first) {
                    val++;
                }
                result = Math.min(result, val);
            }
        }

        return result;
    }

    private static void initDp(int[][][] dp) {
        for (int c = 0; c <= HALF_DAY; c++) {
            for (int l = 0; l <= 1; l++) {
                for (int f = 0; f <= 1; f++) {
                    dp[c][l][f] = INF;
                }
            }
        }
    }

    private Main() {
        
    }
}