import java.io.*;
import java.util.*;

public class Main {
    static final String NEWLINE = System.lineSeparator();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            String P = st.nextToken().trim();

            if (N == 1) { // 1‑자리 특수 처리
                char p = P.charAt(0);
                char q = (p != '4') ? '4' : '6'; // 4 또는 6 택 1
                int r = (q == '4' || q == '6') ? 2 : 3;
                out.append(q).append(' ').append(r).append(NEWLINE);
                continue;
            }

            int digitSum = 0;
            for (int i = 0; i < N; i++)
                digitSum += P.charAt(i) - '0';

            char[] arr = P.toCharArray();
            Set<String> made = new HashSet<>();

            for (int pos = 0; pos < N; pos++) {
                char original = arr[pos];
                int baseSum = digitSum - (original - '0');
                boolean done = false;

                // 0~9 후보 가운데 조건 만족 & 중복 아님인 첫 번째를 고른다.
                for (char c = '0'; c <= '9' && !done; c++) {
                    if (c == original)
                        continue;
                    if (pos == 0 && c == '0')
                        continue; // leading zero 금지
                    int newSum = baseSum + (c - '0');
                    if (newSum % 3 != 0)
                        continue; // 3의 배수 조건
                    arr[pos] = c;
                    String qStr = new String(arr);
                    if (made.add(qStr)) { // 중복 검사
                        out.append(qStr).append(" 3").append(NEWLINE);
                        done = true;
                    }
                    arr[pos] = original; // 원상복구 후 다음 후보
                }

                // 만에 하나 실패했다면 2의 배수(짝수)로 만드는 플랜 B
                if (!done) {
                    for (char c = '0'; c <= '9'; c++) {
                        if (c == original)
                            continue;
                        if (pos == 0 && c == '0')
                            continue;
                        arr[pos] = c;
                        String qStr = new String(arr);
                        if ((qStr.charAt(N - 1) & 1) == 0 && made.add(qStr)) {
                            out.append(qStr).append(" 2").append(NEWLINE);
                            done = true;
                            break;
                        }
                        arr[pos] = original;
                    }
                }
            }
        }
        System.out.print(out.toString());
    }
}
