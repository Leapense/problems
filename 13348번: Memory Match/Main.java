import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int K = in.nextInt();

        int matchedPairs = 0;

        boolean[] removed = new boolean[N + 1];
        boolean[] knownPos = new boolean[N + 1];

        String[] picAt = new String[N + 1];

        Set<String> matchedPicNames = new HashSet<>();

        for (int turn = 0; turn < K; turn++) {
            int c1 = in.nextInt();
            int c2 = in.nextInt();
            String p1 = in.next();
            String p2 = in.next();

            if (p1.equals(p2)) {
                if (!matchedPicNames.contains(p1)) {
                    matchedPicNames.add(p1);
                    matchedPairs++;
                }

                removed[c1] = true;
                removed[c2] = true;

                knownPos[c1] = false;
                knownPos[c2] = false;
            } else {
                if (!removed[c1] && !knownPos[c1]) {
                    knownPos[c1] = true;
                    picAt[c1] = p1;
                }
                if (!removed[c2] && !knownPos[c2]) {
                    knownPos[c2] = true;
                    picAt[c2] = p2;
                }
            }
        }

        Map<String, int[]> countMap = new HashMap<>();

        for (int pos = 1; pos <= N; pos++) {
            if (removed[pos] || !knownPos[pos]) {
                continue;
            }

            String pic = picAt[pos];
            if (matchedPicNames.contains(pic)) {
                continue;
            }

            countMap.computeIfAbsent(pic, k -> new int[1])[0]++;
        }

        int X2 = 0;
        int X1 = 0;

        for (int[] kc : countMap.values()) {
            if (kc[0] == 2) {
                X2++;
            } else if (kc[0] == 1) {
                X1++;
            }
        }

        int Ptotal = N / 2;
        int X0 = Ptotal - matchedPairs - X2 - X1;

        int answer = X2;
        if (X0 == 0) {
            answer += X1;
        } else if (X0 == 1 && X1 == 0) {
            answer += 1;
        }

        System.out.println(answer);
    }
}