import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String nStr = br.readLine().trim();
            BigInteger n = new BigInteger(nStr);
            int L = nStr.length();
            boolean found = false;
            if (L == 1) {
                out.println("1 1");
                continue;
            }
            if (nStr.charAt(0) != '1') {
                StringBuilder aBuilder = new StringBuilder();
                for (int i = 0; i < L; i++) {
                    aBuilder.append(nStr.charAt(0));
                }
                BigInteger aCandidate = new BigInteger(aBuilder.toString());
                BigInteger bCandidate = n.subtract(aCandidate);
                if (isRepdigit(bCandidate.toString())) {
                    out.println(aCandidate + " " + bCandidate);
                    continue;
                }
            }
            for (int d = 1; d <= 9 && !found; d++) {
                StringBuilder aBuilder = new StringBuilder();
                for (int i = 0; i < L - 1; i++) {
                    aBuilder.append((char) (d + '0'));
                }
                BigInteger aCandidate = new BigInteger(aBuilder.toString());
                BigInteger bCandidate = n.subtract(aCandidate);
                if (bCandidate.compareTo(BigInteger.ZERO) > 0 && isRepdigit(bCandidate.toString())) {
                    out.println(aCandidate + " " + bCandidate);
                    found = true;
                    break;
                }
            }
        }
        out.flush();
        out.close();
    }

    private static boolean isRepdigit(String s) {
        char c = s.charAt(0);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) != c)
                return false;
        }
        return true;
    }
}