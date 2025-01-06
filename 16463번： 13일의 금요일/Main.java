import java.io.*;
import java.util.*;

public class Main {
    public static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int startYear = 2019;
        int dayOfWeek = 2;
        int count = 0;

        for (int year = startYear; year <= N; year++) {
            for (int month = 0; month < 12; month++) {
                int day13 = (dayOfWeek + 12) % 7;
                if (day13 == 5) {
                    count++;
                }

                int days = daysInMonth[month];
                if (month == 1 && isLeapYear(year)) {
                    days = 29;
                }

                dayOfWeek = (dayOfWeek + days) % 7;
            }
        }

        System.out.println(count);
    }
}