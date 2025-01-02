import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Game {
        int id;
        long price;
        long satisfaction;
        double value;

        public Game(int id, long price, long satisfaction) {
            this.id = id;
            this.price = price;
            this.satisfaction = satisfaction;
            this.value = (double) satisfaction / price;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] firstLine = br.readLine().trim().split("\\s+");
        int N = Integer.parseInt(firstLine[0]);
        int K = Integer.parseInt(firstLine[1]);

        List<Game> games = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            String[] gameInfo = br.readLine().trim().split("\\s+");
            int id = Integer.parseInt(gameInfo[0]);
            long price = Long.parseLong(gameInfo[1]);
            long satisfaction = Long.parseLong(gameInfo[2]);
            games.add(new Game(id, price, satisfaction));

        }

        Collections.sort(games, new Comparator<Game>() {
            @Override
            public int compare(Game g1, Game g2) {
                if (Double.compare(g2.value, g1.value) != 0) {
                    return Double.compare(g2.value, g1.value);
                }
                if (g1.price != g2.price) {
                    return Long.compare(g1.price, g2.price);
                }

                return Integer.compare(g1.id, g2.id);
            }
        });

        for (int i = 0; i < K; i++) {
            System.out.println(games.get(i).id);
        }
    }
}