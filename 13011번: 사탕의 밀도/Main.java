import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.StringTokenizer;

public final class Main {

    private static final class Pair {
        final double ratio;   // W_i / C_i
        final double weight;  // C_i
        Pair(double ratio, double weight) {
            this.ratio = ratio;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine().trim());

        double[] c = new double[n];
        double[] w = new double[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) { c[i] = Double.parseDouble(st.nextToken()); }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) { w[i] = Double.parseDouble(st.nextToken()); }

        // Build (ratio, weight) pairs
        Pair[] arr = new Pair[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(w[i] / c[i], c[i]);
        }

        // Sort by ratio
        Arrays.sort(arr, (a, b) -> Double.compare(a.ratio, b.ratio));

        // Weighted median
        double total = 0.0;
        for (Pair p : arr) { total += p.weight; }
        double half = total / 2.0;

        double acc = 0.0;
        double dStar = arr[0].ratio;
        for (Pair p : arr) {
            acc += p.weight;
            if (acc >= half) {
                dStar = p.ratio;
                break;
            }
        }

        // Minimal total difference
        double diffSum = 0.0;
        for (Pair p : arr) {
            diffSum += p.weight * Math.abs(dStar - p.ratio);
        }

        // Flexible output: at least ".0", up to 9 decimals, no trailing zeros
        DecimalFormat df = new DecimalFormat("0.#########");
        df.setMinimumFractionDigits(1);
        System.out.println(df.format(diffSum));
    }
}