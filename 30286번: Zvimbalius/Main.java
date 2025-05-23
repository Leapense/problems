import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine().trim());

        if (N % 2 != 0) {
            System.out.println("NEGALIMA");
            return;
        }

        String commands = br.readLine().trim();

        int countS = 0, countP = 0, countR = 0, countV = 0;
        for (int i = 0; i < N; i++) {
            char c = commands.charAt(i);
            if (c == 'S')
                countS++;
            else if (c == 'P')
                countP++;
            else if (c == 'R')
                countR++;
            else if (c == 'V')
                countV++;
        }

        int maxKeep = 0;

        for (int v = 0; v <= N; v += 2) {
            int h = N - v;

            int verticalKeep = Math.min(countS, v / 2) + Math.min(countP, v / 2);
            int horizontalKeep = Math.min(countR, h / 2) + Math.min(countV, h / 2);
            int totalKeep = verticalKeep + horizontalKeep;
            maxKeep = Math.max(maxKeep, totalKeep);
        }

        int result = N - maxKeep;
        System.out.println(result);
    }
}