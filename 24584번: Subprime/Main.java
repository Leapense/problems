import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static final int MAX_PRIME_INDEX = 100000;
    private static final int SIEVE_LIMIT = 1300000;
    private static List<Integer> primes;

    private static void generatePrimes() {
        primes = new ArrayList<>(MAX_PRIME_INDEX);
        boolean[] isPrime = new boolean[SIEVE_LIMIT + 1];
        for (int i = 2; i <= SIEVE_LIMIT; i++) {
            isPrime[i] = true;
        }
        for (int p = 2; p * p <= SIEVE_LIMIT; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= SIEVE_LIMIT; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        for (int p = 2; p <= SIEVE_LIMIT && primes.size() < MAX_PRIME_INDEX; p++) {
            if (isPrime[p]) {
                primes.add(p);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        generatePrimes();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int l = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        String p = br.readLine();

        int count = 0;
        for (int i = l - 1; i < h; i++) {
            if (i >= primes.size()) {
                break;
            }

            String primeStr = String.valueOf(primes.get(i));
            if (primeStr.contains(p)) {
                count++;
            }
        }
        System.out.println(count);
    }
}