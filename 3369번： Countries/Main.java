import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int[] x, y, s;

    static int[] parent;
    static int[] type;
    static int[] finalCapital;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine().trim());
        x = new int[n];
        y = new int[n];
        s = new int[n];
        parent = new int[n];
        type = new int[n];

        finalCapital = new int[n];
        Arrays.fill(parent, -1);
        Arrays.fill(finalCapital, -1);

        for (int i = 0; i < n; i++) {
            String[] parts = br.readLine().split(" ");
            x[i] = Integer.parseInt(parts[0]);
            y[i] = Integer.parseInt(parts[1]);
            s[i] = Integer.parseInt(parts[2]);
        }

        for (int i = 0; i < n; i++) {
            long bestNum = -1;
            long bestDen = 1;
            int candidate = -1;
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                int dx = x[i] - x[j];
                int dy = y[i] - y[j];
                int d2 = dx * dx + dy * dy;

                if ((long) s[j] > (long) s[i] * d2) {
                    long cur = (long) s[j];
                    if (candidate == -1) {
                        bestNum = cur;
                        bestDen = d2;
                        candidate = j;
                        count += 1;
                    } else {
                        long lhs = cur * bestDen;
                        long rhs = bestNum * d2;
                        if (lhs > rhs) {
                            bestNum = cur;
                            bestDen = d2;
                            candidate = j;
                            count = 1;
                        } else if (lhs == rhs) {
                            count++;
                        }
                    }
                }
            }

            if (candidate == -1) {
                type[i] = 1;
            } else if (count > 1) {
                type[i] = 2;
            } else {
                parent[i] = candidate;
            }
        }

        for (int i = 0; i < n; i++) {
            int cap = findCapital(i);
            if (parent[i] == -1) {
                if (type[i] == 1) {
                    System.out.println("K");
                } else {
                    System.out.println("D");
                }
            } else {
                System.out.println(cap + 1);
            }
        }
    }

    static int findCapital(int i) {
        if (parent[i] == -1) {
            return i;
        }

        if (finalCapital[i] != -1)
            return finalCapital[i];
        finalCapital[i] = findCapital(parent[i]);
        return finalCapital[i];
    }
}