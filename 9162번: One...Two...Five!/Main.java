import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main
{
    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            String line;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if ("#".equals(line)) {
                    break;
                }
                if (line.isEmpty()) {
                    continue;
                }

                String[] tokens = line.split("\\s+");
                int[] numbers = new int[tokens.length];
                for (int i = 0; i < tokens.length; i++) {
                    numbers[i] = Integer.parseInt(tokens[i]);
                }

                long answer = solveLine(numbers);
                if (answer == Long.MIN_VALUE) {
                    System.out.println("No result");
                } else {
                    System.out.println(answer);
                }
            }
        }
    }

    private static long solveLine(int[] numbers) {
        Map<Long, Integer> dpMap = new HashMap<>();
        dpMap.put((long) numbers[0], 1);

        for (int i = 1; i < numbers.length; i++) {
            int current = numbers[i];
            Map<Long, Integer> nextMap = new HashMap<>();

            for (Map.Entry<Long, Integer> entry : dpMap.entrySet()) {
                long value = entry.getKey();
                int count = entry.getValue();

                accumulate(nextMap, value + current, count);
                accumulate(nextMap, Math.abs(value - current), count);
                accumulate(nextMap, value * current, count);
                if (current != 0) {
                    accumulate(nextMap, value / current, count);
                }
            }
            dpMap = nextMap;
        }

        long bestNumber = Long.MIN_VALUE;
        int bestCount = 0;
        for (Map.Entry<Long, Integer> entry : dpMap.entrySet()) {
            long num = entry.getKey();
            int cnt = entry.getValue();
            if (containsDigitThree(num)) {
                if (cnt > bestCount || (cnt == bestCount && num > bestNumber)) {
                    bestCount = cnt;
                    bestNumber = num;
                }
            }
        }

        return (bestCount > 0) ? bestNumber : Long.MIN_VALUE;
    }

    private static void accumulate(Map<Long, Integer> map, long key, int count) 
    {
        map.put(key, map.getOrDefault(key, 0) + count);
    }

    private static boolean containsDigitThree(long number) {
        return String.valueOf(number).indexOf('3') >= 0;
    }
}