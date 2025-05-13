import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine().trim());
        
        double marks = 100.0;
        double dollars = 0.0;

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            double B = Double.parseDouble(st.nextToken());
            double S = Double.parseDouble(st.nextToken());

            double newDollars = Math.max(dollars, marks / 100.0 * B);
            double newMarks = Math.max(marks, dollars / S * 100.0);

            dollars = newDollars;
            marks = newMarks;
        }

        System.out.printf(Locale.US, "%.2f%n", marks);
    }
}