import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());   // 사람 수
        int K = Integer.parseInt(st.nextToken());   // 메시지 개수
        int Q = Integer.parseInt(st.nextToken());   // 관심 메시지 번호

        int[] R = new int[K+1];         // R[i]: i번째 메시지의 최종 읽지 않은 사람 수
        int[] lastSend = new int[N];    // lastSend[x]: x번(0=A,1=B,...) 사람이 마지막으로 보낸 메시지 인덱스
        Arrays.fill(lastSend, 0);

        // 메시지 정보 입력
        for (int i = 1; i <= K; i++) {
            st = new StringTokenizer(br.readLine());
            R[i] = Integer.parseInt(st.nextToken());
            char p = st.nextToken().charAt(0);
            int idx = p - 'A';
            lastSend[idx] = i;  // idx번 사람이 i번째에 메시지 보냄
        }

        // Q번째 메시지를 읽지 않았을 가능성이 있는 사람들
        // 조건: 'A'(index=0)를 제외하고 lastSend[x] <= Q
        List<Character> ans = new ArrayList<>();
        if (R[Q] > 0) {
            for (int x = 1; x < N; x++) {
                if (lastSend[x] <= Q) {
                    ans.add((char)('A' + x));
                }
            }
        }

        // 출력
        if (ans.isEmpty()) {
            System.out.println(-1);
        } else {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < ans.size(); i++) {
                if (i > 0) sb.append(' ');
                sb.append(ans.get(i));
            }
            System.out.println(sb);
        }
    }
}
