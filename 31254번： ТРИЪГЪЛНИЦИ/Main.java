import java.util.Scanner;

public class Main {
    static class Point {
        String name;
        int x, y;

        Point(String name, int x, int y) {
            this.name = name;
            this.x = x;
            this.y = y;
        }
    }

    static boolean isCollinear(Point a, Point b, Point c) {
        int area2 = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
        return area2 == 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        Point[] points = new Point[n];

        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            points[i] = new Point(name, x, y);
        }

        boolean triangleFound = false;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (!isCollinear(points[i], points[j], points[k])) {
                        System.out.println(points[i].name + " " + points[j].name + " " + points[k].name);
                        triangleFound = true;
                    }
                }
            }
        }

        if (!triangleFound) {
            System.out.println("No triangles.");
        }

        scanner.close();
    }
}