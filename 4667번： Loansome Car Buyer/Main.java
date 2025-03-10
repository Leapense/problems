import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int duration = sc.nextInt();
            if (duration < 0)
                break;
            double downPayment = sc.nextDouble();
            double loanAmount = sc.nextDouble();
            int nRecords = sc.nextInt();

            double[] depreciation = new double[duration + 1];
            for (int i = 0; i <= duration; i++) {
                depreciation[i] = -1;
            }

            double currentRate = 0;
            for (int i = 0; i < nRecords; i++) {
                int month = sc.nextInt();
                double rate = sc.nextDouble();
                depreciation[month] = rate;
            }

            for (int i = 0; i <= duration; i++) {
                if (depreciation[i] < 0) {
                    depreciation[i] = currentRate;
                } else {
                    currentRate = depreciation[i];
                }
            }

            double carValue = (loanAmount + downPayment) * (1 - depreciation[0]);
            double owed = loanAmount;
            int month = 0;
            double monthlyPayment = (duration > 0) ? (loanAmount / (double) duration) : 0;

            while (owed >= carValue) {
                month++;
                owed -= monthlyPayment;
                carValue = carValue * (1 - depreciation[month]);
            }

            System.out.println(month + (month == 1 ? " month" : " months"));
        }

        sc.close();
    }
}