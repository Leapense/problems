import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] value = new int[n][];
        int totalNodes = n * (n + 1) / 2;

        // 입력값을 삼각형 형태의 2차원 배열로 변환
        List<Integer> flat = new ArrayList<>(totalNodes);
        for (int i = 0; i < totalNodes; i++)
        {
            flat.add(scanner.nextInt());
        }
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            value[i] = new int[i + 1];
            for (int j = 0; j <= i; j++)
            {
                value[i][j] = flat.get(idx++);
            }
        }

        // DP와 부모 추적 배열 초기화
        int[][] dp = new int[n][];
        int[][] parent = new int[n][];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[i + 1];
            parent[i] = new int[i + 1];
        }

        // 레벨 0 초기화
        dp[0][0] = value[0][0];
        parent[0][0] = -1;

        // DP 테이블 채우기
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                int leftParent = j > 0 ? dp[i - 1][j - 1] : Integer.MIN_VALUE;
                int rightParent = j < i ? dp[i - 1][j] : Integer.MIN_VALUE;

                if (leftParent >= rightParent) {
                    dp[i][j] = leftParent + value[i][j];
                    parent[i][j] = j - 1;
                } else {
                    dp[i][j] = rightParent + value[i][j];
                    parent[i][j] = j;
                }
            }
        }

        // 마지막 레벨에서 최대 합 경로의 끝 위치 찾기
        int maxSum = Integer.MIN_VALUE;
        int maxIndex = 0;
        for (int j = 0; j < dp[n - 1].length; j++)
        {
            if (dp[n - 1][j] > maxSum) {
                maxSum = dp[n - 1][j];
                maxIndex = j;
            }
        }

        // 경로 복원
        List<Integer> path = new ArrayList<>(n);
        int row = n - 1;
        int col = maxIndex;
        while (row >= 0) {
            path.add(value[row][col]);
            col = parent[row][col];
            row--;
        }
        Collections.reverse(path);

        // 두 숫자 계산
        long sumOfSquares = 0;
        long sum = 0;

        for (var v : path)
        {
            sumOfSquares += (long) v * v;
            sum += v;
        }

        // 알파벳 변환 (0 -> a, ..., 25 -> z 순환)
        char firstChar = (char) ('a' + (sumOfSquares % 26));
        char secondChar = (char) ('a' + (sum % 26));

        // 결과 출력
        System.out.printf("%d %d%n", sumOfSquares, sum);
        System.out.printf("%c%c%n", firstChar, secondChar);

        scanner.close();
    }
}