import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(reader.readLine().trim());
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            String[] parts = reader.readLine().trim().split("\\s+");
            int N = Integer.parseInt(parts[0]);
            int M = Integer.parseInt(parts[1]);

            Set<String> existing = new HashSet<>();

            for (int i = 0; i < N; i++) {
                String path = reader.readLine().trim();
                addAllPrefixes(path, existing);
            }

            int mkdirCount = 0;

            for (int i = 0; i < M; i++) {
                String newPath = reader.readLine().trim();
                StringBuilder prefixBuilder = new StringBuilder();
                String[] comps = newPath.split("/");

                for (int j = 1; j < comps.length; j++) {
                    prefixBuilder.append('/').append(comps[j]);
                    String prefix = prefixBuilder.toString();
                    if (!existing.contains(prefix)) {
                        mkdirCount++;
                        existing.add(prefix);
                    }
                }
            }

            System.out.printf("Case #%d: %d%n", caseNum, mkdirCount);
        }
        reader.close();
    }

    private static void addAllPrefixes(String path, Set<String> existing) {
        StringBuilder builder = new StringBuilder();
        String[] comps = path.split("/");
        for (int i = 1; i < comps.length; i++) {
            builder.append('/').append(comps[i]);
            existing.add(builder.toString());
        }
    }
}