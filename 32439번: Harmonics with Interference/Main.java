import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String mStr = br.readLine().trim();
        String nStr = br.readLine().trim();

        char[] M = mStr.toCharArray();
        char[] N = nStr.toCharArray();
        int mLen = M.length, nLen = N.length;

        int[] starIdxM = new int[mLen];
        int[] starIdxN = new int[nLen];
        Arrays.fill(starIdxM, -1);
        Arrays.fill(starIdxN, -1);

        int starCount = 0;
        for (int i = 0; i < mLen; i++) {
            if (M[i] == '*') starIdxM[i] = starCount++;
        }
        for (int i = 0; i < nLen; i++) {
            if (N[i] == '*') starIdxN[i] = starCount++;
        }

        int totalMasks = 1 << starCount;

        for (int mask = 0; mask < totalMasks; mask++) {
            int v = 0;
            for (int i = 0; i < nLen; i++) {
                int bit;
                if (starIdxN[i] >= 0) {
                    bit = (mask >> starIdxN[i]) & 1;
                } else {
                    bit = N[i] - '0';
                }
                v = (v << 1) + bit;
            }
            if (v == 0) continue;

            int rem = 0;
            for (int i = 0; i < mLen; i++) {
                int bit;
                if (starIdxM[i] >= 0) {
                    bit = (mask >> starIdxM[i]) & 1;
                } else {
                    bit = M[i] - '0';
                }
                rem = ((rem << 1) + bit) % v;
            }

            if (rem == 0) {
                StringBuilder sb = new StringBuilder(mLen);
                for (int i = 0; i < mLen; i++) {
                    if (starIdxM[i] >= 0) {
                        sb.append(((mask >> starIdxM[i]) & 1) == 1 ? '1' : '0');
                    } else {
                        sb.append(M[i]);
                    }
                }
                System.out.println(sb.toString());
                return;
            }
        }

        StringBuilder fallback = new StringBuilder(mLen);
        for (int i = 0; i < mLen; i++) {
            fallback.append(M[i] == '*' ? '0' : M[i]);
        }

        System.out.println(fallback.toString());
    }
}