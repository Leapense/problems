import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        long startMileage = scanner.nextLong();
        long endMileage = scanner.nextLong();
        scanner.close();

        String startString = Long.toString(startMileage);
        String endString = Long.toString(endMileage);
        int minLength = startString.length();
        int maxLength = endString.length();

        long interestingCount = 0;

        for (int digitLength = minLength; digitLength <= maxLength; digitLength++) {
            char[] digits = new char[digitLength];
            
            for (int a = 0; a <= 9; a++) {
                for (int b = 0; b <= 9; b++) {
                    if (b == a) {
                        continue;
                    }

                    for (int pos = 0; pos < digitLength; pos++) {
                        if (a == 0 && pos != 0) {
                            continue;
                        }

                        char digitCharA = (char)('0' + a);
                        for (int i = 0; i < digitLength; i++) {
                            digits[i] = digitCharA;
                        }

                        digits[pos] = (char)('0' + b);

                        if (digits[0] == '0') {
                            continue;
                        }

                        String candidateString = new String(digits);
                        long candidateValue;
                        try {
                            candidateValue = Long.parseLong(candidateString);
                        } catch(NumberFormatException e) {
                            continue;
                        }

                        if (candidateValue < startMileage || candidateValue > endMileage) {
                            continue;
                        }

                        interestingCount++;
                    }
                }
            }
        }

        System.out.println(interestingCount);
    }
}