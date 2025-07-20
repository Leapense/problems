import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int n = s.length();
        int[] lengths = new int[n];
        char[] colors = new char[n];
        int m = 0;
        for (int i = 0; i < n; ) {
            char c = s.charAt(i);
            int j = i;
            while (j < n && s.charAt(j) == c) {
                j++;
            }

            colors[m] = c;
            lengths[m] = j - i;
            m++;
            i = j;
        }

        if (m % 2 == 0) {
            System.out.println(0);
            return;
        }

        int mid = m / 2;
        int centerLength = lengths[mid];
        if (centerLength < 2) {
            System.out.println(0);
            return;
        }

        for (int k = 1; k <= mid; k++) {
            if (colors[mid - k] != colors[mid + k] || lengths[mid - k] + lengths[mid + k] < 3) {
                System.out.println(0);
                return;
            }
        }

        System.out.println(centerLength + 1);
    }
}