import java.util.*;
import java.io.*;

public class Main {
    private static final int WEEK = 10080;

    static class Mower {
        String name;
        int price, rate, t, r;

        Mower(String name, int price, int rate, int t, int r) {
            this.name = name;
            this.price = price;
            this.rate = rate;
            this.t = t;
            this.r = r;
        }

        boolean qualifies(int lawn) {
            int cycle = t + r;
            long fullCycles = WEEK / (long) cycle;
            int leftover = WEEK % cycle;
            long cutWeek1 = fullCycles * (long) rate * t + (long) Math.min(leftover, t) * rate;
            if (cutWeek1 < lawn)
                return false;

            long lhs = (long) WEEK * rate * t;
            long rhs = (long) lawn * (t + r);
            return lhs >= rhs;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int lawn = sc.nextInt(), m = sc.nextInt();
        sc.nextLine();

        List<Mower> list = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            String line = sc.nextLine().trim();
            int c1 = line.indexOf(',');
            String name = line.substring(0, c1).trim();
            String[] pcrt = line.substring(c1 + 1).split(",");
            int price = Integer.parseInt(pcrt[0].trim());
            int rate = Integer.parseInt(pcrt[1].trim());
            int t = Integer.parseInt(pcrt[2].trim());
            int r = Integer.parseInt(pcrt[3].trim());
            list.add(new Mower(name, price, rate, t, r));
        }

        int best = Integer.MAX_VALUE;
        List<String> ans = new ArrayList<>();
        for (Mower w : list) {
            if (!w.qualifies(lawn))
                continue;
            if (w.price < best) {
                best = w.price;
                ans.clear();
                ans.add(w.name);
            } else if (w.price == best) {
                ans.add(w.name);
            }
        }

        if (ans.isEmpty()) {
            System.out.println("no such mower");
        } else {
            ans.forEach(System.out::println);
        }
    }
}