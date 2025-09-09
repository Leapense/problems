import java.io.*;
import java.util.*;

public class Main {
    static class Point {
        int r, c;
        Point(int r, int c) { this.r = r; this.c = c; }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int H1 = Integer.parseInt(st.nextToken());
        int W1 = Integer.parseInt(st.nextToken());
        List<Point> S = new ArrayList<>();
        for (int i = 0; i < H1; i++) {
            String line = br.readLine().trim();
            for (int j = 0; j < W1; j++) {
                if (line.charAt(j) == 'O') S.add(new Point(i, j));
            }
        }

        st = new StringTokenizer(br.readLine());
        int H2 = Integer.parseInt(st.nextToken());
        int W2 = Integer.parseInt(st.nextToken());
        List<Point> T = new ArrayList<>();
        for (int i = 0; i < H2; i++) {
            String line = br.readLine().trim();
            for (int j = 0; j < W2; j++) {
                if (line.charAt(j) == 'O') T.add(new Point(i, j));
            }
        }

        int N = S.size();
        if (N == 0) {
            System.out.println(0);
            return;
        }

        HashMap<Long, Integer> freq = new HashMap<>();
        int maxCount = 0;
        for (Point s : S) {
            for (Point t : T) {
                int dr = s.r - t.r;
                int dc = s.c - t.c;
                long key = pack(dr, dc);
                int f = freq.getOrDefault(key, 0) + 1;
                freq.put(key, f);
                if (f > maxCount) maxCount = f;
            }
        }

        int answer = N - maxCount;
        System.out.println(answer);
    }

    static long pack(int a, int b) {
        return (((long) a) << 32) ^ (b & 0xffffffffL);
    }
}