import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 1. 전우 수 입력
        int N = Integer.parseInt(br.readLine());

        // 2. 좌표 초기화 및 입력
        String[] positions = br.readLine().split(" ");
        int[] pos = new int[N];
        for (int i = 0; i < N; i++) {
            pos[i] = Integer.parseInt(positions[i]);
        }
        

        // 3. 사거리 초기화 및 입력 (N이 1보다 크다면, N-1 크기의 배열로 초기화)
        int[] range = new int[N > 1 ? N - 1 : 0];
        if (N > 1) {
            String[] ranges = br.readLine().split(" ");
            for (int i = 0; i < N - 1; i++) {
                range[i] = Integer.parseInt(ranges[i]);
            }
        }

        // 초기 상태 설정: 욱제의 위치는 항상 0에서 시작하며, range의 첫번째 요소의 값에 더한다.
        int maxReach = 0;

        for (int i = 0; i < N - 1; i++) {
            if (pos[i] > maxReach) {
                System.out.println("엄마 나 전역 늦어질 것 같아");
                return;
            }

            maxReach = Math.max(maxReach, pos[i] + range[i]);
        }

        if (pos[N - 1] <= maxReach) {
            System.out.println("권병장님, 중대장님이 찾으십니다");
        } else {
            System.out.println("엄마 나 전역 늦어질 것 같아");
        }

        br.close();
    }
}