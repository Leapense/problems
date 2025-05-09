import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); // 나무의 개수
        int C = Integer.parseInt(st.nextToken()); // 자르는 비용
        int W = Integer.parseInt(st.nextToken()); // 단위 길이당 가격

        List<Integer> initialLengths = new ArrayList<>();
        int maxInitialLength = 0;
        for (int i = 0; i < N; i++) {
            int length = Integer.parseInt(br.readLine());
            initialLengths.add(length);
            if (length > maxInitialLength) {
                maxInitialLength = length;
            }
        }

        long maxTotalProfit = 0;

        // 가능한 모든 최종 나무 길이 targetL (1부터 maxInitialLength까지)을 시도
        for (int targetL = 1; targetL <= maxInitialLength; targetL++) {
            long currentProfitForThisTargetL = 0;

            // 각 초기 나무에 대해 계산
            for (int initialL : initialLengths) {
                if (initialL < targetL) {
                    // 이 나무는 targetL 길이로 만들 수 없으므로 무시
                    continue;
                }

                int numPieces = initialL / targetL; // 이 나무에서 얻을 수 있는 targetL 길이 조각의 수

                long revenueFromThisWood = (long) numPieces * targetL * W;

                int numCuts;
                if (initialL % targetL == 0) {
                    // 정확히 나누어 떨어지면, 조각 수 - 1 만큼 자름
                    numCuts = numPieces - 1;
                } else {
                    // 나머지가 있으면, 조각 수 만큼 자름 (마지막 남은 부분도 잘라낸 것으로 간주)
                    numCuts = numPieces;
                }

                long costForThisWood = (long) numCuts * C;

                long profitFromThisWood = revenueFromThisWood - costForThisWood;

                // 이 나무를 잘라서 파는 것이 이득일 때만 총 이익에 합산
                if (profitFromThisWood > 0) {
                    currentProfitForThisTargetL += profitFromThisWood;
                }
            }

            if (currentProfitForThisTargetL > maxTotalProfit) {
                maxTotalProfit = currentProfitForThisTargetL;
            }
        }

        System.out.println(maxTotalProfit);
    }
}