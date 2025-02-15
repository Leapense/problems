import java.util.Scanner;

public class Main {
    static final String[] DAYS = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int meetDayInput = sc.nextInt();
        int pWdayPercent = sc.nextInt();
        int pWendPercent = sc.nextInt();
        int pImpPercent = sc.nextInt();
        sc.close();

        double pWday = pWdayPercent / 100.0;
        double pWend = pWendPercent / 100.0;
        double pImp = pImpPercent / 100.0;

        int i = 1;
        double cumulativeSuccess = 0.0;
        double cumulativeFailure = 1.0;
        int depDayIndex = -1;

        int meetDayIndex = (meetDayInput - 1) % 7;

        while (cumulativeSuccess + 1e-9 < pImp) {
            int currentDayIndex = (meetDayIndex - i + 7) % 7;
            double currentP;
            if (DAYS[currentDayIndex].equals("Sunday") || DAYS[currentDayIndex].equals("Saturday")) {
                currentP = pWend;
            } else {
                currentP = pWday;
            }

            cumulativeSuccess += cumulativeFailure * currentP;
            cumulativeFailure *= (1 - currentP);

            depDayIndex = currentDayIndex;

            if (cumulativeSuccess + 1e-9 >= pImp)
                break;
            i++;
        }

        String depDay = DAYS[depDayIndex];
        String meetDay = DAYS[meetDayIndex];
        String dayOrDays = (i == 1) ? "day" : "days";

        System.out.printf("Try to leave on %s, %d %s before the %s meeting.", depDay, i, dayOrDays, meetDay);

    }
}