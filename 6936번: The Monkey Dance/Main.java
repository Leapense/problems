import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int n = sc.nextInt();
            if (n == 0)
                break;

            int[] next = new int[n + 1];
            for (int i = 0; i < n; i++) {
                int from = sc.nextInt();
                int to = sc.nextInt();
                next[from] = to;
            }

            boolean[] visited = new boolean[n + 1];
            List<Integer> cycleLengths = new ArrayList<>();

            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    int cycleLength = 0;
                    int current = i;

                    do {
                        visited[current] = true;
                        current = next[current];
                        cycleLength++;
                    } while (current != i);

                    cycleLengths.add(cycleLength);
                }
            }

            long result = 1;

            for (int length : cycleLengths) {
                result = lcm(result, length);
            }

            System.out.println(result);
        }

        sc.close();
    }

    private static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    private static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }
}