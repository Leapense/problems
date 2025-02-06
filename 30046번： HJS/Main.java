import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine().trim());
        String P = br.readLine().trim();
        String Q = br.readLine().trim();
        String R = br.readLine().trim();

        int pos1 = -1;
        for (int i = 0; i < N; i++) {
            if (P.charAt(i) != Q.charAt(i)) {
                pos1 = i;
                break;
            }
        }
        if (pos1 == -1) {
            System.out.println("Hmm...");
            return;
        }

        int pos2 = -1;
        for (int i = 0; i < N; i++) {
            if (Q.charAt(i) != R.charAt(i)) {
                pos2 = i;
                break;
            }
        }

        if (pos2 == -1) {
            System.out.println("Hmm...");
            return;
        }

        char cP = P.charAt(pos1);
        char cQ = Q.charAt(pos1);
        char cQ2 = Q.charAt(pos2);
        char cR = R.charAt(pos2);

        boolean found = false;

        outer: for (int h = 1; h <= 9; h++) {
            for (int j = 1; j <= 9; j++) {
                if (j == h)
                    continue;
                for (int s = 1; s <= 9; s++) {
                    if (s == h || s == j)
                        continue;

                    int valP = getMappedValue(cP, h, j, s);
                    int valQ = getMappedValue(cQ, h, j, s);
                    int valQ2 = getMappedValue(cQ2, h, j, s);
                    int valR = getMappedValue(cR, h, j, s);

                    if (valP < valQ && valQ2 < valR) {
                        found = true;
                        break outer;
                    }
                }
            }
        }

        System.out.println(found ? "HJS! HJS! HJS!" : "Hmm...");
    }

    private static int getMappedValue(char ch, int h, int j, int s) {
        if (ch == 'H')
            return h;
        else if (ch == 'J')
            return j;
        else
            return s;
    }
}