import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        String s = br.readLine().trim();

        class Context {
            BigInteger prod = BigInteger.ONE;
            int count = 0;
        }

        Deque<Context> stack = new ArrayDeque<>();
        stack.push(new Context());

        for (char c : s.toCharArray()) {
            if (c == '(') {
                stack.push(new Context());
            } else {
                Context ctx = stack.pop();
                BigInteger val;
                if (ctx.count == 0) {
                    val = BigInteger.ONE;
                } else {
                    val = ctx.prod.add(BigInteger.ONE);
                }

                Context parent = stack.peek();
                parent.prod = parent.prod.multiply(val);
                parent.count++;
            }
        }

        System.out.println(stack.peek().prod);
    }
}