import java.util.Scanner;

public class Main {

    // 요일을 나타내는 문자열 배열 (문제에서 1=일요일, ..., 7=토요일)
    private static final String[] DAY_NAMES = {
            "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 입력: 회의 요일, 주중 확률 p_wday, 주말 확률 p_wend, 중요도 p_imp
        int meetingDayIndex = sc.nextInt(); // 1~7
        int pWday = sc.nextInt(); // 0~100
        int pWend = sc.nextInt(); // 0~100
        int pImp = sc.nextInt(); // 1~99

        sc.close();

        // 배열 인덱스 맞추기: 문제의 1=일요일을 배열 상으로 0 인덱스에 맞춤
        // meetingDayIndex는 문제 정의에 따라 1~7, 우리 배열은 0~6이므로 조정
        int meetingDayArrayIndex = (meetingDayIndex - 1) % 7;

        // 중요도(퍼센트)를 0~1 범위 확률로 변환
        double requiredProbability = pImp / 100.0;
        double weekdayProb = pWday / 100.0;
        double weekendProb = pWend / 100.0;

        // i: 며칠 전부터 출발 시도하는지
        int bestDaysBefore = 1;
        while (true) {
            double successProbability = calculateSuccessProbability(
                    meetingDayArrayIndex, bestDaysBefore, weekdayProb, weekendProb);
            if (successProbability >= requiredProbability) {
                break;
            }
            bestDaysBefore++;
        }

        // 최종적으로 bestDaysBefore에 담긴 일수로 출발하면 요구사항 충족
        // 출발 요일 계산
        // (meetingDayIndex - bestDaysBefore) % 7 을 통해 요일 인덱스를 구하되,
        // 음수가 나오지 않도록 7을 더한 뒤 다시 % 7
        int departureIndex = (meetingDayArrayIndex - bestDaysBefore) % 7;
        if (departureIndex < 0) {
            departureIndex += 7;
        }

        String departureDayName = DAY_NAMES[departureIndex];
        String meetingDayName = DAY_NAMES[meetingDayArrayIndex];

        // 단/복수 표현 (1일 전이면 day, 그 외 days)
        String dayOrDays = (bestDaysBefore == 1) ? "day" : "days";

        // 출력 형식에 맞춰 메시지 구성
        System.out.printf("Try to leave on %s, %d %s before the %s meeting.\n",
                departureDayName, bestDaysBefore, dayOrDays, meetingDayName);
    }

    /**
     * 특정 며칠 전부터 매일 시도할 때, 회의 당일까지 출발 성공할 확률을 계산
     * 
     * @param meetingDayIndex 0~6 (일요일 0, 월요일 1, …)
     * @param daysBefore      며칠 전부터 시작하는지
     * @param pWday           주중 성공 확률
     * @param pWend           주말 성공 확률
     * @return 누적 성공 확률
     */
    private static double calculateSuccessProbability(int meetingDayIndex,
            int daysBefore,
            double pWday,
            double pWend) {
        // 실패 확률의 곱 = 모든 날 실패할 확률
        double failAllProbability = 1.0;

        // meetingDayIndex - 1일부터 (daysBefore)회 시도
        // ex) daysBefore=3 -> (회의 전날부터 3일 전까지) 역순으로 계산해도 동일
        for (int i = 0; i < daysBefore; i++) {
            // 비행을 시도하는 구체적 요일을 구함
            // 회의 전날부터 i일 전이 실제로는 (meetingDayIndex - 1 - i)
            int currentDayIndex = (meetingDayIndex - 1 - i) % 7;
            if (currentDayIndex < 0) {
                currentDayIndex += 7;
            }

            double successProb = isWeekday(currentDayIndex) ? pWday : pWend;
            double failProb = 1 - successProb;
            failAllProbability *= failProb;
        }

        // 적어도 하루 성공할 확률 = 1 - (모든 날 실패할 확률)
        return 1.0 - failAllProbability;
    }

    /**
     * 요일 인덱스가 주중(월~금)에 해당하는지 여부 반환
     * 일(0), 월(1), 화(2), 수(3), 목(4), 금(5), 토(6)
     */
    private static boolean isWeekday(int dayIndex) {
        return (dayIndex >= 1 && dayIndex <= 5);
    }
}