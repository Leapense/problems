import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // 빠른 입출력을 위한 BufferedReader 사용
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());

        // 몬스터와 장비 정보를 분리하여 저장
        List<Integer> monsters = new ArrayList<>();
        List<Integer> equips = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());
            int power = Integer.parseInt(st.nextToken());
            if (type == 1) {
                monsters.add(power);
            } else {
                equips.add(power);
            }
        }

        // 각 목록을 오름차순 정렬
        Collections.sort(monsters);
        Collections.sort(equips);

        // 최적화: 몬스터가 없는 경우, 모든 방은 장비 방이므로 장비의 개수를 출력
        if (monsters.isEmpty()) {
            System.out.println(equips.size());
            return;
        }

        // BigInteger로 현재 전투력 관리
        BigInteger cur = BigInteger.valueOf(D);
        long count = 0; // 돌파한 방의 수
        int mIndex = 0, eIndex = 0;

        // 남은 몬스터들 중 최대 전투력을 미리 구함
        BigInteger maxMonster = BigInteger.valueOf(monsters.get(monsters.size() - 1));

        while (true) {
            // 모든 방을 처리한 경우 종료
            if (mIndex >= monsters.size() && eIndex >= equips.size())
                break;

            // 만약 몬스터가 더 이상 남지 않았다면, 남은 장비는 순서대로 모두 획득 가능
            if (mIndex >= monsters.size()) {
                count += (equips.size() - eIndex);
                break;
            }

            // 현재 전투력이 남은 몬스터들 중 최대 전투력보다 크다면,
            // 남은 몬스터와 장비 모두 돌파 가능하므로 바로 종료
            if (cur.compareTo(maxMonster) > 0) {
                count += (monsters.size() - mIndex) + (equips.size() - eIndex);
                break;
            }

            // 다음 몬스터와 비교: 만약 현재 전투력이 다음 몬스터보다 크다면 쓰러뜨릴 수 있음
            BigInteger nextMonster = BigInteger.valueOf(monsters.get(mIndex));
            if (cur.compareTo(nextMonster) > 0) {
                cur = cur.add(nextMonster);
                mIndex++;
                count++;
                continue;
            }

            // 몬스터를 쓰러뜨릴 수 없는 경우, 남은 장비가 있다면 장비를 사용하여 전투력 증가
            if (eIndex < equips.size()) {
                cur = cur.multiply(BigInteger.valueOf(equips.get(eIndex)));
                eIndex++;
                count++;
                continue;
            }

            // 더 이상 진행할 수 없으면 종료
            break;
        }

        System.out.println(count);
    }
}