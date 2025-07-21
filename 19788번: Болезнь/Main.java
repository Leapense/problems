import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());
        boolean[] impossible = new boolean[n + 1];
        List<int[]> positiveTests = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int[] row = new int[n + 1];
            for (int j = 1; j <= n; j++) {
                row[j] = Integer.parseInt(tokenizer.nextToken());
            }
            int result = Integer.parseInt(tokenizer.nextToken());
            if (result == 0) {
                for (int j = 1; j <= n; j++) {
                    if (row[j] == 1) {
                        impossible[j] = true;
                    }
                }
            } else {
                positiveTests.add(row);
            }
        }
        boolean[] definite = new boolean[n + 1];
        for (int[] row : positiveTests) {
            List<Integer> candidates = new ArrayList<>();
            for (int j = 1; j <= n; j++) {
                if (row[j] == 1 && !impossible[j]) {
                    candidates.add(j);
                }
            }
            if (candidates.isEmpty()) {
                writer.write("Incorrect");
                writer.newLine();
                writer.flush();
                return;
            }
            if (candidates.size() == 1) {
                definite[candidates.get(0)] = true;
            }
        }
        List<Integer> impossibleList = new ArrayList<>();
        List<Integer> definiteList = new ArrayList<>();
        List<Integer> unknownList = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (impossible[i]) {
                impossibleList.add(i);
            } else if (definite[i]) {
                definiteList.add(i);
            } else {
                unknownList.add(i);
            }
        }

        writeResult(writer, impossibleList);
        writeResult(writer, definiteList);
        writeResult(writer, unknownList);
        writer.flush();
    }

    private static void writeResult(BufferedWriter writer, List<Integer> list) throws IOException {
        if (list.isEmpty()) {
            writer.write("0");
        } else {
            writer.write(String.valueOf(list.size()));
            for (int x : list) {
                writer.write(" ");
                writer.write(String.valueOf(x));
            }
        }

        writer.newLine();
    }
}