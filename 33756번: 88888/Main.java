import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main
{
    private static final List<Long> EIGHT_NUMBERS = new ArrayList<>();
    private static final Set<Long> LUCKY_NUMBERS = new HashSet<>();
    private static final long MAX_VALUE = 1_000_000_000_000_000_000L;

    static {
        long number = 8;
        for (int i = 0; i < 18; i++) {
            EIGHT_NUMBERS.add(number);
            if (number > MAX_VALUE / 10) {
                break;
            }

            number = number * 10 + 8;
        }
        generateSums(0, 0, 0);
    }

    private static void generateSums(long currentSum, int count, int startIndex) {
        if (count > 8) {
            return;
        }

        if (currentSum > 0) {
            LUCKY_NUMBERS.add(currentSum);
        }

        if (count == 8) {
            return;
        }

        for (int i = startIndex; i < EIGHT_NUMBERS.size(); i++) {
            long numToAdd = EIGHT_NUMBERS.get(i);
            long newSum = currentSum + numToAdd;

            if (newSum > MAX_VALUE || newSum < currentSum) {
                continue;
            }

            generateSums(newSum, count + 1, i);
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < T; i++) {
            long n = Long.parseLong(br.readLine());
            if (LUCKY_NUMBERS.contains(n)) {
                sb.append("Yes\n");
            } else {
                sb.append("No\n");
            }
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}