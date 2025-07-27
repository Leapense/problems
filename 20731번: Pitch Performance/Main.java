import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    private static final double EPS = 1e-12;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        ArrayList<Integer> fEnds = new ArrayList<>();
        ArrayList<Double> fValues = new ArrayList<>();
        int prev = 0;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            double y = Double.parseDouble(st.nextToken());
            fEnds.add(x);
            fValues.add(y);
        }
        int m = Integer.parseInt(br.readLine().trim());
        ArrayList<Integer> gEnds = new ArrayList<>();
        ArrayList<Double> aList = new ArrayList<>();
        ArrayList<Double> bList = new ArrayList<>();
        ArrayList<Double> cList = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            double a = Double.parseDouble(st.nextToken());
            double b = Double.parseDouble(st.nextToken());
            double c = Double.parseDouble(st.nextToken());
            gEnds.add(x);
            aList.add(a);
            bList.add(b);
            cList.add(c);
        }
        double area = 0.0;
        int fIdx = 0;
        int gIdx = 0;
        int left = 0;
        while (fIdx < n && gIdx < m) {
            int right = Math.min(fEnds.get(fIdx), gEnds.get(gIdx));
            double yConst = fValues.get(fIdx);
            double a = aList.get(gIdx);
            double b = bList.get(gIdx);
            double c = cList.get(gIdx);
            area += integrateAbsDiff(left, right, a, b, c - yConst);
            left = right;
            if (right == fEnds.get(fIdx)) {
                fIdx++;
            }
            if (right == gEnds.get(gIdx)) {
                gIdx++;
            }
        }
        System.out.printf("%.13f%n", area);
    }
    private static double integrateAbsDiff(double l, double r, double a, double b, double c) {
        double[] points = new double[4];
        int count = 0;
        points[count++] = l;
        double discriminant;
        if (Math.abs(a) < EPS) { // 선형 또는 상수
            if (Math.abs(b) > EPS) {
                double root = -c / b;
                if (root > l + EPS && root < r - EPS) {
                    points[count++] = root;
                }
            }
        } else {
            discriminant = b * b - 4.0 * a * c;
            if (discriminant > EPS) {
                double sqrt = Math.sqrt(discriminant);
                double root1 = (-b - sqrt) / (2.0 * a);
                double root2 = (-b + sqrt) / (2.0 * a);
                if (root1 > l + EPS && root1 < r - EPS) {
                    points[count++] = root1;
                }
                if (root2 > l + EPS && root2 < r - EPS) {
                    points[count++] = root2;
                }
            }
        }
        points[count++] = r;
        java.util.Arrays.sort(points, 0, count);
        double sum = 0.0;
        for (int i = 0; i < count - 1; i++) {
            double p = points[i];
            double q = points[i + 1];
            if (q - p < EPS) {
                continue;
            }
            double part = polyIntegral(q, a, b, c) - polyIntegral(p, a, b, c);
            sum += Math.abs(part);
        }
        return sum;
    }

    private static double polyIntegral(double x, double a, double b, double c) {
        return a * x * x * x / 3.0 + b * x * x / 2.0 + c * x;
    }
}