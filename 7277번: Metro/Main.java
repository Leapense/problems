import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
                BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out))) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            int trainCount = Integer.parseInt(st.nextToken());
            int targetGap = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(reader.readLine());
            long[] prefixDiff = new long[trainCount];
            long minPrefix = 0;
            long cumulative = 0;

            for (int i = 1; i < trainCount; i++) {
                int currentGap = Integer.parseInt(st.nextToken());
                cumulative += (long) targetGap - currentGap;
                prefixDiff[i] = cumulative;
                if (cumulative < minPrefix) {
                    minPrefix = cumulative;
                }
            }

            long firstDelay = Math.max(0, -minPrefix);

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < trainCount; i++) {
                long delay = firstDelay + prefixDiff[i];
                sb.append(delay);
                if (i < trainCount - 1) {
                    sb.append(' ');
                }
            }

            writer.write(sb.toString());
            writer.newLine();
            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}