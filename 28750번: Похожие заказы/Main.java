import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int n = Integer.parseInt(br.readLine());
        String t = br.readLine();
        String s = br.readLine();

        if (n == 1) {
            int d = ((s.charAt(0) - t.charAt(0)) % 26 + 26) % 26;
            pw.println("Success");
            pw.printf("0 %d%n", d);
            pw.flush();
            return;
        }

        int[] Dt = new int[n];
        int[] Ds = new int[n];

        for (int i = 0; i < n; i++) {
            Dt[i] = ((t.charAt((i + 1) % n) - t.charAt(i)) % 26 + 26) % 26;
            Ds[i] = ((s.charAt((i + 1) % n) - s.charAt(i)) % 26 + 26) % 26;
        }

        int[] text = new int[2 * n - 1];
        for (int i = 0; i < 2 * n - 1; i++) {
            text[i] = Ds[i % n];
        }
        int[] pat = Dt;
        int[] pi = new int[n];
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && pat[i] != pat[j]) {
                j = pi[j - 1];
            }
            if (pat[i] == pat[j]) {
                j++;
            }
            pi[i] = j;
        }

        int matchPos = -1;
        for (int i = 0, j = 0; i < text.length; i++) {
            while (j > 0 && text[i] != pat[j]) {
                j = pi[j - 1];
            }
            if (text[i] == pat[j]) {
                j++;
            }
            if (j == n) {
                matchPos = i - (n - 1);
                break;
            }
        }

        if (matchPos < 0) {
            pw.println("Impossible");
        } else {
            int k = matchPos % n;
            int d = ((s.charAt(k) - t.charAt(0)) % 26 + 26) % 26;
            pw.println("Success");
            pw.printf("%d %d%n", k, d);
        }
        pw.flush();
    }
}
