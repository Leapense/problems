import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public final class Main {
    private static final long MAX_SQUARE = 100_000_000_000_000L;
    private static final List<Long> fairAndSquareList = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        precomputeFairAndSquare();
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(reader.readLine().trim());
        for (int tc = 1; tc <= T; tc++) {
            String[] parts = reader.readLine().split(" ");
            long A = Long.parseLong(parts[0]);
            long B = Long.parseLong(parts[1]);
            int count = countInRange(A, B);
            System.out.printf("Case #%d: %d%n", tc, count);
        }
    }

    private static void precomputeFairAndSquare() {
        for (int d = 1; d <= 9; d++) {
            testAndAdd(d);
        }

        for (int halfLen = 1; halfLen <= 4; halfLen++) {
            generatePalindromes(halfLen, true);
            if (halfLen > 1) {
                generatePalindromes(halfLen, false);
            }
        }

        Collections.sort(fairAndSquareList);
    }

    private static void generatePalindromes(int halfLen, boolean even) {
        int start = (int) Math.pow(10, halfLen - 1);
        int end = (int) Math.pow(10, halfLen) - 1;

        for (int prefix = start; prefix <= end; prefix++) {
            String left = Integer.toString(prefix);
            StringBuilder right = new StringBuilder(left);

            if (!even) {
                right.deleteCharAt(right.length() - 1);
            }

            String palStr = left + right.reverse().toString();
            long r = Long.parseLong(palStr);
            testAndAdd(r);
        }
    }

    private static void testAndAdd(long r) {
        long sq = r * r;
        if (sq > MAX_SQUARE) {
            return;
        }
        if (isPalindrome(Long.toString(sq))) {
            fairAndSquareList.add(sq);
        }
    }

    private static boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }

        return true;
    }

    private static int countInRange(long A, long B) {
        int low = lowerBound(fairAndSquareList, A);
        int high = upperBound(fairAndSquareList, B);
        return Math.max(0, high - low);
    }

    private static int lowerBound(List<Long> list, long key) {
        int left = 0, right = list.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (list.get(mid) < key) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    private static int upperBound(List<Long> list, long key) {
        int left = 0, right = list.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (list.get(mid) <= key) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}