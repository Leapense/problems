import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public final class Main {
    private static final char M = 'M';
    private static final char K = 'K';

    private Main() { }

    public static void main(String[] args) throws IOException {
        final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        final String raw = reader.readLine();
        final String maxValue = buildMax(raw);
        final String minValue = buildMin(raw);

        final StringBuilder out = new StringBuilder()
            .append(maxValue).append(System.lineSeparator())
            .append(minValue);

        System.out.print(out);
    }

    private static String buildMax(final String input) {
        final StringBuilder result = new StringBuilder();
        int mCount = 0;

        for (final char ch : input.toCharArray()) {
            if (ch == M) {
                mCount++;
            } else {
                if (mCount > 0) {
                    result.append('5');
                    appendZeros(result, mCount);
                } else {
                    result.append('5');
                }
                mCount = 0;
            }
        }

        if (mCount > 0) {
            appendOnes(result, mCount);
        }
        return result.toString();
    }

    private static String buildMin(final String input) {
        final StringBuilder result = new StringBuilder();
        int mCount = 0;
        for (final char ch : input.toCharArray()) {
            if (ch == M) {
                mCount++;
            } else {
                if (mCount > 0) {
                    result.append('1');
                    appendZeros(result, mCount - 1);
                }
                result.append('5');
                mCount = 0;
            }
        }
        if (mCount > 0) {
            result.append('1');
            appendZeros(result, mCount - 1);
        }

        return result.toString();
    }

    private static void appendZeros(final StringBuilder sb, final int count) {
        for (int i = 0; i < count; i++) {
            sb.append('0');
        }
    }

    private static void appendOnes(final StringBuilder sb, final int count) {
        for (int i = 0; i < count; i++) {
            sb.append('1');
        }
    }
}