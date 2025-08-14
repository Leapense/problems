import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static final int MAX_FEASIBLE_LARGE_COUNT = 31;

    private static final class FastScanner {
        private final InputStream in;
        private final byte[] buffer;
        private int ptr;
        private int len;

        FastScanner(InputStream in) {
            this.in = in;
            this.buffer = new byte[1 << 16];
            this.ptr = 0;
            this.len = 0;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) {
                    return -1;
                }
            }
            return buffer[ptr++];
        }

        long nextLong() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= 32 && c != -1);
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            long val = 0L;
            while (c > 32) {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
        }
    }

    private static int signOf(long v) {
        return v >= 0 ? 1 : -1;
    }

    private static boolean isCandidateValid(List<Long> largeValues, int candidateIndex, int negOneCount, int signLargeTotal) {
        long candidate = largeValues.get(candidateIndex);
        long targetAbs = Math.abs(candidate);
        long productAbs = 1L;
        for (int i = 0; i < largeValues.size(); i++) {
            if (i == candidateIndex) {
                continue;
            }
            long vAbs = Math.abs(largeValues.get(i));
            if (vAbs > targetAbs) {
                return false;
            }
            if (productAbs > targetAbs / vAbs) {
                return false;
            }
            productAbs *= vAbs;
        }
        if (productAbs != targetAbs) {
            return false;
        }
        int onesSign = (negOneCount & 1) == 0 ? 1 : -1;
        int signLargeExcludingCandidate = signLargeTotal * signOf(candidate);
        int othersSign = onesSign * signLargeExcludingCandidate;
        return othersSign == signOf(candidate);
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int n = (int) fs.nextLong();
        long[] values = new long[n];
        int zeroCount = 0;
        int negOneCount = 0;
        int posOneCount = 0;
        List<Long> largeValues = new ArrayList<>();
        int signLargeTotal = 1;

        for (int i = 0; i < n; i++) {
            long v = fs.nextLong();
            values[i] = v;
            if (v == 0L) {
                zeroCount++;
            } else if (v == 1L) {
                posOneCount++;
            } else if (v == -1L) {
                negOneCount++;
            } else {
                largeValues.add(v);
                signLargeTotal *= signOf(v);
            }
        }

        if (zeroCount >= 2) {
            System.out.println("Yes");
            System.out.println(0);
            return;
        }
        if (zeroCount == 1) {
            System.out.println("No");
            return;
        }

        if (largeValues.isEmpty()) {
            if ((negOneCount & 1) == 0) {
                System.out.println("Yes");
                System.out.println(values[0]);
            } else {
                System.out.println("No");
            }
            return;
        }

        if (largeValues.size() >= MAX_FEASIBLE_LARGE_COUNT) {
            System.out.println("No");
            return;
        }

        for (int i = 0; i < largeValues.size(); i++) {
            if (isCandidateValid(largeValues, i, negOneCount, signLargeTotal)) {
                System.out.println("Yes");
                System.out.println(largeValues.get(i));
                return;
            }
        }

        System.out.println("No");
    }
}