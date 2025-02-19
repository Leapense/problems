import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int caseNo = 1;

        while (true) {
            if (!sc.hasNext())
                break;
            int n = sc.nextInt();

            if (n == 0)
                break;
            int[] xs = new int[n];
            int[] ys = new int[n];

            for (int i = 0; i < n; i++) {
                xs[i] = sc.nextInt();
                ys[i] = sc.nextInt();
            }

            Arrays.sort(xs);
            Arrays.sort(ys);

            int medianX = (n % 2 == 0) ? xs[n / 2 - 1] : xs[n / 2];
            int medianY = (n % 2 == 0) ? ys[n / 2 - 1] : ys[n / 2];

            long totalDistance = 0;
            for (int i = 0; i < n; i++) {
                totalDistance += Math.abs(xs[i] - medianX);
                totalDistance += Math.abs(ys[i] - medianY);
            }

            System.out.println("Case " + caseNo + ": (" + medianX + "," + medianY + ") " + totalDistance);
            caseNo++;
        }
        sc.close();
    }
}