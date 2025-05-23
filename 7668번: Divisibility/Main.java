import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s;
        while (!(s = br.readLine()).equals("end")) {
            int rem = 0;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                int value = c >= '0' && c <= '9' ? c - '0' : c >= 'A' && c <= 'Z' ? c - 'A' + 10 : c - 'a' + 36;
                rem = (rem * 62 + value) % 61;
            }
            out.println(rem == 0 ? "yes" : "no");
        }
        out.flush();
    }
}