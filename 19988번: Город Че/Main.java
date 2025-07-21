import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public final class Main
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long r = Long.parseLong(st.nextToken());

        long[] d = new long[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            d[i] = Long.parseLong(st.nextToken());
        }

        long visiblePairs = 0L;
        int right = 0;
        for (int left = 0; left < n; left++) {
            while (right < n && d[right] - d[left] <= r) {
                right++;
            }
            visiblePairs += right - left - 1;
        }

        long totalPairs = (long) n * (n - 1) / 2;
        long answer = totalPairs - visiblePairs;
        System.out.println(answer);
    }
}