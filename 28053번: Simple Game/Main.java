import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Long.parseLong(st.nextToken());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());

        if (gcd(a, b) != 1) {
            System.out.println("No");
            return;
        }

        StringBuilder sb = new StringBuilder();
        sb.append("Yes\n");
        for (long i = 0; i < n; i++) {
            long x = a + (2 * i) * b;
            long y = a + (2 * i + 1) * b;
            sb.append(x).append(' ').append(y).append('\n');
        }

        System.out.print(sb);
    }

    private static long gcd(long x, long y) {
        while (y != 0) {
            long t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
}