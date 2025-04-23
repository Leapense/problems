import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out, true);

        long n = Long.parseLong(in.readLine().trim());
        long rMin = 1, rMax = n;
        long cMin = 1, cMax = n;

        while (true) {
            long rMid = (rMin + rMax) >>> 1;
            long cMid = (cMin + cMax) >>> 1;

            out.println(rMid + " " + cMid);

            String resp = in.readLine().trim();
            if (resp.equals("OK")) {
                break;
            }

            if (resp.contains("N")) {
                rMax = rMid - 1;
            } else if (resp.contains("S")) {
                rMin = rMid + 1;
            }

            if (resp.contains("W")) {
                cMax = cMid - 1;
            } else if (resp.contains("E")) {
                cMin = cMid + 1;
            }
        }
    }
}