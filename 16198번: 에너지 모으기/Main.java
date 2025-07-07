import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public final class Main {
    private static int maxEnergy;

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine().trim());
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        List<Integer> beads = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            beads.add(Integer.parseInt(tokenizer.nextToken()));
        }
        maxEnergy = 0;
        gather(beads, 0);
        System.out.println(maxEnergy);
    }

    private static void gather(List<Integer> beads, int collected) {
        int size = beads.size();
        if (size == 2) {
            if (collected > maxEnergy) {
                maxEnergy = collected;
            }
            return;
        }

        for (int i = 1; i < size - 1; i++) {
            int gain = beads.get(i - 1) * beads.get(i + 1);
            int removed = beads.remove(i);
            gather(beads, collected + gain);
            beads.add(i, removed);
        }
    }
}