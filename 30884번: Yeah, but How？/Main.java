import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        System.out.println(solve(S));
    }

    static String solve(String S) {
        StringBuilder sb = new StringBuilder();
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(0);

        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            if (c == '(') {
                if (stack.peek() > 0) {
                    sb.append('+');
                }

                sb.append('(');
                stack.push(0);
            } else if (c == ')') {
                if (stack.peek() == 0) {
                    sb.append("1");
                }

                sb.append(')');
                stack.pop();

                if (!stack.isEmpty()) {
                    int cnt = stack.pop();
                    stack.push(cnt + 1);
                }
            }
        }

        return sb.toString();
    }
}