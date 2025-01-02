import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * 스모그 게임 플랫폼에서 가성비가 높은 K개의 게임을 선택하는 프로그램.
 * 
 * 가성비는 만족도 대비 가격으로 정의되며, 
 * 가성비가 높은 순, 가성비가 동일하면 가격이 낮은 순, 
 * 가격까지 동일하면 게임 번호가 작은 순으로 정렬하여 K개의 게임을 선택한다.
 */
public class Main {
    /**
     * 게임 정보를 저장하는 클래스.
     */
    static class Game {
        int id;         // 게임 번호
        long price;     // 게임 가격
        long satisfaction; // 게임 만족도

        public Game(int id, long price, long satisfaction) {
            this.id = id;
            this.price = price;
            this.satisfaction = satisfaction;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // 첫 번째 줄: N (게임 수)과 K (선택할 게임 수)
        String[] firstLine = br.readLine().trim().split("\\s+");
        int N = Integer.parseInt(firstLine[0]);
        int K = Integer.parseInt(firstLine[1]);

        List<Game> games = new ArrayList<>();

        // 다음 N줄: 각 게임의 번호, 가격, 만족도
        for (int i = 0; i < N; i++) {
            String[] gameInfo = br.readLine().trim().split("\\s+");
            int id = Integer.parseInt(gameInfo[0]);
            long price = Long.parseLong(gameInfo[1]);
            long satisfaction = Long.parseLong(gameInfo[2]);
            games.add(new Game(id, price, satisfaction));
        }

        // 게임 목록을 정렬
        Collections.sort(games, new Comparator<Game>() {
            @Override
            public int compare(Game g1, Game g2) {
                // 교차 곱을 이용한 가성비 비교: g1.value > g2.value 이면 g1이 앞
                // h1/c1 > h2/c2 ↔ h1 * c2 > h2 * c1
                long lhs = g1.satisfaction * g2.price;
                long rhs = g2.satisfaction * g1.price;
                if (lhs != rhs) {
                    return Long.compare(rhs, lhs); // 내림차순
                }
                // 가성비가 동일하면 가격 오름차순
                if (g1.price != g2.price) {
                    return Long.compare(g1.price, g2.price);
                }
                // 가격도 동일하면 게임 번호 오름차순
                return Integer.compare(g1.id, g2.id);
            }
        });

        // 상위 K개의 게임을 선택하여 출력
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < K; i++) {
            sb.append(games.get(i).id).append('\n');
        }
        System.out.print(sb);
    }
}
