import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        String x = br.readLine().trim();
        int k = Integer.parseInt(br.readLine().trim());

        String fractional = x.substring(2);
        StringBuilder result = new StringBuilder();

        if (fractional.length() <= k) {
            result.append(fractional);
            while (result.length() < k) {
                result.append('0');
            }

            out.println("0." + result.toString());
        } else {
            String base = fractional.substring(0, k);
            char roundDigit = fractional.charAt(k);
            char[] digits = base.toCharArray();

            if (roundDigit >= '5') {
                int pos = k - 1;
                while (pos >= 0) {
                    if (digits[pos] == '9') {
                        digits[pos] = '0';
                        pos--;
                    } else {
                        digits[pos]++;
                        break;
                    }
                }
                if (pos < 0) {
                    out.print("1.");
                    for (int i = 0; i < k; i++) {
                        out.print("0");
                    }

                    out.println();
                    out.flush();
                    out.close();
                    return;
                }
            }

            out.println("0." + new String(digits));
        }

        out.flush();
        out.close();
    }
}