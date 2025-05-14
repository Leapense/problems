import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        Map<Integer, Integer> counts = new HashMap<>();

        int numElementsWithDuplicates = 0;

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String operation = st.nextToken();
            int k = Integer.parseInt(st.nextToken());

            if (operation.equals("insert"))
            {
                int oldCount = counts.getOrDefault(k, 0);
                counts.put(k, oldCount + 1);

                if (oldCount + 1 == 2) {
                    numElementsWithDuplicates++;
                }
            }
            else
            {
                int oldCount = counts.getOrDefault(k, 0);

                if (oldCount > 0) {
                    counts.put(k, oldCount - 1);

                    if (oldCount - 1 == 0) {
                        counts.remove(k);
                    }

                    if (oldCount == 2) {
                        numElementsWithDuplicates--;
                    }
                }
            }

            boolean isHomogeneous = (numElementsWithDuplicates > 0);
            boolean isHeterogeneous = (counts.size() >= 2);

            if (isHomogeneous && isHeterogeneous) {
                pw.println("both");
            } else if (isHomogeneous) {
                pw.println("homo");
            } else if (isHeterogeneous) {
                pw.println("hetero");
            } else {
                pw.println("neither");
            }
        }

        pw.flush();
        pw.close();
        br.close();
    }
}