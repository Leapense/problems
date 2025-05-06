import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] polygon = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            polygon[i] = Integer.parseInt(st.nextToken());
        }

        int[] testSeq = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            testSeq[i] = Integer.parseInt(st.nextToken());
        }

        System.out.println(canAppearAfterDihedralActions(polygon, testSeq) ? 1 : 0);
    }

    private static boolean canAppearAfterDihedralActions(int[] polygon, int[] testSeq) {
        int n = polygon.length;
        int m = testSeq.length;

        if (m > n)
            return false;

        // Check all rotations
        for (int start = 0; start < n; start++) {
            boolean found = true;
            for (int i = 0; i < m; i++) {
                if (polygon[(start + i) % n] != testSeq[i]) {
                    found = false;
                    break;
                }
            }
            if (found)
                return true;
        }

        // Check all reflections followed by rotations
        for (int start = 0; start < n; start++) {
            boolean found = true;
            for (int i = 0; i < m; i++) {
                if (polygon[(start - i + n) % n] != testSeq[i]) {
                    found = false;
                    break;
                }
            }
            if (found)
                return true;
        }

        return false;
    }
}