import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] boards = new int[n];
        st = new StringTokenizer(br.readLine());
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            boards[i] = Integer.parseInt(st.nextToken());
            if (boards[i] > maxLen) {
                maxLen = boards[i];
            }
        }

        long low = 1, high = maxLen;

        while (low < high) {
            long mid = (low + high + 1) >>> 1;
            if (canMakeFour(boards, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        long result = (low > 0 && canMakeFour(boards, low)) ? low * low : 0;
        System.out.println(result);
    }

    private static boolean canMakeFour(int[] boards, long L) {
        int count = 0;
        for (int len : boards) {
            count += len / L;
            if (count >= 4) {
                return true;
            }
        }

        return false;
    }
}
