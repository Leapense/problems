import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private final long MOD = 1_000_000_007L;
    private long power(long base, long exp) {
        long result = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;
            exp /= 2;
        }

        return result;
    }

    /**
     * 메인 로직을 포함하는 solve 메서드이다.
     * 입력을 읽고, 각 항을 처리하여 f'(2)의 값을 계산한 후 출력한다.
     * 
     * @throws IOException 입출력 작업 중 오류 발생 시
     */
    public void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        long totalDerivativeAtTwo = 0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            long C = Long.parseLong(st.nextToken());
            long K = Long.parseLong(st.nextToken());

            if (K == 0) {
                continue;
            }

            long derivativeCoefficient = (C * K) % MOD;

            long powerOfTwo = power(2, K - 1);
            long termContribution = (derivativeCoefficient * powerOfTwo) % MOD;

            totalDerivativeAtTwo = (totalDerivativeAtTwo + termContribution) % MOD;
        }

        System.out.println(totalDerivativeAtTwo);

        br.close();
    }

    /**
     * 프로그램의 진입접(Entry Point)이다.
     * Main 클래스의 solve 메서드를 호출하여 프로그램을 실행한다.
     * 
     * @param args 커맨드 라인 인자 (사용되지는 않지만, 넣어야 한다.)
     * @throws IOException 입출력 작업 중 오류 발생 시
     */
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}