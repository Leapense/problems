import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.List;
import java.util.StringTokenizer;

public final class Main {

    private static final long MOD = 1_000_002_013L;

    private static class Event implements Comparable<Event> {
        final int station;
        final long count;  // positive for entry, negative for exit

        Event(final int station, final long count) {
            this.station = station;
            this.count = count;
        }

        @Override
        public int compareTo(final Event other) {
            if (this.station != other.station) {
                return Integer.compare(this.station, other.station);
            }
            return Long.compare(other.count, this.count);
        }
    }

    public static void main(final String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(reader.readLine().trim());
        for (int tc = 1; tc <= testCases; tc++) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            // Read journeys and accumulate original revenue
            long originalRevenue = 0L;
            List<Event> events = new ArrayList<>(2 * m);
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(reader.readLine());
                int o = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                long p = Long.parseLong(st.nextToken());

                long distance = e - o;
                long journeyCost = computeCost(n, distance);
                originalRevenue = (originalRevenue + p * journeyCost) % MOD;

                events.add(new Event(o,  p));   // entry
                events.add(new Event(e, -p));   // exit
            }

            // Compute minimal revenue under optimal swapping
            long actualRevenue = computeActualRevenue(n, events);

            long loss = (originalRevenue - actualRevenue) % MOD;
            if (loss < 0) {
                loss += MOD;
            }

            System.out.printf("Case #%d: %d%n", tc, loss);
        }
    }

    /**
     * Computes cost of traveling exactly 'd' stations on a line of 'n' stops:
     *   cost = d * n - d*(d - 1)/2, all mod MOD.
     */
    private static long computeCost(final int n, final long d) {
        long term1 = (d % MOD) * (n % MOD) % MOD;
        long term2 = (d * (d - 1) / 2) % MOD;
        long cost = (term1 - term2) % MOD;
        if (cost < 0) {
            cost += MOD;
        }
        return cost;
    }

    /**
     * Runs the sweep-line simulation on sorted entry/exit events to find the
     * minimum possible revenue (i.e. actual revenue under full swapping).
     */
    private static long computeActualRevenue(final int n, final List<Event> events) {
        Collections.sort(events);
        Deque<Event> stack = new ArrayDeque<>();
        long revenue = 0L;

        for (Event event : events) {
            if (event.count > 0) {
                // entry event
                stack.push(event);
            } else {
                // exit event
                long toMatch = -event.count;
                int exitStation = event.station;

                while (toMatch > 0L) {
                    Event top = stack.peek();
                    long available = top.count;
                    int entryStation = top.station;

                    long used = Math.min(available, toMatch);
                    long distance = exitStation - entryStation;
                    revenue = (revenue + used * computeCost(n, distance)) % MOD;

                    toMatch -= used;
                    if (used < available) {
                        // partially consume this entry
                        stack.pop();
                        stack.push(new Event(entryStation, available - used));
                    } else {
                        // fully consume
                        stack.pop();
                    }
                }
            }
        }

        return revenue;
    }
}