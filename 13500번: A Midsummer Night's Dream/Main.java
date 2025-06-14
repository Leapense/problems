import java.io.*;
import java.util.*;

public class Main {
    static class Location {
        int x;
        int y;
        int t;

        public Location(int x, int y, int t) {
            this.x = x;
            this.y = y;
            this.t = t;
        }
    }

    static class Person {
        int id;
        int potionTime;
        List<Location> locations;
        int loves = -1;

        public Person(int id) {
            this.id = id;
            this.locations = new ArrayList<>();
        }

        public Location getLocationAtTime(int time) {
            Location currentPos = null;

            for (int i = locations.size() - 1; i >= 0; i--) {
                if (locations.get(i).t <= time) {
                    currentPos = locations.get(i);
                    break;
                }
            }

            return currentPos;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String kLine = br.readLine();
        if (kLine == null || kLine.trim().isEmpty()) {
            return;
        }

        int k = Integer.parseInt(kLine);
        for (int i = 1; i <= k; i++) {
            String line = br.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = br.readLine();
            }

            if (line == null) break;

            System.out.println("Data Set " + i + ":");
            solve(br, line);
            System.out.println();
        }
    }

    private static void solve(BufferedReader br, String firstLine) throws Exception {
        StringTokenizer st = new StringTokenizer(firstLine);
        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        Person[] people = new Person[n];
        for (int i = 0; i < n; i++) {
            people[i] = new Person(i);
            st = new StringTokenizer(br.readLine());
            people[i].potionTime = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            String locationLine = br.readLine();
            if (m > 0 && locationLine != null) {
                st = new StringTokenizer(locationLine);
                for (int j = 0; j < m; j++) {
                    int x = Integer.parseInt(st.nextToken());
                    int y = Integer.parseInt(st.nextToken());
                    int t = Integer.parseInt(st.nextToken());
                    people[i].locations.add(new Location(x, y, t));
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (people[i].potionTime != -1) {
                findLoveTarget(i, people, n, d);
            }
        }

        int coupleCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (people[i].loves == j && people[j].loves == i) {
                    coupleCount++;
                }
            }
        }

        System.out.println(coupleCount);
    }

    private static void findLoveTarget(int personIndex, Person[] people, int n, int d) {
        Person me = people[personIndex];
        Set<Integer> eventTimes = new TreeSet<>();
        eventTimes.add(me.potionTime);
        for (Person p : people) {
            for (Location loc : p.locations) {
                if (loc.t >= me.potionTime) {
                    eventTimes.add(loc.t);
                }
            }
        }

        for (int t : eventTimes) {
            Location myLocation = me.getLocationAtTime(t);
            if (myLocation == null) {
                continue;
            }

            List<Integer> candidates = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                if (personIndex == j) {
                    continue;
                }

                Person other = people[j];
                Location otherLocation = other.getLocationAtTime(t);
                if (otherLocation == null) {
                    continue;
                }

                double distSq = Math.pow(myLocation.x - otherLocation.x, 2) + Math.pow(myLocation.y - otherLocation.y, 2);
                if (distSq <= (double)d * d) {
                    candidates.add(j);
                }
            }

            if (!candidates.isEmpty()) {
                int bestCandidate = -1;
                double minDistanceSq = Double.MAX_VALUE;

                for (int candidateId : candidates) {
                    Location candidateLocation = people[candidateId].getLocationAtTime(t);
                    double distSq = Math.pow(myLocation.x - candidateLocation.x, 2) + Math.pow(myLocation.y - candidateLocation.y, 2);
                    if (distSq < minDistanceSq) {
                        minDistanceSq = distSq;
                        bestCandidate = candidateId;
                    }
                }

                me.loves = bestCandidate;
                return;
            }
        }
    }
}