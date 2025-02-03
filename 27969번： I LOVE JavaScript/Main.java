import java.io.*;
import java.util.*;

public class Main {
    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input, " ");
        Stack<Long> stack = new Stack<>();

        long result = 0;
        while (st.hasMoreTokens()) {
            String token = st.nextToken();
            if (token.equals("[")) {
                stack.push(0L);
            } else if (token.equals("]")) {
                long cur = stack.pop()
            }
        }
    }
}