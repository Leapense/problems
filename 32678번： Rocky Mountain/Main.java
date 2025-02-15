import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // 빠른 입출력을 위한 BufferedReader와 BufferedWriter 사용
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] x = new int[N];
        int[] y = new int[N];

        // 좌표 입력
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());
        }

        // 최고점 찾기 (유일한 최고점이며, 0과 N-1은 아님)
        int peak = -1;
        for (int i = 0; i < N; i++) {
            if (peak == -1 || y[i] > y[peak]) {
                peak = i;
            }
        }

        // 왼쪽 후보 찾기 (인덱스 0 ~ peak-1)
        int bestLeft = -1;
        double bestLeftSlope = Double.POSITIVE_INFINITY;
        // p-1부터 0까지 검사 (왼쪽에서는 후보와 최고점 사이의 거리로 나누므로 음수가 아니게 됨)
        for (int i = peak - 1; i >= 0; i--) {
            double slope = (double) (y[peak] - y[i]) / (x[peak] - x[i]);
            // 더 낮은 slope (케이블이 더 낮게 연결됨)을 찾거나, 기울기가 같은 경우 더 왼쪽인 것을 선택
            if (slope < bestLeftSlope) {
                bestLeftSlope = slope;
                bestLeft = i;
            } else if (slope == bestLeftSlope) {
                // 기울기가 같다면 더 왼쪽(인덱스가 작은) 선택
                bestLeft = i;
            }
        }

        // 오른쪽 후보 찾기 (인덱스 peak+1 ~ N-1)
        int bestRight = -1;
        double bestRightSlope = Double.POSITIVE_INFINITY;
        // 오른쪽에서는 x[i] - x[peak]가 양수이므로 문제없음
        for (int i = peak + 1; i < N; i++) {
            double slope = (double) (y[peak] - y[i]) / (x[i] - x[peak]);
            // 더 낮은 slope를 선택, 기울기가 같은 경우 더 오른쪽(인덱스가 큰)을 선택
            if (slope < bestRightSlope) {
                bestRightSlope = slope;
                bestRight = i;
            } else if (slope == bestRightSlope) {
                bestRight = i; // 오른쪽에서는 반복하면서 더 큰 인덱스가 마지막에 남음
            }
        }

        // 결과 출력
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(x[bestLeft] + " " + y[bestLeft] + "\n");
        bw.write(x[bestRight] + " " + y[bestRight] + "\n");
        bw.flush();
        bw.close();
    }
}