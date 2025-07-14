import java.util.Scanner;

public class Main
{
    private static final int INF = Integer.MAX_VALUE / 2;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int segmentCount = sc.nextInt();
        String[] types = new String[segmentCount];
        int[] lower = new int[segmentCount];
        int[] upper = new int[segmentCount];

        for (int i = 0; i < segmentCount; i++) {
            types[i] = sc.next();
            lower[i] = sc.nextInt();
            upper[i] = sc.nextInt();
        }

        int initialLow = 0;
        int initialHigh = INF;
        for (int i = segmentCount - 1; i >= 0; i--) {
            String type = types[i];
            int min = lower[i];
            int max = upper[i];
            if ("none".equals(type)) {
                initialLow = Math.max(initialLow, min);
                initialHigh = Math.min(initialHigh, max);
            } else if ("on".equals(type)) {
                initialLow = Math.max(0, initialLow - max);
                initialHigh = Math.max(0, initialHigh - min);
            } else {
                initialLow += min;
                initialHigh += max;
            }
        }

        System.out.println(initialLow + " " + initialHigh);
        int finalLow = initialLow;
        int finalHigh = initialHigh;

        for (int i = 0; i < segmentCount; i++) {
            String type = types[i];
            int min = lower[i];
            int max = upper[i];
            if ("none".equals(type)) {
                finalLow = Math.max(finalLow, min);
                finalHigh = Math.min(finalHigh, max);
            } else if ("on".equals(type)) {
                finalLow += min;
                finalHigh += max;
            } else {
                finalLow = Math.max(0, finalLow - max);
                finalHigh = Math.max(0, finalHigh - min);
            }
        }

        System.out.println(finalLow + " " + finalHigh);
    }
}