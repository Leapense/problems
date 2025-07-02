import java.io.*;

public final class Main {
    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            String t = br.readLine();

            if (solve(n, t)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
    private static boolean solve(int n, String t) {
        if (t.charAt(n - 1) == 'A') {
            return false;
        }

        int balance = 0;
        for (int i = 0; i < n; ++i) {
            char currentChar = t.charAt(i);
            if (currentChar == 'A') {
                balance++;
            } else {
                balance--;
            }

            if (balance < 0) {
                return false;
            }
        }

        return true;
    }
}