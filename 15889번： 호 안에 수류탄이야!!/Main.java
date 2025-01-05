import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 1. 전우 수 입력
        int N = Integer.parseInt(br.readLine());

        // 2. 좌표 초기화 및 입력
        int[] pos = new int[N];
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            pos[i] = Integer.parseInt(input[0]);
        }

        // 3. 사거리 초기화 및 입력 (N이 1보다 크다면, N-1 크기의 배열로 초기화)
        int[] range = new int[N - 1];
        for (int i = 0; i < N - 1; i++) {
            String[] input = br.readLine().split(" ");
            range[i] = Integer.parseInt(input[0]);
        }


        // 초기 상태 설정: 욱제의 위치는 항상 0에서 시작하며, range의 첫번째 요소의 값에 더한다.
        int initial_stats = pos[0] + range[0];

        for (int i = 1; i < N - 1; i++) {
            // pos와 range의 요소를 가져와서 더하고, 초기 상태와 비교하여 더 큰 경우 초기 상태를 갱신한다.
            initial_stats = Math.max(initial_stats, pos[i] + range[i]);
        }

        // 마지막 전우의 위치가 초기 상태보다 크다면, 게임이 조용히 마무리 될 수 있다는 것이다.
        if (pos[N - 1] <= initial_stats) {
            System.out.println("권병장님, 중대장님이 찾으십니다");
        } else {
            System.out.println("엄마 나 전역 늦어질 것 같아");
        }
        br.close();
    }
}