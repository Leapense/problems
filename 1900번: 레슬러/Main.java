import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Wrestler {
    int id;
    int strength;
    int ringPower;

    public Wrestler(int id, int strength, int ringPower) {
        this.id = id;
        this.strength = strength;
        this.ringPower = ringPower;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        List<Wrestler> wrestlers = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());

            wrestlers.add(new Wrestler(i + 1, s, r));

        }
        Collections.sort(wrestlers, (w1, w2) -> {
            long val1NumeratorPart = (long) (w1.ringPower - 1) * w2.strength;
            long val2NumeratorPart = (long) (w2.ringPower - 1) * w1.strength;

            if (val1NumeratorPart > val2NumeratorPart) {
                return -1;
            } else if (val1NumeratorPart < val2NumeratorPart) {
                return 1;
            } else {
                return 0;
            }
        });

        StringBuilder sb = new StringBuilder();

        for (Wrestler wrestler : wrestlers) {
            sb.append(wrestler.id).append("\n");
        }

        System.out.print(sb.toString());
    }
}