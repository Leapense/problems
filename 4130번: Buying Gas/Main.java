import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int d = sc.nextInt();
        int maxDistance = n * 10;
        int[][] stations = new int[m][2];
        for (int i = 0; i < m; i++) {
            stations[i][0] = sc.nextInt();
            stations[i][1] = sc.nextInt();
        }

        Arrays.sort(stations, (a, b) -> Integer.compare(a[0], b[0]));
        int count = 0;
        int currentRange = maxDistance;
        int i = 0;
        while (currentRange < d) {
            int best = -1;
            while (i < m && stations[i][0] <= currentRange) {
                best = i;
                i++;
            }
            if (best == -1) {
                System.out.println(-1);
                return;
            }

            currentRange = stations[best][0] + maxDistance;
            count++;
        }

        System.out.println(count);
    }
}