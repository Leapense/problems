import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    private static final BufferedReader BR = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception {
        int n = Integer.parseInt(BR.readLine().trim());
        long[] cows = new long[n];
        long[] stalls = new long[n];
        readLineToArray(cows);
        readLineToArray(stalls);
        Arrays.sort(cows);
        Arrays.sort(stalls);

        long ways = 1;
        int assigned = 0;
        for (int i = n - 1; i >= 0; i--) {
            int eligible = countGreaterOrEqual(stalls, cows[i]);
            int choices = eligible - assigned;
            if (choices <= 0) {
                ways = 0;
                break;
            }
            ways *= choices;
            assigned++;
        }
        System.out.println(ways);
    }

    private static void readLineToArray(long[] arr) throws Exception {
        StringTokenizer st = new StringTokenizer(BR.readLine());
        for (int i = 0; i < arr.length; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
    }

    private static int countGreaterOrEqual(long[] arr, long value) {
        int left = 0;
        int right = arr.length;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (arr[mid] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return arr.length - left;
    }
}