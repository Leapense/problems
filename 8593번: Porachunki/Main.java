import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine().trim());
        long totalDiff = 0L;
        long[] diff = new long[n];

        for (int i = 0; i < n; i++) {
            String[] parts = reader.readLine().split(" ");
            int contract = Integer.parseInt(parts[0]);
            int actual = Integer.parseInt(parts[1]);
            diff[i] = (long) actual - contract;
            totalDiff += diff[i];
        }

        if (totalDiff != 0L) {
            System.out.println("NIE");
            return;
        }
        Map<Long, Integer> frequencyMap = new HashMap<>(n);
        long prefixSum = 0L;
        int maxFreq = 0;

        for (long delta : diff) {
            prefixSum += delta;
            int count = frequencyMap.getOrDefault(prefixSum, 0) + 1;
            frequencyMap.put(prefixSum, count);
            if (count > maxFreq) {
                maxFreq = count;
            }
        }

        int result = n - maxFreq;
        System.out.println(result);
    }
}