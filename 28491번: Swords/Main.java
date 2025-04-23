import java.io.*;
import java.util.*;

public class Main {
    static class Sword {
        int a, b;
        Sword(int a, int b) { this.a = a; this.b = b; }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        Sword[] arr = new Sword[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[i] = new Sword(a, b);
        }

        Arrays.sort(arr, (s1, s2) -> {
            if (s1.a != s2.a) return Integer.compare(s2.a, s1.a);
            else return Integer.compare(s2.b, s1.b);
        });

        long usefulCount = 0;
        int maxB = -1;
        for (Sword s : arr) {
            if (s.b > maxB) {
                usefulCount++;
                maxB = s.b;
            }
        }

        System.out.println(usefulCount);
    }
}
