import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;

enum FoodType {
    CHOCOLATE, COFFEE
}

class ConsumptionEvent {
    FoodType type;
    int consumptionTime;
    double amount;

    public ConsumptionEvent(FoodType type, int consumptionTime, double amount) {
        this.type = type;
        this.consumptionTime = consumptionTime;
        this.amount = amount;
    }
}

class QueryResult implements Comparable<QueryResult> {
    int queryTime;
    double safetyDistance;

    public QueryResult(int queryTime, double safetyDistance) {
        this.queryTime = queryTime;
        this.safetyDistance = safetyDistance;
    }

    @Override
    public int compareTo(QueryResult other) {
        return Integer.compare(this.queryTime, other.queryTime);
    }

    public String getFormattedOutput() {
        return String.format(Locale.US, "%d %.1f", this.queryTime, this.safetyDistance);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        List<ConsumptionEvent> consumptions = new ArrayList<>();
        List<Integer> queryTimesToProcess = new ArrayList<>();

        String line;
        while ((line = br.readLine()) != null && !line.trim().isEmpty()) {
            String[] parts = line.split(" ");
            String command = parts[0];

            if (command.equals("Query")) {
                int t = Integer.parseInt(parts[1]);
                queryTimesToProcess.add(t);
            } else if (command.equals("Chocolate")) {
                int t = Integer.parseInt(parts[1]);
                double n = Double.parseDouble(parts[2]);
                consumptions.add(new ConsumptionEvent(FoodType.CHOCOLATE, t, n));
            } else if (command.equals("Coffee")) {
                int t = Integer.parseInt(parts[1]);
                double n = Double.parseDouble(parts[2]);
                consumptions.add(new ConsumptionEvent(FoodType.COFFEE, t, n));
            }
        }
        List<QueryResult> results = new ArrayList<>();

        for (int currentQueryTime : queryTimesToProcess) {
            double totalSafetyDistance = 0.0;

            for (ConsumptionEvent event : consumptions) {
                if (event.consumptionTime > currentQueryTime) {
                    continue;
                }

                int elapsedTime = currentQueryTime - event.consumptionTime;
                double effectRadius = 0.0;

                if (event.type == FoodType.CHOCOLATE) {
                    effectRadius = 8.0 * event.amount - (double) elapsedTime / 12.0;
                } else {
                    effectRadius = 2.0 * event.amount - ((double) elapsedTime * elapsedTime) / 79.0;
                }

                if (effectRadius < 0) {
                    effectRadius = 0.0;
                }
                totalSafetyDistance += effectRadius;
            }

            if (totalSafetyDistance < 1.0) {
                totalSafetyDistance = 1.0;
            }

            results.add(new QueryResult(currentQueryTime, totalSafetyDistance));
        }

        Collections.sort(results);

        for (QueryResult result : results) {
            pw.println(result.getFormattedOutput());
        }

        pw.flush();
        pw.close();
        br.close();
    }
}