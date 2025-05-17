import java.util.*;
import java.io.*;

public class Main {
    private static final int[] DAYS = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    private static int toMinutes(String mmdd, String hhmm) {
        String[] md = mmdd.split("/");
        int m = Integer.parseInt(md[0]);
        int d = Integer.parseInt(md[1]);

        String[] hm = hhmm.split(":");
        int h = Integer.parseInt(hm[0]);
        int min = Integer.parseInt(hm[1]);

        int totalDays = d;
        for (int i = 1; i < m; ++i)
            totalDays += DAYS[i];
        return (totalDays - 1) * 24 * 60 + h * 60 + min;
    }

    private static class Entry {
        int time;
        String action;
        String id;

        Entry(int time, String action, String id) {
            this.time = time;
            this.action = action;
            this.id = id;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            int n;
            line = line.trim();
            if (line.equals("0"))
                break;
            n = Integer.parseInt(line);
            List<Entry> log = new ArrayList<>(n);
            for (int i = 0; i < n; ++i) {
                String[] parts = br.readLine().trim().split("\\s+");
                int time = toMinutes(parts[0], parts[1]);
                log.add(new Entry(time, parts[2], parts[3]));
            }

            Map<String, Integer> progEntry = new HashMap<>();
            Map<String, Integer> goddessEntry = new HashMap<>();
            Map<String, Integer> blessed = new HashMap<>();

            boolean goddessPresent = false;
            int goddessEnterTime = -1;

            Map<String, Integer> currentProgEntry = new HashMap<>();

            for (Entry e : log) {
                if (e.id.equals("000")) {
                    if (e.action.equals("I")) {
                        goddessPresent = true;
                        goddessEnterTime = e.time;
                    } else {
                        for (Map.Entry<String, Integer> ent : currentProgEntry.entrySet()) {
                            String pid = ent.getKey();
                            int enter = ent.getValue();

                            int start = Math.max(enter, goddessEnterTime);
                            int end = e.time;
                            int overlap = end - start;
                            if (overlap > 0) {
                                blessed.put(pid, blessed.getOrDefault(pid, 0) + overlap);
                            }
                        }

                        goddessPresent = false;
                    }
                } else {
                    if (e.action.equals("I")) {
                        currentProgEntry.put(e.id, e.time);
                    } else {
                        Integer enter = currentProgEntry.remove(e.id);
                        if (goddessPresent) {
                            int start = Math.max(enter, goddessEnterTime);
                            int end = e.time;
                            int overlap = end - start;
                            if (overlap > 0) {
                                blessed.put(e.id, blessed.getOrDefault(e.id, 0) + overlap);
                            }
                        }
                    }
                }
            }

            int result = 0;
            for (Map.Entry<String, Integer> ent : blessed.entrySet()) {
                if (!ent.getKey().equals("000")) {
                    result = Math.max(result, ent.getValue());
                }
            }

            System.out.println(result);
        }
    }
}