import java.io.*;
import java.util.*;

public class Main {
    static int R, C;
    static int[][] a, right, down;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 1) R, C 읽기
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        // 2) 행렬 입력: R*C 개수만큼 토큰 단위로 읽기
        a = new int[R][C];
        int total = R * C;
        int idx = 0;
        st = new StringTokenizer("");
        while (idx < total) {
            if (!st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null)
                    break; // 안전장치
                st = new StringTokenizer(line);
                continue;
            }
            int val = Integer.parseInt(st.nextToken());
            a[idx / C][idx % C] = val;
            idx++;
        }

        // 3) right, down 전처리
        right = new int[R][C];
        down = new int[R][C];
        for (int i = R - 1; i >= 0; i--) {
            for (int j = C - 1; j >= 0; j--) {
                right[i][j] = 1;
                down[i][j] = 1;
                if (j + 1 < C && a[i][j] < a[i][j + 1])
                    right[i][j] = right[i][j + 1] + 1;
                if (i + 1 < R && a[i][j] < a[i + 1][j])
                    down[i][j] = down[i + 1][j] + 1;
            }
        }

        // 4) 최대 면적 탐색
        int maxArea = 0;
        List<int[]> answers = new ArrayList<>();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int horizMin = Integer.MAX_VALUE;
                int maxH = down[i][j];

                for (int h = 1; h <= maxH; h++) {
                    // 가로 증가 길이 최소값 갱신
                    horizMin = Math.min(horizMin, right[i + h - 1][j]);
                    if (horizMin == 0)
                        break;

                    // 세로 증가 조건 만족하는 연속 열 개수 계산
                    int vertLen = 0;
                    while (vertLen < horizMin && down[i][j + vertLen] >= h) {
                        vertLen++;
                    }
                    if (vertLen == 0)
                        break;

                    int area = h * vertLen;
                    if (area < maxArea)
                        continue;
                    if (area > maxArea) {
                        maxArea = area;
                        answers.clear();
                    }
                    answers.add(new int[] { i + 1, j + 1, h, vertLen });
                }
            }
        }

        // 5) 사전순 정렬 및 출력
        answers.sort((u, v) -> {
            for (int k = 0; k < 4; k++) {
                if (u[k] != v[k])
                    return u[k] - v[k];
            }
            return 0;
        });

        StringBuilder sb = new StringBuilder();
        for (int[] t : answers) {
            if (t[2] * t[3] == maxArea) {
                sb.append(t[0]).append(' ')
                        .append(t[1]).append(' ')
                        .append(t[2]).append(' ')
                        .append(t[3]).append('\n');
            }
        }
        System.out.print(sb);
    }
}
