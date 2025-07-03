import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public final class Main {
    private Main() {
        throw new IllegalStateException("Utility class");
    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            final int rowCount = Integer.parseInt(reader.readLine().trim());
            final int[] prevMax = new int[3];
            final int[] prevMin = new int[3];
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
            for (int c = 0; c < 3; c++) {
                int value = Integer.parseInt(tokenizer.nextToken());
                prevMax[c] = value;
                prevMin[c] = value;
            }

            int[] curMax = new int[3];
            int[] curMin = new int[3];

            for (int row = 1; row < rowCount; row++) {
                tokenizer = new StringTokenizer(reader.readLine());
                int v0 = Integer.parseInt(tokenizer.nextToken());
                int v1 = Integer.parseInt(tokenizer.nextToken());
                int v2 = Integer.parseInt(tokenizer.nextToken());

                curMax[0] = v0 + Math.max(prevMax[0], prevMax[1]);
                curMax[1] = v1 + Math.max(Math.max(prevMax[0], prevMax[1]), prevMax[2]);
                curMax[2] = v2 + Math.max(prevMax[1], prevMax[2]);

                curMin[0] = v0 + Math.min(prevMin[0], prevMin[1]);
                curMin[1] = v1 + Math.min(Math.min(prevMin[0], prevMin[1]), prevMin[2]);
                curMin[2] = v2 + Math.min(prevMin[1], prevMin[2]);

                System.arraycopy(curMax, 0, prevMax, 0, 3);
                System.arraycopy(curMin, 0, prevMin, 0, 3);
            }

            int globalMax = Math.max(Math.max(prevMax[0], prevMax[1]), prevMax[2]);
            int globalMin = Math.min(Math.min(prevMin[0], prevMin[1]), prevMin[2]);

            StringBuilder out = new StringBuilder();
            out.append(globalMax).append(' ').append(globalMin);
            System.out.println(out);
        }
    }
}