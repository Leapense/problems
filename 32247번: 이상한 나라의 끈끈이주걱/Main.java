import java.io.*;
import java.util.*;

public class Main {
    static class Obstacle {
        int type;
        int h;
        Obstacle(int type, int h) {
            this.type = type;
            this.h = h;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        Obstacle[] obs = new Obstacle[N + 1];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            obs[x] = new Obstacle(c, h);
        }

        long L = 0;
        long U = 0;
        for (int i = 1; i <= N; i++) {
            L = L - 1;
            U = N - i;
            Obstacle ob = obs[i];
            if (ob != null) {
                if (ob.type == 0) {
                    long need = (long) ob.h + 1L;
                    if (L < need) L = need;
                } else {
                    long cap = (long) ob.h - 1L;
                    if (U > cap) U = cap;
                }
            }
            if (L > U) {
                System.out.println("adios");
                return;
            }
        }

        if (L <= 0 && 0 <= U) System.out.println("stay");
        else System.out.println("adios");
    }
}