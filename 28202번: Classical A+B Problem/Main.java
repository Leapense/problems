import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String n = br.readLine().trim();
            String ansA = "", ansB = "";
            int L = n.length();
            boolean found = false;
            List<Integer> candidateLengths = new ArrayList<>();
            if (L == 1)
                candidateLengths.add(1);
            else {
                candidateLengths.add(L);
                candidateLengths.add(L - 1);
            }
            for (int lenA : candidateLengths) {
                for (int d = 1; d <= 9; d++) {
                    String a = repeatChar((char) (d + '0'), lenA);
                    if (compare(n, a) < 0)
                        continue;
                    String b = subtract(n, a);
                    if (b.equals("0"))
                        continue;
                    if (isRepdigit(b)) {
                        ansA = a;
                        ansB = b;
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
            out.println(ansA + " " + ansB);
        }
        out.flush();
    }

    static String repeatChar(char c, int count) {
        char[] arr = new char[count];
        Arrays.fill(arr, c);
        return new String(arr);
    }

    static int compare(String a, String b) {
        if (a.length() != b.length())
            return a.length() - b.length();
        return a.compareTo(b);
    }

    static String subtract(String n, String m) {
        int i = n.length() - 1, j = m.length() - 1, carry = 0;
        StringBuilder sb = new StringBuilder();
        while (i >= 0 || j >= 0) {
            int a = i >= 0 ? n.charAt(i) - '0' : 0;
            int b = j >= 0 ? m.charAt(j) - '0' : 0;
            int sub = a - b - carry;
            if (sub < 0) {
                sub += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            sb.append(sub);
            i--;
            j--;
        }
        while (sb.length() > 1 && sb.charAt(sb.length() - 1) == '0')
            sb.setLength(sb.length() - 1);
        return sb.reverse().toString();
    }

    static boolean isRepdigit(String s) {
        char c = s.charAt(0);
        for (int i = 1; i < s.length(); i++)
            if (s.charAt(i) != c)
                return false;
        return true;
    }
}