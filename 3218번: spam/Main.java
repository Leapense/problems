import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        br.close();

        Set<String> answers = new LinkedHashSet<>();

        tryRecover(s, answers);

        String needle = "nospam";
        int L = s.length();

        for (int i = 0; i + needle.length() <= L; i++) {
            if (s.startsWith(needle, i)) {
                String t = s.substring(0, i) + s.substring(i + needle.length());
                tryRecover(t, answers);
            }
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (String email : answers) {
            bw.write(email);
            bw.newLine();
        }
        bw.flush();
    }

    static void tryRecover(String t, Set<String> ans) {
        int n = t.length();
        for (int i = 0; i + 2 <= n; i++) {
            if (t.charAt(i) == 'a' && t.charAt(i + 1) == 't') {
                String e = t.substring(0, i) + '@' + t.substring(i + 2);
                if (isValidEmail(e)) {
                    ans.add(e);
                }
            }
        }
    }

    static boolean isValidEmail(String e) {
        int n = e.length();
        int atPos = e.indexOf('@');
        if (atPos < 1 || atPos != e.lastIndexOf('@') || atPos == n-1) return false;

        for (char c : e.toCharArray()) {
            if (!(c >= 'a' && c <= 'z') && c != '.' && c != '@') return false;
        }

        char left = e.charAt(atPos - 1), right = e.charAt(atPos + 1);
        if (!(left >= 'a' && left <= 'z')) return false;
        if (!(right >= 'a' && right <= 'z')) return false;
        if (e.charAt(0) == '.' || e.charAt(n-1) == '.') {
            return false;
        }
        return true;
    }
}