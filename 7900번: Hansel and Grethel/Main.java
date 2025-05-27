import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int testCount = Integer.parseInt(reader.readLine().trim());
        StringBuilder outputBuilder = new StringBuilder();

        for (int i = 0; i < testCount; i++) {
            Marker m1 = readMarker(reader);
            Marker m2 = readMarker(reader);

            double sin1 = Math.sin(m1.radian);
            double cos1 = Math.cos(m1.radian);
            double sin2 = Math.sin(m2.radian);
            double cos2 = Math.cos(m2.radian);

            double a = sin1;
            double b = -sin2;
            double c = m2.x - m1.x;
            double d = cos1;
            double e = -cos2;
            double f = m2.y - m1.y;

            double denom = a * e - b * d;
            double t1 = (c * e - b * f) / denom;
            double x = m1.x + t1 * sin1;
            double y = m1.y + t1 * cos1;

            outputBuilder.append(String.format("%.4f %.4f%n", x, y));
        }
        System.out.print(outputBuilder.toString());
    }

    private static Marker readMarker(BufferedReader reader) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        double x = Double.parseDouble(tokenizer.nextToken());
        double y = Double.parseDouble(tokenizer.nextToken());
        double degree = Double.parseDouble(tokenizer.nextToken());
        return new Marker(x, y, Math.toRadians(degree));
    }

    private static final class Marker {
        final double x;
        final double y;
        final double radian;
        Marker(double x, double y, double radian) {
            this.x = x;
            this.y = y;
            this.radian = radian;
        }
    }
}