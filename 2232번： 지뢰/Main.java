import java.io.*;
import java.util.*;

public class Main {
    static class Interval {
        int L, R, index;

        public Interval(int L, int R, int index) {
            this.L = L;
            this.R = R;
            this.index = index;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        int[] P = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            P[i] = Integer.parseInt(br.readLine().trim());
        }

        int[] L = new int[N + 1];
        int[] R = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            L[i] = i;
            if (i > 1 && P[i] > P[i - 1]) {
                L[i] = L[i - 1];
            }
        }

        for (int i = N; i >= 1; i--) {
            R[i] = i;
            if (i < N && P[i] > P[i + 1]) {
                R[i] = R[i + 1];
            }
        }

        Interval[] intervals = new Interval[N];

        for (int i = 1; i <= N; i++) {
            intervals[i - 1] = new Interval(L[i], R[i], i);
        }

        Arrays.sort(intervals, new Comparator<Interval>() {
            public int compare(Interval a, Interval b) {
                return Integer.compare(a.L, b.L);
            }
        });

        List<Integer> result = new ArrayList<>();
        int currentEnd = 0;
        int i = 0;

        while (currentEnd < N) {
            int bestR = currentEnd;
            int chosenIndex = -1;

            while (i < N && intervals[i].L <= currentEnd + 1) {
                if (intervals[i].R > bestR) {
                    bestR = intervals[i].R;
                    chosenIndex = intervals[i].index;
                }
                i++;
            }

            if (chosenIndex == -1) {
                break;
            }

            result.add(chosenIndex);
            currentEnd = bestR;
        }

        Collections.sort(result);

        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        for (int idx : result) {
            pw.println(idx);
        }

        pw.flush();
        pw.close();
    }
}