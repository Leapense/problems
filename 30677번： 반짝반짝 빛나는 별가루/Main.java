import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        int[] base = new int[K];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            base[i] = Integer.parseInt(st.nextToken());
        }

        int[] s = new int[K];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            s[i] = Integer.parseInt(st.nextToken());
        }

        int[] p = new int[K];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            p[i] = Integer.parseInt(st.nextToken());
        }
        int[] plan = new int[N];
        for (int i = 0; i < N; i++) {
            plan[i] = Integer.parseInt(br.readLine());
        }

        int fatigue = 0;
        int combo = 0;
        int[] skill = new int[K];
        BigInteger totalStardust = BigInteger.ZERO;

        for (int day = 0; day < N; day++) {
            int action = plan[day];

            if (action == 0) {
                fatigue = Math.max(fatigue - R, 0);
                combo = 0;
            } else {
                int magicIndex = action - 1;

                long factor1 = 100L + combo * (long) C;
                long factor2 = skill[magicIndex] * (long) s[magicIndex];

                BigInteger produced = BigInteger.valueOf(base[magicIndex])
                        .multiply(BigInteger.valueOf(factor1))
                        .multiply(BigInteger.valueOf(factor2))
                        .divide(BigInteger.valueOf(10000));

                totalStardust = totalStardust.add(produced);

                skill[magicIndex]++;
                combo++;

                fatigue += p[magicIndex];
                if (fatigue > 100) {
                    System.out.println(-1);
                    return;
                }
            }
        }

        System.out.println(totalStardust);
    }
}