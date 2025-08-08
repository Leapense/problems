import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedHashMap;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String header = nextNonEmptyLine(reader);
        if (header == null) {
            return;
        }
        String[] parts = header.trim().split("\\s+");
        int n = Integer.parseInt(parts[0]);
        int m = Integer.parseInt(parts[1]);

        int capacity = Math.max(16, (int) Math.ceil(m / 0.75d) + 1);
        LruCache cache = new LruCache(capacity, m);

        for (int i = 0; i < n; i++) {
            String line = nextNonEmptyLine(reader);
            if (line == null) {
                break;
            }
            int id = Integer.parseInt(line.trim());
            cache.touch(id);
        }

        List<Integer> order = cache.keysOldestToNewest();
        StringBuilder out = new StringBuilder();
        for (int i = order.size() - 1; i >= 0; i--) {
            out.append(order.get(i)).append('\n');
        }

        System.out.print(out.toString());
    }

    private static String nextNonEmptyLine(BufferedReader reader) throws IOException {
        String s = reader.readLine();
        while (s != null && s.trim().isEmpty()) {
            s = reader.readLine();
        }

        return s;
    }

    private static final class LruCache {
        private final int maxSize;
        private final LinkedHashMap<Integer, Boolean> map;

        LruCache(int initialCapacity, int maxSize) {
            this.maxSize = maxSize;
            this.map = new LinkedHashMap<Integer, Boolean>(initialCapacity, 0.75f, true) {
                @Override
                protected boolean removeEldestEntry(Map.Entry<Integer, Boolean> eldest) {
                    return size() > LruCache.this.maxSize;
                }
            };
        }

        void touch(int id) {
            map.put(id, Boolean.TRUE);
        }
        List<Integer> keysOldestToNewest() {
            List<Integer> keys = new ArrayList<>(map.size());
            for (Integer k : map.keySet()) {
                keys.add(k);
            }

            return keys;
        }
    }
}