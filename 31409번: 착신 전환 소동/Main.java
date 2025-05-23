import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] a = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            a[i] = sc.nextInt();
        }

        int[] b = new int[N + 1];
        int changes = 0;

        int candidate = -1;
        for (int i = 1; i <= N; i++) {
            if (a[i] != i) {
                candidate = i;
                break;
            }
        }

        if (candidate != -1) {
            for (int i = 1; i <= N; i++) {
                if (a[i] == i) {
                    b[i] = candidate;
                    changes++;
                } else {
                    b[i] = a[i];
                }
            }
        } else {
            for (int i = 1; i < N; i++) {
                b[i] = i + 1;
            }
            b[N] = 1;
            changes = N;
        }

        System.out.println(changes);
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            sb.append(b[i]).append(" ");
        }

        System.out.println(sb.toString().trim());

        sc.close();
    }
}