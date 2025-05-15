import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder output = new StringBuilder();
        String line;

        DecimalFormat df = new DecimalFormat("0.00");
        df.setDecimalSeparatorAlwaysShown(true);

        while ((line = reader.readLine()) != null && !line.isBlank())
        {
            StringTokenizer st = new StringTokenizer(line);
            double a = Double.parseDouble(st.nextToken());
            double b = Double.parseDouble(st.nextToken());
            double c = Double.parseDouble(st.nextToken());
            double d = Double.parseDouble(st.nextToken());
            double m = Double.parseDouble(st.nextToken());
            double t = Double.parseDouble(st.nextToken());

            double lo = 0.0, hi = 1e3;
            for (int iter = 0; iter < 100; iter++)
            {
                double mid = (lo + hi) / 2.0;
                double fuelPerHour = ((a * mid + b) * mid + c) * mid * mid + d * mid;
                double g = m * fuelPerHour - t * mid;

                if (g <= 0) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            double bestV = Math.floor(lo * 100) / 100.0;

            output.append(String.format(Locale.ROOT, "%.2f%n", bestV));
        }

        System.out.print(output.toString());
    }
}