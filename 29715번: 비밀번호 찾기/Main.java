import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    static int N, M, X, Y;
    static int[] fixed;
    static boolean[] required = new boolean[10];
    static int countCandidates = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());

        fixed = new int[N];

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (a == 0) {
                required[b] = true;
            } else {
                fixed[a - 1] = b;
            }
        }
        boolean[] used = new boolean[10];
        int[] perm = new int[N];
        generate(0, perm, used);

        int groups = (countCandidates - 1) / 3;
        int totalTime = countCandidates * X + groups * Y;

        out.println(totalTime);
        out.flush();
        out.close();
    }

    static void generate(int pos, int[] perm, boolean[] used) {
        if (pos == N) {
            for (int d = 1; d <= 9; d++) {
                if (required[d]) {
                    boolean found = false;
                    for (int i = 0; i < N; i++) {
                        if (perm[i] == d) {
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        return;
                }
            }

            countCandidates++;
            return;
        }

        if (fixed[pos] != 0) {
            int digit = fixed[pos];
            if (used[digit])
                return;
            used[digit] = true;
            perm[pos] = digit;
            generate(pos + 1, perm, used);
            used[digit] = false;
        } else {
            for (int digit = 1; digit <= 9; digit++) {
                if (!used[digit]) {
                    used[digit] = true;
                    perm[pos] = digit;
                    generate(pos + 1, perm, used);
                    used[digit] = false;
                }
            }
        }
    }
}