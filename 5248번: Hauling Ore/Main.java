
// Main.java
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String pending = null; // 다음 테스트의 "GRAPH BEGIN"을 미리 저장
        StringBuilder out = new StringBuilder();

        while (true) {
            String line;
            if (pending != null) { // 이전 루프에서 읽어 둔 BEGIN
                line = pending;
                pending = null;
            } else {
                line = br.readLine();
            }
            if (line == null)
                break;

            line = line.trim();
            if (!"GRAPH BEGIN".equals(line))
                continue; // 케이스 시작까지 스킵

            /* ---------- 1. 그래프 구축 ---------- */
            Map<String, Set<String>> adj = new HashMap<>();
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if ("GRAPH END".equals(line))
                    break;
                if (line.isEmpty())
                    continue;
                String[] tok = line.split("\\s+");
                String u = tok[0];
                adj.computeIfAbsent(u, k -> new HashSet<>());
                for (int i = 1; i < tok.length; ++i) {
                    String v = tok[i];
                    adj.computeIfAbsent(v, k -> new HashSet<>());
                    adj.get(u).add(v);
                    adj.get(v).add(u);
                }
            }

            /* ---------- 2. 질의 처리 ---------- */
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty())
                    continue;
                if ("GRAPH BEGIN".equals(line)) { // 다음 케이스 시작
                    pending = line;
                    break;
                }

                String s = line;
                Set<String> neighbors = adj.getOrDefault(s, Collections.emptySet());
                Set<String> ans = new TreeSet<>();

                for (String n : neighbors) {
                    for (String m : adj.getOrDefault(n, Collections.emptySet())) {
                        if (!m.equals(s) && !neighbors.contains(m))
                            ans.add(m);
                    }
                }
                if (ans.isEmpty())
                    out.append("NONE");
                else {
                    boolean first = true;
                    for (String v : ans) {
                        if (!first)
                            out.append(' ');
                        out.append(v);
                        first = false;
                    }
                }
                out.append('\n');
            }
            if (line == null)
                break; // EOF
        }
        System.out.print(out.toString());
    }
}
