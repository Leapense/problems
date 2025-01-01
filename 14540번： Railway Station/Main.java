import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        boolean firstBlock = true;

        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.equals("")) continue;
            int N;

            try {
                N = Integer.parseInt(line);
            } catch (NumberFormatException e) {
                continue;
            }
            if (N == 0) {
                break;
            }

            StringBuilder output = new StringBuilder();
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.equals("0")) {
                    break;
                }

                if (line.equals("")) {
                    continue;
                }

                int[] desired = new int[N];
                StringTokenizer st = new StringTokenizer(line);
                int count = 0;

                while (st.hasMoreTokens() && count < N) {
                    desired[count++] = Integer.parseInt(st.nextToken());
                }

                if (count < N) {
                    while (count < N && (line = br.readLine()) != null) {
                        line = line.trim();
                        if (line.equals("")) continue;
                        st = new StringTokenizer(line);
                        while (st.hasMoreTokens() && count < N) {
                            desired[count++] = Integer.parseInt(st.nextToken());
                        }

                        if (count >= N) break;
                    }
                }

                boolean possible = isPossible(N, desired);
                if (possible) {
                    output.append("Yes\n");
                } else {
                    output.append("No\n");
                }
            }

            System.out.print(output.toString());
            System.out.println();
        }
    }

    private static boolean isPossible(int N, int[] desired) {
        Stack<Integer> stack = new Stack<>();
        int current = 1;

        for (int i = 0; i < N; i++) {
            int desiredCoach = desired[i];

            while (current <= desiredCoach) {
                stack.push(current++);
            }

            if (!stack.isEmpty() && stack.peek() == desiredCoach) {
                stack.pop();
            } else {
                return false;
            }
        }

        return true;
    }
}