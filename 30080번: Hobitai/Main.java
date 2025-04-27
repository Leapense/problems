import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        char[] S = br.readLine().toCharArray();

        int[] count = new int[256];
        int[] lastEnd = new int[256];

        for (int i = 0; i < 256; i++) {
            lastEnd[i] = -8;
        }

        int mask = 0;
        for (int i = 0; i < 7; i++) {
            mask = ((mask << 1) & 0xFF) | (S[i] == 'O' ? 1 : 0);
        }

        for (int i = 7; i < N; i++) {
            mask = ((mask << 1) & 0xFF) | (S[i] == 'O' ? 1 : 0);
            int start = i - 7;

            if (start - lastEnd[mask] >= 8) {
                count[mask]++;
                lastEnd[mask] = start;
            }
        }

        int bestMask = 0, bestCnt = 0;
        for (int b = 0; b < 256; b++) {
            if (count[b] > bestCnt) {
                bestCnt = count[b];
                bestMask = b;
            }
        }

        StringBuilder pattern = new StringBuilder(8);
        for (int j = 7; j >= 0; j--) {
            pattern.append(((bestMask >> j) & 1) == 1 ? 'O' : 'H');
        }

        System.out.println(bestCnt * 8);
        System.out.println(pattern);
    }
}