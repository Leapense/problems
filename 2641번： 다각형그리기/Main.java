import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static boolean isSamePolygon(int[] sample, int[] candidate) {
        int len = sample.length;
        for (int start = 0; start < len; start++) {
            boolean match = true;
            for (int j = 0; j < len; j++) {
                if (candidate[j] != sample[(start + j) % len]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    }
}