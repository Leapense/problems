import java.io.*;
import java.util.*;

public class Main {
    static class Player {
        int location;
        Map<Integer, Integer> items;

        Player() {
            this.location = 1;
            this.items = new HashMap<>();
        }

        void move(int newLocation) {
            this.location = newLocation;
        }

        void addItem(int itemId) {
            items.put(itemId, items.getOrDefault(itemId, 0) + 1);
        }

        boolean hasItem(int itemId) {
            return items.getOrDefault(itemId, 0) > 0;
        }

        void useItem(int itemId) {
            if (hasItem(itemId)) {
                items.put(itemId, items.get(itemId) - 1);
                if (items.get(itemId) == 0) {
                    items.remove(itemId);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        Map<Integer, Player> players = new HashMap<>();
        List<Integer> cheatingLogs = new ArrayList<>();
        Set<Integer> bannedPlayers = new TreeSet<>();

        for (int i = 1; i <= T; i++) {
            st = new StringTokenizer(br.readLine());
            int logNum = Integer.parseInt(st.nextToken());
            int playerId = Integer.parseInt(st.nextToken());
            String action = st.nextToken();

            players.putIfAbsent(playerId, new Player());
            Player player = players.get(playerId);

            boolean isCheating = false;

            switch(action) {
                case "M":
                    int newLocation = Integer.parseInt(st.nextToken());
                    player.move(newLocation);
                    break;
                case "F":
                    int itemId = Integer.parseInt(st.nextToken());
                    if (player.location != itemId) {
                        isCheating = true;
                    }

                    player.addItem(itemId);
                    break;
                case "C":
                    int item1 = Integer.parseInt(st.nextToken());
                    int item2 = Integer.parseInt(st.nextToken());

                    if (!player.hasItem(item1) || !player.hasItem(item2)) {
                        isCheating = true;
                    }

                    if (player.hasItem(item1)) {
                        player.useItem(item1);
                    }
                    if (player.hasItem(item2)) {
                        player.useItem(item2);
                    }
                    break;
                case "A":
                    int targetId = Integer.parseInt(st.nextToken());
                    players.putIfAbsent(targetId, new Player());
                    Player target = players.get(targetId);
                    if (player.location != target.location) {
                        isCheating = true;
                        bannedPlayers.add(playerId);
                    }

                    break;
            }

            if (isCheating) {
                cheatingLogs.add(logNum);
            }
        }

        System.out.println(cheatingLogs.size());
        if (!cheatingLogs.isEmpty()) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < cheatingLogs.size(); i++) {
                if (i > 0) sb.append(" ");
                sb.append(cheatingLogs.get(i));
            }

            System.out.println(sb.toString());
        }

        System.out.println(bannedPlayers.size());
        if (!bannedPlayers.isEmpty()) {
            StringBuilder sb = new StringBuilder();
            boolean first = true;
            for (int playerId : bannedPlayers) {
                if (!first) sb.append(" ");
                sb.append(playerId);
                first = false;
            }
            System.out.println(sb.toString());
        }
    }
}