import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static boolean isArithmetic(int[] digits) {
        if (digits.length < 2) return true;
        int diff = digits[1] - digits[0];
        for (int i = 2; i < digits.length; i++) {
            if (digits[i] - digits[i - 1] != diff) return false;
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long D = Long.parseLong(br.readLine().trim());
        int[] isFavorite = new int[720];
        int countInCycle = 0;

        for (int i = 0; i < 720; i++) {
            int H = (12 + i / 60) % 12;
            if (H == 0) H = 12;
            int M = i % 60;
            int[] digits;

            if (H >= 10) {
                digits = new int[] {H / 10, H % 10, M / 10, M % 10};
            } else {
                digits = new int[] {H, M / 10, M % 10};
            }

            if (isArithmetic(digits)) {
                isFavorite[i] = 1;
                countInCycle++;
            }
        }

        long cycles = D / 720;
        long remainder = D % 720;
        long total = cycles * countInCycle;
        for (int i = 0; i <= remainder; i++) {
            total += isFavorite[i];
        }

        System.out.println(total);
        br.close();
    }
}