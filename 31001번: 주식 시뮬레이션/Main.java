import java.io.*;
import java.util.*;

public class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String next() throws IOException {
            while (st == null || !st.hasMoreElements()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        int nextInt() throws IOException { return Integer.parseInt(next()); }
        long nextLong() throws IOException { return Long.parseLong(next()); }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int N = fs.nextInt();
        long M = fs.nextLong();
        int Q = fs.nextInt();

        long cash = M;
        long[] price = new long[N];
        long[] share = new long[N];
        
        Map<String, Integer> idxByName = new HashMap<>();
        @SuppressWarnings("unchecked")
        ArrayList<Integer>[] groupToIdx = new ArrayList[101];
        for (int i = 1; i <= 100; i++) {
            groupToIdx[i] = new ArrayList<>();
        }

        for (int i = 0; i < N; i++) {
            int g = fs.nextInt();
            String name = fs.next();
            long p = fs.nextLong();
            idxByName.put(name, i);
            price[i] = p;
            share[i] = 0L;
            if (g >= 1 && g <= 100) groupToIdx[g].add(i);
        }

        StringBuilder out = new StringBuilder();
        for (int qi = 0; qi < Q; qi++) {
            int t = fs.nextInt();
            switch (t) {
                case 1: {
                    String A = fs.next();
                    int B = fs.nextInt();
                    int i = idxByName.get(A);
                    long cost = price[i] * (long) B;
                    if (cash >= cost) {
                        cash -= cost;
                        share[i] += B;
                    }
                    break;
                }
                case 2: {
                    String A = fs.next();
                    int B = fs.nextInt();
                    int i = idxByName.get(A);
                    long have = share[i];
                    if (have > 0) {
                        long sell = Math.min(have, (long)B);
                        cash += sell * price[i];
                        share[i] -= sell;
                    }
                    break;
                }
                case 3: {
                    String A = fs.next();
                    long C = fs.nextLong();
                    int i = idxByName.get(A);
                    price[i] += C;
                    if (price[i] < 0) price[i] = 0;
                    break;
                }
                case 4: {
                    int D = fs.nextInt();
                    long C = fs.nextLong();
                    for (int i : groupToIdx[D]) {
                        price[i] += C;
                        if (price[i] < 0) price[i] = 0;
                    }
                    break;
                }
                case 5: {
                    int D = fs.nextInt();
                    int E = fs.nextInt();
                    int k = 100 + E;
                    for (int i : groupToIdx[D]) {
                        long tmp = price[i] * (long) k;
                        long np = tmp / 100L;
                        np -= (np % 10L);
                        if (np < 0) np = 0;
                        price[i] = np;
                    }

                    break;
                }
                case 6: {
                    out.append(cash).append('\n');
                    break;
                }
                case 7: {
                    long total = cash;
                    for (int i = 0; i < N; i++) total += share[i] * price[i];
                    out.append(total).append('\n');
                    break;
                }
                default:
                    break;
            }
        }

        System.out.print(out.toString());
    }
}