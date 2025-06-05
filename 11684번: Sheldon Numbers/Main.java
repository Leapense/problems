import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main 
{
    // 최대 비트 길이: 63비트 (양의 long 범위)
    private static final int MAX_BITS = 63;
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] tokens = reader.readLine().trim().split("\\s+");
        
        long X = Long.parseUnsignedLong(tokens[0]);
        long Y = Long.parseUnsignedLong(tokens[1]);

        long count = 0L;

        for (int n = 1; n <= MAX_BITS; n++) {
            long value = (1L << n) - 1L;

            if (value >= X && value <= Y) {
                count++;
            }
        }

        for (int n = 1; n <= MAX_BITS; n++) {
            long onesMaskForA = (1L << n) - 1L;

            for (int m = 1; m <= MAX_BITS; m++) {
                if (n + m > MAX_BITS) {
                    continue;
                }

                int maxKForEven = MAX_BITS / (n + m);

                for (int k = 1; k <= maxKForEven; k++) {
                    int totalBits = k * (n + m);
                    if (totalBits > MAX_BITS) {
                        break;
                    }

                    long result = 0L;
                    for (int blockIndex = 1; blockIndex <= 2 * k; blockIndex++) {
                        if ((blockIndex & 1) == 1) {
                            result = (result << n) | onesMaskForA;
                        } else {
                            result = result << m;
                        }
                    }

                    if (result >= X && result <= Y) {
                        count++;
                    }
                }
            }
        }

        for (int n = 1; n <= MAX_BITS; n++) {
            long onesMaskForA = (1L << n) - 1L;

            for (int m = 1; m <= MAX_BITS; m++) {
                int maxKForOdd = (MAX_BITS + m) / (n + m);

                for (int k = 2; k <= maxKForOdd; k++) {
                    int totalBits = k * n + (k - 1) * m;
                    if (totalBits > MAX_BITS) {
                        break;
                    }

                    long result = 0L;
                    int totalBlocks = 2 * k - 1;

                    for (int blockIndex = 1; blockIndex <= totalBlocks; blockIndex++) {
                        if ((blockIndex & 1) == 1) {
                            result = (result << n) | onesMaskForA;
                        } else {
                            result = result << m;
                        }
                    }

                    if (result >= X && result <= Y) {
                        count++;
                    }
                }
            }
        }

        System.out.println(count);
    }
}
