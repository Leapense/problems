import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] mark = new int[N + 1];

        ArrayList<Integer> seenVars = new ArrayList<>();

        int[] chosenClause = null;

        clauseLoop: for (int ci = 0; ci < M; ci++) {
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int[] lits = new int[k];

            boolean isTaut = false;

            for (int j = 0; j < k; j++) {
                int a = Integer.parseInt(st.nextToken());
                lits[j] = a;
                int v = Math.abs(a);
                int sign = a > 0 ? +1 : -1;

                if (!isTaut) {
                    if (mark[v] == 0) {
                        mark[v] = sign;
                        seenVars.add(v);
                    } else if (mark[v] != sign) {
                        isTaut = true;
                    }
                }
            }

            for (int v : seenVars) {
                mark[v] = 0;
            }

            seenVars.clear();

            if (!isTaut) {
                chosenClause = lits;
                break clauseLoop;
            }
        }

        StringBuilder sb = new StringBuilder();
        if (chosenClause == null) {
            sb.append("NO\n");
            System.out.print(sb);
            return;
        }

        boolean[] assign = new boolean[N + 1];

        for (int a : chosenClause) {
            if (a < 0) {
                assign[-a] = true;
            }
        }

        sb.append("YES\n");
        for (int i = 1; i <= N; i++) {
            sb.append(assign[i] ? '1' : '0');
            if (i < N)
                sb.append(' ');
        }

        sb.append('\n');
        System.out.print(sb);
    }
}