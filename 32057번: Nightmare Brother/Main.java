import java.io.*;
import java.util.*;

public class Main {
    static class Hint {
        int x;
        String t;
        Hint(int x, String t) { this.x = x; this.t = t; }
    }

    static String buildCandidate(int M, List<Hint> hints, int omitIdx) {
        char[] s = new char[M];
        Arrays.fill(s, '?');

        for (int i = 0; i < hints.size(); i++) {
            if (i == omitIdx) continue;
            Hint h = hints.get(i);
            int start = h.x - 1;
            String t = h.t;
            for (int k = 0; k < t.length(); k++) {
                int pos = start + k;
                char c = t.charAt(k);
                if (s[pos] == '?') {
                    s[pos] = c;
                } else if (s[pos] != c) {
                    return null;
                }
            }
        }

        for (int i = 0; i < M; i++) {
            if (s[i] == '?') return null;
        }

        return new String(s);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        List<Hint> hints = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            String t = st.nextToken().trim();
            hints.add(new Hint(x, t));
        }

        Set<String> candidates = new LinkedHashSet<>();

        String cand = buildCandidate(M, hints, -1);
        if (cand != null) candidates.add(cand);

        for (int omit = 0; omit < N; omit++) {
            cand = buildCandidate(M, hints, omit);
            if (cand != null) candidates.add(cand);
        }

        if (candidates.isEmpty()) {
            System.out.println(-1);
        } else if (candidates.size() == 1) {
            System.out.println(candidates.iterator().next());
        } else {
            System.out.println(-2);
        }
    }
}