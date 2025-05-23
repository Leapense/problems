import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int contestNumber = 1;
        while (true) {
            String line = br.readLine();
            if (line == null || line.trim().isEmpty()) {
                continue;
            }

            int P = Integer.parseInt(line.trim());
            if (P == 0)
                break;

            String[] pointsStr = br.readLine().trim().split("\\s+");
            int[] points = new int[P];
            for (int i = 0; i < P; i++) {
                points[i] = Integer.parseInt(pointsStr[i]);
            }
            int T = Integer.parseInt(br.readLine().trim());
            List<Team> teams = new ArrayList<>();
            for (int i = 0; i < T; i++) {
                String teamLine = br.readLine();
                String[] parts = teamLine.split(",");
                String teamName = parts[0];
                int totalPoints = 0;

                for (int j = 1; j < parts.length; j++) {
                    String[] record = parts[j].split("/");
                    if (!record[1].equals("-")) {
                        totalPoints += points[j - 1];
                    }
                }

                teams.add(new Team(teamName, totalPoints));
            }

            Collections.sort(teams, new Comparator<Team>() {
                public int compare(Team t1, Team t2) {
                    if (t2.score != t1.score)
                        return t2.score - t1.score;
                    return t1.name.toLowerCase().compareTo(t2.name.toLowerCase());
                }
            });

            System.out.println("Contest " + contestNumber);
            int rank = 1;
            int printed = 0;
            int prevScore = -1;
            for (Team t : teams) {
                printed++;
                if (t.score != prevScore) {
                    rank = printed;
                }
                System.out.println(rank + " " + t.name + " " + t.score);
                prevScore = t.score;
            }
            contestNumber++;
        }
    }
}

class Team {
    String name;
    int score;

    public Team(String name, int score) {
        this.name = name;
        this.score = score;
    }
}