import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int d = sc.nextInt();

        int[] pitches = new int[n];
        for (int i = 0; i < n; i++) {
            pitches[i] = sc.nextInt();
        }

        Arrays.sort(pitches);

        int recordings = 0;
        int i = 0;

        while (i < n) {
            int startPitch = pitches[i];
            int limit = startPitch + d;

            while (i < n && pitches[i] <= limit) {
                i++;
            }
            recordings++;
        }

        System.out.println(recordings);
        sc.close();
    }
}