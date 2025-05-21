import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Objects; // Needed for hashCode
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class QueryEvent implements Comparable<QueryEvent> {
        private final int qNum;
        private final int period;
        private final int nextExecutionTime;

        public QueryEvent(int qNum, int period, int nextExecutionTime) {
            this.qNum = qNum;
            this.period = period;
            this.nextExecutionTime = nextExecutionTime;
        }

        public int getQNum() {
            return qNum;
        }

        public int getPeriod() {
            return period;
        }

        public int getNextExecutionTime() {
            return nextExecutionTime;
        }

        @Override
        public int compareTo(QueryEvent other) {
            if (this.nextExecutionTime != other.nextExecutionTime) {
                return Integer.compare(this.nextExecutionTime, other.nextExecutionTime);
            }
            return Integer.compare(this.qNum, other.qNum);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            QueryEvent that = (QueryEvent) o;
            return qNum == that.qNum && period == that.period && nextExecutionTime == that.nextExecutionTime;
        }

        @Override
        public int hashCode() {
            return Objects.hash(qNum, period, nextExecutionTime);
        }
    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                PrintWriter pw = new PrintWriter(System.out)) {
            PriorityQueue<QueryEvent> eventQueue = new PriorityQueue<>();

            String line;

            while ((line = br.readLine()) != null && !line.equals("#")) {
                StringTokenizer st = new StringTokenizer(line);
                st.nextToken();
                int qNum = Integer.parseInt(st.nextToken());
                int period = Integer.parseInt(st.nextToken());

                eventQueue.add(new QueryEvent(qNum, period, period));
            }

            int k = Integer.parseInt(br.readLine());

            for (int i = 0; i < k; i++) {
                if (eventQueue.isEmpty()) {
                    break;
                }

                QueryEvent currentEvent = eventQueue.poll();
                pw.println(currentEvent.getQNum());

                QueryEvent nextInstance = new QueryEvent(
                        currentEvent.getQNum(),
                        currentEvent.getPeriod(),
                        currentEvent.getNextExecutionTime() + currentEvent.getPeriod());
                eventQueue.add(nextInstance);
            }

            pw.flush();
        }
    }
}