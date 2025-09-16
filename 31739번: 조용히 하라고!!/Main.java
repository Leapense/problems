import java.io.*;
import java.util.*;

public class Main {
    static class Mosquito {
        int r, c, s;
        Mosquito(int r, int c, int s) { this.r = r; this.c = c; this.s = s; }
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        long T = Long.parseLong(st.nextToken());
        long P = Long.parseLong(st.nextToken());

        Mosquito[] ms = new Mosquito[K];
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            ms[i] = new Mosquito(r, c, s);
        }

        int maxWoo = solveWoo(N, M, K, T, ms);
        int maxAhr = solveAhr(N, M, K, P, ms);
        System.out.println(maxWoo + " " + maxAhr);
    }

    static int solveWoo(int N, int M, int K, long T, Mosquito[] ms) {
        Map<Long, Integer> countMap = new HashMap<>();
        Map<Long, int[]> coordMap = new HashMap<>();
        for (Mosquito m : ms) {
            long key = pack(m.r, m.c);
            countMap.put(key, countMap.getOrDefault(key, 0) + 1);
            coordMap.putIfAbsent(key, new int[]{m.r, m.c});
        }
        int U = countMap.size();
        int[] rs = new int[U];
        int[] cs = new int[U];
        int[] cnt = new int[U];
        int idx = 0;
        for (Map.Entry<Long, Integer> e : countMap.entrySet()) {
            long key = e.getKey();
            int[] rc = coordMap.get(key);
            rs[idx] = rc[0];
            cs[idx] = rc[1];
            cnt[idx] = e.getValue();
            idx++;
        }

        if (U == 0) return 0;

        int[][] dist = new int[U][U];
        for (int i = 0; i < U; i++) {
            for (int j = 0; j < U; j++) {
                dist[i][j] = Math.abs(rs[i] - rs[j]) + Math.abs(cs[i] - cs[j]);
            }
        }

        int[] sumCnt = new int[1 << U];
        for (int mask = 1; mask < (1 << U); mask++) {
            int lsb = mask & -mask;
            int bit = Integer.numberOfTrailingZeros(lsb);
            sumCnt[mask] = sumCnt[mask ^ lsb] + cnt[bit];
        }

        int INF = 1_000_000_000;
        int[][] dp = new int[1 << U][U];
        for (int m = 0; m < (1 << U); m++) Arrays.fill(dp[m], INF);
        for (int v = 0; v < U; v++) dp[1 << v][v] = 0;

        for (int mask = 1; mask < (1 << U); mask++) {
            for (int v = 0; v < U; v++) {
                if ((mask & (1 << v)) == 0) continue;
                int cur = dp[mask][v];
                if (cur == INF) continue;
                for (int n = 0; n < U; n++) {
                    if ((mask & (1 << n)) != 0) continue;
                    int nm = mask | (1 << n);
                    int cand = cur + dist[v][n];
                    if (cand < dp[nm][n]) dp[nm][n] = cand;
                }
            }
        }

        int ans = 0;
        for (int mask = 1; mask < (1 << U); mask++) {
            int best = INF;
            for (int v = 0; v < U; v++) {
                if ((mask & (1 << v)) == 0) continue;
                best = Math.min(best, dp[mask][v]);
            }
            if (best != INF && best <= T) {
                ans = Math.max(ans, sumCnt[mask]);
            }
        }

        return ans;
    }

    static int solveAhr(int N, int M, int K, long P, Mosquito[] ms) {
        int best = 0;
        for (int R = 1; R <= N; R++) {
            for (int C = 1; C <= M; C++) {
                int got = 0;
                for (int i = 0; i < K; i++) {
                    if (ms[i].r == R && ms[i].c == C) {
                        got++;
                    } else {
                        int L = Math.abs(R - ms[i].r) + Math.abs(C - ms[i].c);
                        long need = (long) ms[i].s * (long) L;
                        if (P >= need) got++;
                    }
                }

                if (got > best) best = got;
            }
        }

        return best;
    }

    static long pack(int r, int c) {
        return (((long) r) << 32) ^ (long) c;
    }
}