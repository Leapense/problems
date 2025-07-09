import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());
        long[] prefix = new long[n];

        tokenizer = new StringTokenizer(reader.readLine());
        prefix[0] = Long.parseLong(tokenizer.nextToken());

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + Long.parseLong(tokenizer.nextToken());
        }

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int i = 0; i < m; i++) {
            long t = Long.parseLong(reader.readLine());
            int idx = Arrays.binarySearch(prefix, t);
            int result = idx >= 0 ? idx + 1 : -idx - 1;
            writer.write(Integer.toString(result));
            writer.newLine();
        }
        writer.flush();
    }
}