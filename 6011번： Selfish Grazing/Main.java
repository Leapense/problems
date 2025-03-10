import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Cow[] cows = new Cow[N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            cows[i] = new Cow(s, e);
        }

        Arrays.sort(cows, new Comparator<Cow>() {
            public int compare(Cow a, Cow b) {
                return a.e - b.e;
            }
        });

        int count = 0;
        int lastEnd = 0;

        for (int i = 0; i < N; i++) {
            if (cows[i].s >= lastEnd) {
                count++;
                lastEnd = cows[i].e;
            }
        }

        System.out.println(count);
    }
}

class Cow {
    int s, e;

    Cow(int s, int e) {
        this.s = s;
        this.e = e;
    }
}