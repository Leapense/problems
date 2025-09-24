import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        long H = Long.parseLong(st.nextToken());
        long W = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());
        long C = Long.parseLong(st.nextToken());
        long D = Long.parseLong(st.nextToken());

        if (C < 0 || D < 0 || C + D != H * W) {
            System.out.println("-1");
            return;
        }

        if (H > W + 1) {
            System.out.println("-1");
            return;
        } 

        long L = H * (H - 1) / 2;
        long U = H * W - L;
        if (D < L || D > U) {
            System.out.println("-1");
            return;
        }

        long R = D - L;
        long q = R / H;
        long r = R % H;

        StringBuilder out = new StringBuilder();
        for (int i = 1; i <= (int)H; i++) {
            long bi = (i - 1L) + q + (i > H - r ? 1 : 0);
            int nine = (int)bi;
            int width = (int)W;

            for (int j = 0; j < width; j++) {
                if (j > 0) out.append(' ');
                out.append(j < nine ? '9' : '1');
            }
            out.append('\n');
        }

        System.out.print(out.toString());
    }
}