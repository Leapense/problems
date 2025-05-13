import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    // 허용 문자 판별
    private static boolean isAllowed(int x) {
        return x == 32 || x == 46 || (97 <= x && x <= 122);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        
        // 암호문은 여러 줄에 걸쳐 있을 수 있으므로 토큰 단위로 N개를 읽는다.
        int[] cipher = new int[N];
        int read = 0;

        while (read < N) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens() && read < N) {
                String token = st.nextToken();
                cipher[read++] = Integer.parseInt(token, 16);
            }
        }

        StringBuilder sb = new StringBuilder(N);

        for (int c : cipher) {
            boolean letterPossible = false;
            boolean nonLetterPossible = false;

            for (int k = 48; k <= 57; k++) {
                int p = c ^ k;
                if (!isAllowed(p)) continue;

                if (97 <= p && p <= 122) letterPossible = true;
                else nonLetterPossible = true;
            }

            if (letterPossible && !nonLetterPossible) sb.append('-');
            else sb.append('.');
        }

        System.out.println(sb.toString());
    }
}