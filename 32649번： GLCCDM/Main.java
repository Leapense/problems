import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        if (B % A != 0) {
            System.out.println(-1);
            return;
        }

        int x = B / A;

        ArrayList<Integer> divisors = new ArrayList<>();
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                divisors.add(i);
                if (i != x / i) {
                    divisors.add(x / i);
                }
            }
        }

        Collections.sort(divisors);

        if (divisors.size() < K) {
            System.out.println(-1);
            return;
        }

        ArrayList<Integer> chosen = new ArrayList<>();
        chosen.add(1);
        chosen.add(x);
        for (int d : divisors) {
            if (chosen.size() >= K)
                break;
            if (d == 1 || d == x)
                continue;
            chosen.add(d);
        }

        for (int num : chosen) {
            System.out.print(A * num + " ");
        }
    }
}