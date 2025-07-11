import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        int[] hole = new int[n];
        for (int i = 1; i <= n - 2; i++) {
            String line = reader.readLine();
            for (int j = 0; j < 4; j++) {
                if (line.charAt(j) == '0') {
                    hole[i] = j;
                    break;
                }
            }
        }

        int[] prev = new int[4];
        for (int c = 0; c < 4; c++) {
            int walk = Math.abs(c - 0);
            int rotate = Math.min(mod(hole[1] - c), mod(c - hole[1]));
            prev[c] = walk + rotate + 1;
        }

        for (int i = 1; i <= n - 3; i++) {
            int[] curr = new int[4];
            for (int c = 0; c < 4; c++) {
                int base = prev[c];
                int rotate = Math.min(mod(hole[i + 1] - c), mod(c - hole[i + 1]));
                curr[c] = base + rotate + 1;
            }
            prev = curr;
        }

        int answer = Integer.MAX_VALUE;
        for (int c = 0; c < 4; c++) {
            int total = prev[c] + 1 + Math.abs(c - 3);
            if (total < answer) {
                answer = total;
            }
        }

        System.out.println(answer);
    }

    private static int mod(int x) {
        int m = x % 4;
        return m < 0 ? m + 4 : m;
    }
}