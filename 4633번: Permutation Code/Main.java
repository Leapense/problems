import java.io.*;
import java.util.*;

public class Main
{
    private static String decode(int x, String S, String P, String C) {
        int n = C.length();
        int d = (int)(Math.pow(n, 1.5) + x) % n;

        Map<Character, Integer> idxS = new HashMap<>();
        Map<Character, Integer> idxP = new HashMap<>();

        for (int i = 0; i < S.length(); i++) idxS.put(S.charAt(i), i);
        for (int i = 0; i < P.length(); i++) idxP.put(P.charAt(i), i);

        char[] invP = P.toCharArray();
        char[] M    = new char[n];

        int pos = idxS.get(C.charAt(d));
        M[d]    = invP[pos];

        int j = (d - 1 + n) % n;
        for (int filled = 0; filled < n - 1; filled++, j = (j - 1 + n) % n)
        {
            int k   = idxS.get(M[(j + 1) % n]);
            int sC  = idxS.get(C.charAt(j));
            int p   = sC ^ k;
            M[j]    = invP[p];
        }

        return new String(M);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        while (true)
        {
            String line = br.readLine();
            if (line == null) break;
            line = line.trim();
            if ("0".equals(line)) break;

            int x       = Integer.parseInt(line);
            String S    = br.readLine().trim();
            String P    = br.readLine().trim();
            String C    = br.readLine().trim();

            out.append(decode(x, S, P, C)).append('\n');
        }

        System.out.println(out.toString());
    }
}