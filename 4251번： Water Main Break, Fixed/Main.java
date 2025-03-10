import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

public class Main {
    static class Break {
        double x, y, t, r;

        Break(double x, double y, double t, double r) {
            this.x = x;
            this.y = y;
            this.t = t;
            this.r = r;
        }
    }

    static int n;
    static double v, best;
    static Break[] breaks;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        for (int k = 1; k <= K; k++) {
            n = sc.nextInt();
            v = sc.nextDouble();
            breaks = new Break[n];
            for (int i = 0; i < n; i++) {
                double x = sc.nextDouble(), y = sc.nextDouble(), t = sc.nextDouble(), r = sc.nextDouble();
                breaks[i] = new Break(x, y, t, r);
            }

            best = Double.MAX_VALUE;
            dfs(0, 0, 0, 0, 0, 0);
            DecimalFormat df = new DecimalFormat("0.00");
            System.out.println("Data Set " + k + ":");
            System.out.println(df.format(best));
            System.out.println();
        }
    }

    static void dfs(int mask, double currTime, double currX, double currY, double waterLost, int count) {
        if (mask == (1 << n) - 1) {
            best = Math.min(best, waterLost);
            return;
        }

        if (waterLost >= best)
            return;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                double dist = Math.hypot(breaks[i].x - currX, breaks[i].y - currY);
                double travelTime = dist / v;
                double arrivalTime = currTime + travelTime;
                double repairTime = Math.max(arrivalTime, breaks[i].t);
                double addedLoss = (repairTime - breaks[i].t) * breaks[i].r;
                dfs(mask | (1 << i), repairTime, breaks[i].x, breaks[i].y, waterLost + addedLoss, count + 1);
            }
        }
    }
}