import java.io.*;
import java.util.*;

public class Main {
    private static final int DIM = 11; // 차원
    private static final int VERT = 2047; // 입력 꼭짓점 수

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[] xor = new long[DIM]; // 누적 XOR

        String line;
        int readCnt = 0;
        while ((line = br.readLine()) != null && line.length() > 0) {
            StringTokenizer st = new StringTokenizer(line);
            for (int d = 0; d < DIM; d++) {
                // 다음 토큰이 없으면 다음 줄에서 이어서 읽어옴
                while (!st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine());
                xor[d] ^= Long.parseLong(st.nextToken());
            }
            ++readCnt;
        }
        if (readCnt != VERT) {
            // 문제에서 2047줄이라 했는데 부족/과잉이면 바로 종료
            System.err.println("잘못된 입력 줄 수: " + readCnt);
            return;
        }

        StringBuilder sb = new StringBuilder();
        for (int d = 0; d < DIM; ++d) {
            if (d > 0)
                sb.append(' ');
            sb.append(xor[d]);
        }
        System.out.println(sb);
    }
}
