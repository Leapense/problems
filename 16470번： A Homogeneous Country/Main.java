import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String> lines = new ArrayList<>();

        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            if (line.isEmpty()) break;
            lines.add(line);
        }

        scanner.close();

        Map<String, Integer> countMap = new HashMap<>();
        for (String line : lines) {
            countMap.put(line, countMap.getOrDefault(line, 0) + 1);
        }

        int m = lines.size();

        double gini = 1.0;
        for (int freq : countMap.values()) {
            double p = (double) freq / m;
            gini -= p * p;
        }

        System.out.printf("%.6f\n", gini);
    }
}