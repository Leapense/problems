import java.util.*;
import java.io.*;

public class Main {
    // mapping: 주어진 숫자 d에 대해 반대 방향을 리턴 (1↔3, 2↔4)
    private static int opposite(int d) {
        switch (d) {
            case 1:
                return 3;
            case 2:
                return 4;
            case 3:
                return 1;
            case 4:
                return 2;
        }
        return -1; // 도달하지 않음.
    }

    public static void main(String[] args) throws IOException {
        // 빠른 입출력을 위한 BufferedReader/Writer 사용
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        // 모양수열 길이
        int n = Integer.parseInt(br.readLine().trim());

        int[] base = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            base[i] = Integer.parseInt(st.nextToken());
        }

        int candidateCount = Integer.parseInt(br.readLine().trim());
        List<int[]> resultList = new ArrayList<>();

        for (int i = 0; i < candidateCount; i++) {
            int[] candidate = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                candidate[j] = Integer.parseInt(st.nextToken());
            }
            if (isSamePolygon(base, candidate)) {
                resultList.add(candidate);
            }
        }

        // 결과 출력
        StringBuilder sb = new StringBuilder();
        sb.append(resultList.size()).append("\n");
        for (int[] seq : resultList) {
            for (int num : seq) {
                sb.append(num).append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }

    // 두 수열이 같은 다각형을 그릴 수 있는지 판별하는 메서드
    // 후보 candidate가 base의 원래 순서 혹은 반대방향(역순 후 각 숫자 반전)의 cyclic rotation과 같으면 true
    private static boolean isSamePolygon(int[] base, int[] candidate) {
        if (isCyclicRotation(base, candidate))
            return true;

        // base의 역순(반대방향) 수열 생성:
        // 뒤에서부터 읽으면서 각 숫자를 반대 방향으로 변환
        int n = base.length;
        int[] rev = new int[n];
        for (int i = 0; i < n; i++) {
            rev[i] = opposite(base[n - 1 - i]);
        }
        if (isCyclicRotation(rev, candidate))
            return true;

        return false;
    }

    // reference 수열의 모든 cyclic rotation 중에 candidate와 같은 것이 있는지 검사
    private static boolean isCyclicRotation(int[] reference, int[] candidate) {
        int n = reference.length;
        // 각 가능한 시작위치를 시도
        for (int start = 0; start < n; start++) {
            boolean match = true;
            for (int i = 0; i < n; i++) {
                if (reference[(start + i) % n] != candidate[i]) {
                    match = false;
                    break;
                }
            }
            if (match)
                return true;
        }
        return false;
    }
}
