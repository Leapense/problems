import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter    writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int t = Integer.parseInt(reader.readLine().trim());

        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            long c = Long.parseLong(st.nextToken());

            boolean possible = StoneService.isSolvable(a, b, c);
            writer.println(possible ? "Yes" : "No");
        }

        writer.flush();
    }
}

class StoneService {
    public static boolean isSolvable(long a, long b, long c) {
        long am = a % 3, bm = b % 3, cm = c % 3;
        return am == bm || am == cm || bm == cm;
    }
}
