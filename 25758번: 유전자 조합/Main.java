import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine().trim());
            int[] countFirst = new int[26];
            int[] countSecond = new int[26];
            int[] repFirst = new int[26];
            int[] repSecond = new int[26];
            for (int i = 0; i < 26; i++) {
                repFirst[i] = -1;
                repSecond[i] = -1;
            }
            StringTokenizer st = new StringTokenizer("");
            List<String> tokens = new ArrayList<>();
            while (tokens.size() < n) {
                if (!st.hasMoreTokens()) {
                    String line = br.readLine();
                    if (line == null) break;
                    st = new StringTokenizer(line);
                }
                while (st.hasMoreTokens() && tokens.size() < n) {
                    tokens.add(st.nextToken());
                }
            }

            for (int i = 0; i < n; i++) {
                String g = tokens.get(i);
                char f = g.charAt(0);
                char s = g.charAt(1);
                int fi = f - 'A';
                int si = s - 'A';
                countFirst[fi]++;
                countSecond[si]++;
                if (repFirst[fi] == -1) repFirst[fi] = i;
                if (repSecond[si] == -1) repSecond[si] = i;
            }

            boolean[] result = new boolean[26];
            for (int fi = 0; fi < 26; fi++) {
                if (countFirst[fi] == 0) continue;
                for (int si = 0; si < 26; si++) {
                    if (countSecond[si] == 0) continue;
                    boolean possible = false;
                    if (countFirst[fi] >= 2 || countSecond[si] >= 2) possible = true;
                    else {
                        if (repFirst[fi] != -1 && repSecond[si] != -1 && repFirst[fi] != repSecond[si]) possible = true;
                    }
                    if (possible) {
                        int mi = Math.max(fi, si);
                        result[mi] = true;
                    }
                }
            }

            StringBuilder sb = new StringBuilder();
            int cnt = 0;
            for (int i = 0; i < 26; i++) if (result[i]) cnt++;
            sb.append(cnt).append('\n');
            boolean firstOut = true;
            for (int i = 0; i < 26; i++) {
                if (result[i]) {
                    if (!firstOut) sb.append(' ');
                    sb.append((char)('A' + i));
                    firstOut = false;
                }
            }

            sb.append('\n');
            System.out.print(sb.toString());
        } catch (IOException e) {
            throw e;
        }
    }
}