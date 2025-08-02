import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public final class Main {
    private static long digitSum(long value) {
        long sum = 0L;
        while (value > 0) {
            sum += value % 10;
            value /= 10;
        }
        return sum;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        long inputNumber = Long.parseLong(reader.readLine().trim());
        long partB;
        if (inputNumber <= 9) {
            partB = inputNumber / 2;
        } else {
            long powerOfTen = 1L;
            while (powerOfTen <= inputNumber) {
                powerOfTen *= 10L;
            }
            powerOfTen /= 10L;
            partB = powerOfTen - 1L;
        }

        long partC = inputNumber - partB;
        long maximumSum = digitSum(partB) + digitSum(partC);

        PrintWriter writer = new PrintWriter(System.out);
        writer.println(maximumSum);
        writer.println(partB + " " + partC);
        writer.flush();
    }
}