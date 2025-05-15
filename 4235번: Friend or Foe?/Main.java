import java.io.*;
import java.util.*;

public class Main {
    static class Point {
        int x, y, z, label; // label: -1 for Alliance, +1 for Empire
        Point(int x, int y, int z, int label) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.label = label;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            String[] parts = line.split("\\s+");
            if (parts.length == 2 && parts[0].equals("-1") && parts[1].equals("-1")) break;
            int allianceCount = Integer.parseInt(parts[0]);
            ArrayList<Point> pts = new ArrayList<>();
            // Read Alliance
            for (int i = 0; i < allianceCount; i++) {
                String[] coord = br.readLine().trim().split("\\s+");
                int x = Integer.parseInt(coord[0]);
                int y = Integer.parseInt(coord[1]);
                int z = Integer.parseInt(coord[2]);
                pts.add(new Point(x, y, z, -1));
            }
            // Read Empire count
            int empireCount = Integer.parseInt(br.readLine().trim());
            // Read Empire
            for (int i = 0; i < empireCount; i++) {
                String[] coord = br.readLine().trim().split("\\s+");
                int x = Integer.parseInt(coord[0]);
                int y = Integer.parseInt(coord[1]);
                int z = Integer.parseInt(coord[2]);
                pts.add(new Point(x, y, z, +1));
            }
            double[] coef = findSeparatingHyperplane(pts);
            System.out.printf("%.6f %.6f %.6f %.6f%n", coef[0], coef[1], coef[2], coef[3]);
        }
    }

    static double[] findSeparatingHyperplane(ArrayList<Point> pts) {
        double a = 0, b = 0, c = 0, d = 0;
        double lr = 1.0;
        int updates = 0, maxUpdates = 100000;
        Random rand = new Random();
        // Start with a random nonzero plane
        a = rand.nextDouble() - 0.5;
        b = rand.nextDouble() - 0.5;
        c = rand.nextDouble() - 0.5;
        d = rand.nextDouble() - 0.5;

        while (updates < maxUpdates) {
            boolean allCorrect = true;
            for (Point p : pts) {
                double val = a * p.x + b * p.y + c * p.z + d;
                if (p.label * val <= 1e-8) {
                    a += lr * p.label * p.x;
                    b += lr * p.label * p.y;
                    c += lr * p.label * p.z;
                    d += lr * p.label * 1;
                    allCorrect = false;
                    updates++;
                }
            }
            if (allCorrect) break;
        }
        return new double[] { a, b, c, d };
    }
}