import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main
{
    public void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] deadlines = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            deadlines[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(deadlines);

        long left = 1;
        long right = deadlines[n - 1];
        long maxK = 0;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (isPossible(mid, n, deadlines)) {
                maxK = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        System.out.println(maxK);
    }

    private boolean isPossible(long k, long n, int[] deadlines) {
        if (k == 0) return true;

        for (int i = 0; i < n; i++) {
            long finishTime = (long)(i + 1) * k;
            if (finishTime > deadlines[i]) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        try {
            new Main().solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
