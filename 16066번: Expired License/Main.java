import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    private static final int SCALE = 100_000;
    private static final int LIMIT = 100 * SCALE;
    private static boolean[] composite;

    public static void main(String[] args) throws IOException {
        sieve();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        for (int t = 0; t < n; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int A = scaled(st.nextToken());
            int B = scaled(st.nextToken());
            int g = gcd(A, B);
            A /= g;
            B /= g;
            if (A == 1 && B == 1) {
                bw.write("2 2\n");
            } else if (isPrime(A) && isPrime(B)) {
                bw.write(A + " " + B + '\n');
            } else {
                bw.write("impossible\n");
            }
        }
        bw.flush();
    }

    private static void sieve() {
        composite = new boolean[LIMIT + 1];
        for (int i = 2; (long) i * i <= LIMIT; i++) {
            if (!composite[i]) {
                for (int j = i * i; j <= LIMIT; j += i) {
                    composite[j] = true;
                }
            }
        }
    }

    private static boolean isPrime(int x) {
        return x > 1 && !composite[x];
    }

    private static int scaled(String s) {
        int dot = s.indexOf('.');
        String i = dot < 0 ? s : s.substring(0, dot);
        String f = dot < 0 ? "" : s.substring(dot + 1);
        if (i.isEmpty()) {
            i = "0";
        }
        while (f.length() < 5) {
            f += '0';
        }
        if (f.length() > 5) {
            f = f.substring(0, 5);
        }
        return Integer.parseInt(i) * SCALE + (f.isEmpty() ? 0 : Integer.parseInt(f));
    }

    private static int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
}