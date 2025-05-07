import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        double R = Double.parseDouble(st.nextToken());
        double answer = 0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            double[] x = new double[4];
            double[] y = new double[4];

            for (int j = 0; j < 4; j++) {
                x[j] = Double.parseDouble(st.nextToken());
                y[j] = Double.parseDouble(st.nextToken());
            }

            double cx = (x[0] + x[1] + x[2] + x[3]) / 4.0;
            double cy = (y[0] + y[1] + y[2] + y[3]) / 4.0;
            double maxD2 = 0;

            for (int j = 0; j < 4; j++) {
                double dx = x[j] - cx;
                double dy = y[j] - cy;
                maxD2 = Math.max(maxD2, dx * dx + dy * dy);
            }

            double q = Math.sqrt(maxD2);
            double d2 = cx * cx + cy * cy;
            double limit = R + q;
            if (d2 <= limit * limit)
                answer++;
        }

        System.out.println((long) answer);
    }
}