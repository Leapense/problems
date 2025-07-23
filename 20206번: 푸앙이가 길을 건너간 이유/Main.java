import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public final class Main {
    private Main() {
        throw new IllegalStateException();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        long c = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());
        long x1 = Long.parseLong(st.nextToken());
        long x2 = Long.parseLong(st.nextToken());
        long y1 = Long.parseLong(st.nextToken());
        long y2 = Long.parseLong(st.nextToken());

        long[] values = {
            a * x1 + b * y1 + c,
            a * x1 + b * y2 + c,
            a * x2 + b * y1 + c,
            a * x2 + b * y2 + c
        };

        long minVal = values[0];
        long maxVal = values[0];

        for (int i = 1; i < values.length; i++) {
            long v = values[i];
            if (v < minVal) {
                minVal = v;
            } else if (v > maxVal) {
                maxVal = v;
            }
        }

        if (minVal < 0 && maxVal > 0) {
            System.out.println("Poor");
        } else {
            System.out.println("Lucky");
        }
    }
}