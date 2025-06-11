import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main
{
    private static final class Event implements Comparable<Event> {
        final int finish;
        final int id;

        Event(int finish, int id) {
            this.finish = finish;
            this.id = id;
        }

        @Override
        public int compareTo(Event other) {
            if (this.finish != other.finish) {
                return Integer.compare(this.finish, other.finish);
            }
            return Integer.compare(this.id, other.id);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        /* -------- read n and s -------- */
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int eaten = n - s;              // pastries that disappeared

        /* -------- read m and the eating speeds -------- */
        int m = Integer.parseInt(br.readLine().trim());
        int[] t = new int[m + 1];       // 1-based; t[0] unused
        for (int i = 1; i <= m; i++) {
            t[i] = Integer.parseInt(br.readLine().trim());
        }

        /* -------- simulate using a min-heap -------- */
        PriorityQueue<Event> pq = new PriorityQueue<>();
        int picked = 0;
        int answer = -1;

        /* initial grabs (t = 0) */
        for (int i = 1; i <= m && picked < eaten; i++) {
            picked++;
            answer = i;
            pq.offer(new Event(t[i], i));
        }

        /* subsequent grabs */
        while (picked < eaten) {
            Event e = pq.poll();             // earliest finisher
            picked++;
            answer = e.id;                   // he grabs next
            pq.offer(new Event(e.finish + t[e.id], e.id));
        }

        System.out.println(answer);
    }
}