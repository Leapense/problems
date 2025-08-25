import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public final class Main {
    static final class Point {
        final long x;
        final long y;
        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static final class Segment {
        final long x1;
        final long y1;
        final long x2;
        final long y2;
        Segment(long x1, long y1, long x2, long y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        Point[] pts = new Point[3];
        for (int i = 0; i < 3; i++) {
            long x = sc.nextLong();
            long y = sc.nextLong();
            pts[i] = new Point(x, y);
        }
        sc.close();

        List<Segment> vertical = buildVertical(pts);
        List<Segment> horizontal = buildHorizontal(pts);

        long totV = totalVerticalCost(pts);
        long totH = totalHorizontalCost(pts);

        List<Segment> out;
        if (totV < totH) {
            out = vertical;
        } else if (totH < totV) {
            out = horizontal;
        } else if (vertical.size() < horizontal.size()) {
            out = vertical;
        } else if (horizontal.size() < vertical.size()) {
            out = horizontal;
        } else {
            out = horizontal;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(out.size()).append('\n');
        for (Segment s : out) {
            sb.append(s.x1).append(' ')
              .append(s.y1).append(' ')
              .append(s.x2).append(' ')
              .append(s.y2).append('\n');
        }
        System.out.print(sb.toString());
    }

    private static List<Segment> buildVertical(Point[] pts) {
        long x0 = median(pts[0].x, pts[1].x, pts[2].x);
        long yMin = Math.min(pts[0].y, Math.min(pts[1].y, pts[2].y));
        long yMax = Math.max(pts[0].y, Math.max(pts[1].y, pts[2].y));
        List<Segment> segs = new ArrayList<>();
        if (yMin != yMax) {
            segs.add(new Segment(x0, yMin, x0, yMax));
        }
        for (Point p : pts) {
            if (p.x != x0) {
                long x1 = Math.min(p.x, x0);
                long x2 = Math.max(p.x, x0);
                segs.add(new Segment(x1, p.y, x2, p.y));
            }
        }
        return segs;
    }

    private static List<Segment> buildHorizontal(Point[] pts) {
        long y0 = median(pts[0].y, pts[1].y, pts[2].y);
        long xMin = Math.min(pts[0].x, Math.min(pts[1].x, pts[2].x));
        long xMax = Math.max(pts[0].x, Math.max(pts[1].x, pts[2].x));
        List<Segment> segs = new ArrayList<>();
        if (xMin != xMax) {
            segs.add(new Segment(xMin, y0, xMax, y0));
        }
        for (Point p : pts) {
            if (p.y != y0) {
                long y1 = Math.min(p.y, y0);
                long y2 = Math.max(p.y, y0);
                segs.add(new Segment(p.x, y1, p.x, y2));
            }
        }
        return segs;
    }

    private static long totalVerticalCost(Point[] pts) {
        long x0 = median(pts[0].x, pts[1].x, pts[2].x);
        long yMin = Math.min(pts[0].y, Math.min(pts[1].y, pts[2].y));
        long yMax = Math.max(pts[0].y, Math.max(pts[1].y, pts[2].y));
        long sum = yMax - yMin;
        for (Point p : pts) {
            sum += Math.abs(p.x - x0);
        }
        return sum;
    }

    private static long totalHorizontalCost(Point[] pts) {
        long y0 = median(pts[0].y, pts[1].y, pts[2].y);
        long xMin = Math.min(pts[0].x, Math.min(pts[1].x, pts[2].x));
        long xMax = Math.max(pts[0].x, Math.max(pts[1].x, pts[2].x));
        long sum = xMax - xMin;
        for (Point p : pts) {
            sum += Math.abs(p.y - y0);
        }
        return sum;
    }

    private static long median(long a, long b, long c) {
        long[] arr = new long[] { a, b, c };
        Arrays.sort(arr);
        return arr[1];
    }
}