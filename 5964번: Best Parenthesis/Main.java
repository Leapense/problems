import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    static final long MOD = 12345678910L;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Stack<Long> stack = new Stack<>();
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(br.readLine());
            if (num == 0) {
                stack.push(-1L);
            } else {
                if (stack.peek() == -1L) {
                    stack.pop();
                    stack.push(1L);
                } else {
                    long sum = 0;
                    while (!stack.isEmpty() && stack.peek() != -1L) {
                        sum = (sum + stack.pop()) % MOD;
                    }
                    stack.pop();
                    stack.push((2 * sum) % MOD);
                }
            }
        }

        long answer = 0;
        while (!stack.isEmpty()) {
            answer = (answer + stack.pop()) % MOD;
        }

        System.out.println(answer);
    }
}