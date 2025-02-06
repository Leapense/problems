import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int N = Integer.parseInt(br.readLine().trim());

        ArrayList<String> normalRecords = new ArrayList<>();
        ArrayList<String> bojRecords = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            String record = br.readLine();
            if (record.startsWith("boj.kr/")) {
                bojRecords.add(record);
            } else {
                normalRecords.add(record);
            }
        }

        Collections.sort(normalRecords, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                if (s1.length() != s2.length()) {
                    return s1.length() - s2.length();
                }

                return s1.compareTo(s2);
            }
        });

        Collections.sort(bojRecords, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                int num1 = Integer.parseInt(s1.substring(6));
                int num2 = Integer.parseInt(s2.substring(6));
                return num1 - num2;
            }
        });

        for (String record : normalRecords) {
            out.println(record);
        }
        for (String record : bojRecords) {
            out.println(record);
        }

        out.flush();
        out.close();
    }
}