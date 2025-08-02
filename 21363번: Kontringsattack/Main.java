import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    private static final class Pair {
        final int diff;
        final int delta;
        Pair(int diff, int delta) {
            this.diff = diff;
            this.delta = delta;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        long currentDiff = 0L;
        ArrayList<Pair> events = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int f = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            if (f == s) {
                continue;
            }

            if (f > s) {
                currentDiff++;
                events.add(new Pair(f - s, -1));
            } else {
                currentDiff--;
                events.add(new Pair(s - f, 1));
            }
        }

        Collections.sort(events, (a, b) -> Integer.compare(a.diff, b.diff));

        long bestDiff = currentDiff;
        int bestK = 0;
        int idx = 0;

        while (idx < events.size()) {
            int d = events.get(idx).diff;
            int deltaSum = 0;
            while (idx < events.size() && events.get(idx).diff == d) {
                deltaSum += events.get(idx).delta;
                idx++;
            }
            currentDiff += deltaSum;
            if (currentDiff > bestDiff || (currentDiff == bestDiff && d < bestK)) {
                bestDiff = currentDiff;
                bestK = d;
            }
        }

        System.out.println(bestK);
    }
}