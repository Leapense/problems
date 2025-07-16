import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public final class Main
{
    public static void main(String[] args) throws IOException
    {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            long m = Long.parseLong(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            List<Beer> beers = new ArrayList<>();
            for (int i = 0; i < k; i++) {
                st = new StringTokenizer(br.readLine());
                int preference = Integer.parseInt(st.nextToken());
                int alcoholLevel = Integer.parseInt(st.nextToken());
                beers.add(new Beer(preference, alcoholLevel));
            }

            Collections.sort(beers);

            PriorityQueue<Integer> preferenceQueue = new PriorityQueue<>();
            long currentPreferenceSum = 0;
            int result = -1;

            for (Beer beer : beers) {
                preferenceQueue.add(beer.getPreference());
                currentPreferenceSum += beer.getPreference();

                if (preferenceQueue.size() > n) 
                {
                    currentPreferenceSum -= preferenceQueue.poll();
                }

                if (preferenceQueue.size() == n && currentPreferenceSum >= m) {
                    result = beer.getAlcoholLevel();
                    break;
                }
            }

            System.out.println(result);
        }
    }

    private static final class Beer implements Comparable<Beer> {
        private final int preference;
        private final int alcoholLevel;

        public Beer(int preference, int alcoholLevel) {
            this.preference = preference;
            this.alcoholLevel = alcoholLevel;
        }

        public int getPreference() {
            return preference;
        }

        public int getAlcoholLevel() {
            return alcoholLevel;
        }

        @Override
        public int compareTo(Beer other) {
            if (this.alcoholLevel == other.alcoholLevel) {
                return Integer.compare(other.preference, this.preference);
            }

            return Integer.compare(this.alcoholLevel, other.alcoholLevel);
        }
    }
}