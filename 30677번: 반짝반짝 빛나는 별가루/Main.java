import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // 입력 준비
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); // 총 일수
        int K = Integer.parseInt(st.nextToken()); // 마법 종류 수
        int C = Integer.parseInt(st.nextToken()); // combo 상수
        int R = Integer.parseInt(st.nextToken()); // 휴식 시 피로도 감소량

        // 각 마법의 기본 별가루 수치
        int[] base = new int[K];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            base[i] = Integer.parseInt(st.nextToken());
        }

        // 각 마법의 s 상수
        int[] s = new int[K];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            s[i] = Integer.parseInt(st.nextToken());
        }

        // 각 마법의 피로도 증가량
        int[] p = new int[K];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            p[i] = Integer.parseInt(st.nextToken());
        }

        // N일 동안의 계획 (마법 번호, 0이면 휴식)
        int[] plan = new int[N];
        for (int i = 0; i < N; i++) {
            plan[i] = Integer.parseInt(br.readLine());
        }

        // 상태 변수 초기화
        int fatigue = 0; // 현재 피로도
        int combo = 0; // 연속 마법 사용 횟수
        int[] skill = new int[K]; // 각 마법별 숙련도 (초기 0)
        BigInteger totalStardust = BigInteger.ZERO; // 누적 별가루

        // 시뮬레이션 진행
        for (int day = 0; day < N; day++) {
            int action = plan[day];

            if (action == 0) { // 휴식
                fatigue = Math.max(fatigue - R, 0);
                combo = 0; // 연속 사용 횟수 리셋
            } else { // 마법 사용
                int magicIndex = action - 1; // 0-indexed 변환

                // 별가루 계산
                // 계산식: floor( base_i * (100 + combo * C) * (100 + skill_i * s_i) / 10000 )
                long factor1 = 100L + combo * (long) C;
                long factor2 = 100L + skill[magicIndex] * (long) s[magicIndex];

                BigInteger produced = BigInteger.valueOf(base[magicIndex])
                        .multiply(BigInteger.valueOf(factor1))
                        .multiply(BigInteger.valueOf(factor2))
                        .divide(BigInteger.valueOf(10000));

                totalStardust = totalStardust.add(produced);

                // 숙련도 및 combo 업데이트
                skill[magicIndex]++;
                combo++;

                // 피로도 증가 및 체크
                fatigue += p[magicIndex];
                if (fatigue > 100) {
                    System.out.println(-1);
                    return;
                }
            }
        }

        // 최종 누적 별가루 출력
        System.out.println(totalStardust);
    }
}