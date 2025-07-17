import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public final class Main
{
    private Main() { }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        int[] a = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int left = 0;
        while (left + 1 < n && a[left] <= a[left + 1]) {
            left++;
        }
        if (left == n - 1) {
            System.out.println("1 1");
            return;
        }

        while (left > 0 && a[left] == a[left - 1]) {
            left--;
        }

        int r = left + 1;
        while (r < n && a[r - 1] >= a[r]) {
            r++;
        }
        int right = r - 1;

        reverse(a, left, right);

        if (isSorted(a)) {
            System.out.println((left + 1) + " " + (right + 1));
        } else {
            System.out.println("impossible");
        }
    }

    private static void reverse(int[] arr, int l, int r) {
        while (l < r) {
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    }

    private static boolean isSorted(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }

        return true;
    }
}