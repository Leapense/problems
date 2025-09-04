import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main
{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        String bs = Long.toString(b);
        long best = digitSum(b);
        for (int i = 0; i < bs.length(); i++) {
            int d = bs.charAt(i) - '0';
            if (d == 0) {
                continue;
            }
            StringBuilder sb = new StringBuilder();
            if (i > 0) {
                sb.append(bs, 0, i);
            }
            sb.append((char) ('0' + d - 1));
            for (int j = i + 1; j < bs.length(); j++) {
                sb.append('9');
            }
            long candidate = Long.parseLong(sb.toString());
            if (candidate >= a) {
                long s = digitSum(candidate);
                if (s > best) {
                    best = s;
                }
            }
        }

        System.out.println(best);
    }

    private static long digitSum(long x) {
        long sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }
}