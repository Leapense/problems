import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        while (line != null && line.trim().isEmpty()) line = br.readLine();
        int n = Integer.parseInt(line.trim());

        List<Integer> answer = solve(n);

        StringBuilder sb = new StringBuilder();
        sb.append(answer.size()).append('\n');
        for (int i = 0; i < answer.size(); i++) {
            if (i > 0) sb.append(' ');
            sb.append(answer.get(i));
        }
        System.out.println(sb.toString());
    }

    static List<Integer> solve(int n) {
        List<Integer> result = new ArrayList<>();
        List<Long> prefix = new ArrayList<>();
        prefix.add(0L);
        int x = 0;
        long total = 0;
        while(total < n) {
            x++;
            total += Integer.bitCount(x);
            prefix.add(total);
        }

        long need = n;
        for (int i = x; i >= 1; i--) {
            long prev = prefix.get(i - 1);
            if (need > prev) {
                result.add(i);
                need -= Integer.bitCount(i);
            }
            if (need == 0) break;
        }

        return result;
    }
}