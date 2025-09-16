import java.io.*;
import java.util.*;

public class Main {
    static class Key {
        final String name;
        final boolean[] allow = new boolean[12];
        final String[] pcName = new String[12];

        Key(String name, int[] pcs, String[] names) {
            this.name = name;
            for (int i = 0; i < pcs.length; i++) {
                int pc = pcs[i];
                allow[pc] = true;
                pcName[pc] = names[i];
            }
        }
    }

    static final double LOG2 = Math.log(2.0);
    static int pitchClass(double f) {
        double aReal = 12.0 * (Math.log(f / 440.0) / LOG2);
        int a = (int) Math.round(aReal);
        int pc = ((a % 12) + 12) % 12;
        return pc;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        int[] pcs = new int[N];
        boolean[] seen = new boolean[12];

        for (int i = 0; i < N; i++) {
            double f = Double.parseDouble(br.readLine().trim());
            int pc = pitchClass(f);
            pcs[i] = pc;
            seen[pc] = true;
        }

        List<Key> keys = new ArrayList<>();
        keys.add(new Key(
            "G major",
            new int[]{10,0,2,3,5,7,9},
            new String[]{"G","A","B","C","D","E","F#"}
        ));
        keys.add(new Key(
            "C major",
            new int[]{3,5,7,8,10,0,2},
            new String[]{"C","D","E","F","G","A","B"}
        ));
        keys.add(new Key(
            "Eb major",
            new int[]{6,8,10,11,1,3,5},
            new String[]{"Eb","F","G","Ab","Bb","C","D"}
        ));
        keys.add(new Key(
            "F# minor",
            new int[]{9,11,0,2,4,5,7},
            new String[]{"F#","G#","A","B","C#","D","E"}
        ));
        keys.add(new Key(
            "G minor",
            new int[]{10,0,1,3,5,6,8},
            new String[]{"G","A","Bb","C","D","Eb","F"}
        ));

        List<Key> candidates = new ArrayList<>();
        outer:
        for (Key k : keys) {
            for (int pc = 0; pc < 12; pc++) {
                if (seen[pc] && !k.allow[pc]) continue outer;
            }
            candidates.add(k);
        }

        if (candidates.size() != 1) {
            System.out.println("cannot determine key");
            return;
        }

        Key K = candidates.get(0);
        System.out.println(K.name);
        for (int pc : pcs) {
            System.out.println(K.pcName[pc]);
        }
    }
}