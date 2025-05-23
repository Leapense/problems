import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); // 아이의 수 (집의 수)
        int M = sc.nextInt(); // 선물 창고의 수

        // M = 0 인 경우, 오두막에서 N개를 바로 싣으면 됨.
        if (M == 0) {
            System.out.println(N);
            return;
        }

        // 1-indexed로 창고 정보를 저장
        int[] p = new int[M + 2]; // 공급 지점: p[1..M] = 집 번호, p[0]=0 (오두막), p[M+1]=N (끝)
        int[] Z = new int[M + 1]; // Z[1..M] : 각 창고의 보충 가능 선물 수

        for (int i = 1; i <= M; i++) {
            p[i] = sc.nextInt(); // 창고가 있는 집 번호
            Z[i] = sc.nextInt(); // 해당 창고에 쌓인 선물 수
        }
        p[0] = 0;
        p[M + 1] = N;

        // A[i] : i번째 공급 지점(창고)에서 해당 집에 선물을 준 후, 썰매에 남겨둬야 하는 최소 선물 수.
        int[] A = new int[M + 1]; // 1-indexed, A[1..M]

        // 마지막 창고: 집 p[M]에서 선물을 준 후 남아야 하는 수 = N - p[M]
        A[M] = p[M + 1] - p[M]; // = N - p[M]

        // 역방향으로 A[i] 계산 (i = M-1 .. 1)
        for (int i = M - 1; i >= 1; i--) {
            // 구간 i -> i+1: 집들 사이의 수
            int gap = p[i + 1] - p[i] - 1;
            // 만약 i+1번째 창고에서 최대 보충량 Z[i+1]를 다 쓸 경우, 이전에 남겨야 할 최소 선물수는
            int candidate = A[i + 1] + (p[i + 1] - p[i]) - Z[i + 1];
            // 반드시 gap 이상의 선물이 있어야 (도착 시 음수가 되지 않도록)
            A[i] = Math.max(gap, candidate);
            if (A[i] < 0)
                A[i] = 0; // 음수는 불가능
        }

        // 오두막(공급 지점 0)에서 첫 창고 p[1]에 도착하기 전까지 창고가 없으므로, 집의 개수는 (p[1]-1)
        // 또한, 첫 창고에서의 보충을 최대한 활용한다고 할 때 X는 다음 조건을 만족해야 함:
        // 도착 시 남은 선물이: X - (p[1]-1)
        // 그리고 첫 창고에서는 선물 L1을 싣고 바로 선물을 주므로,
        // A[1] = (X - (p[1]-1)) + L1 - 1 => L1 = A[1] - (X - (p[1]-1)) + 1.
        // L1는 최대 Z[1]를 넘을 수 없으므로 X는 최소 X >= A[1] + p[1] - Z[1] 이어야 함.
        int X = Math.max(p[1] - 1, A[1] + p[1] - Z[1]);

        // X가 p[1]-1 미만이 될 수는 없으므로 X로 결정.

        // 이제 각 창고에서 싣는 선물 수 L[i] 계산 (1-indexed)
        int[] L = new int[M + 1]; // L[1..M]

        // 첫 창고: 도착 시 남은 선물 = X - (p[1]-1)
        int arrival = X - (p[1] - 1);
        L[1] = A[1] - arrival + 1;
        // (L[1]가 음수이면 0으로; 실제로 필요한 경우 최소 1개는 싣게 됨)
        if (L[1] < 0)
            L[1] = 0;
        if (L[1] > Z[1])
            L[1] = Z[1]; // 최대 한계

        // 그 다음 창고들
        for (int i = 2; i <= M; i++) {
            // i번째 창고에 도착할 때 남은 선물:
            // 이전 창고에서 출발할 때 남은 A[i-1]개에서, 집들 사이의 갭만큼 소비됨.
            arrival = A[i - 1] - (p[i] - p[i - 1] - 1);
            L[i] = A[i] - arrival + 1;
            if (L[i] < 0)
                L[i] = 0;
            if (L[i] > Z[i])
                L[i] = Z[i];
        }

        // 결과 출력: 첫 줄은 오두막에서 출발할 때 싣는 선물 수, 이후 각 창고에서 추가로 싣는 선물 수.
        System.out.println(X);
        for (int i = 1; i <= M; i++) {
            System.out.println(L[i]);
        }
    }
}
