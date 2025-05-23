import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] tokens = br.readLine().split(" ");

        Map<Integer, Long> freqMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int color = Integer.parseInt(tokens[i]);
            freqMap.put(color, freqMap.getOrDefault(color, 0L) + 1);
        }

        long sameCells = 0;

        for (long freq : freqMap.values()) {
            sameCells += freq * freq;
        }

        long totalCells = (long) n * n;
        long result = totalCells - sameCells;

        System.out.println(result);
    }
}