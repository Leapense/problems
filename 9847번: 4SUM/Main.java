import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main
{
    static class SumPair implements Comparable<SumPair> {
        private final long sum;
        private final int index1;
        private final int index2;

        public SumPair(long sum, int index1, int index2) {
            this.sum = sum;
            this.index1 = index1;
            this.index2 = index2;
        }

        public long getSum() {
            return sum;
        }

        public int getIndex1() {
            return index1;
        }

        public int getIndex2() {
            return index2;
        }

        @Override
        public int compareTo(SumPair other) {
            return Long.compare(this.sum, other.sum);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();

        long[] setA = new long[a];
        long[] setB = new long[b];
        long[] setC = new long[c];
        long[] setD = new long[d];

        for (int i = 0; i < a; i++) {
            setA[i] = scanner.nextLong();
        }
        for (int i = 0; i < b; i++) {
            setB[i] = scanner.nextLong();
        }
        for (int i = 0; i < c; i++) {
            setC[i] = scanner.nextLong();
        }
        for (int i = 0; i < d; i++) {
            setD[i] = scanner.nextLong();
        }

        List<SumPair> abSums = new ArrayList<>();
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                abSums.add(new SumPair(setA[i] + setB[j], i, j));
            }
        }

        List<SumPair> cdSums = new ArrayList<>();
        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < d; j++)
            {
                cdSums.add(new SumPair(setC[i] + setD[j], i, j));
            }
        }

        SumPair[] abArray = abSums.toArray(new SumPair[0]);
        SumPair[] cdArray = cdSums.toArray(new SumPair[0]);
        Arrays.sort(abArray);
        Arrays.sort(cdArray);

        int abIndex = 0;
        int cdIndex = cdArray.length - 1;
        long targetSum = 0;
        boolean found = false;
        int abFoundIndex1 = 0, abFoundIndex2 = 0, cdFoundIndex1 = 0, cdFoundIndex2 = 0;

        while (abIndex < abArray.length && cdIndex >= 0) {
            long currentSum = abArray[abIndex].getSum() + cdArray[cdIndex].getSum();
            if (currentSum == targetSum) {
                abFoundIndex1 = abArray[abIndex].getIndex1();
                abFoundIndex2 = abArray[abIndex].getIndex2();
                cdFoundIndex1 = cdArray[cdIndex].getIndex1();
                cdFoundIndex2 = cdArray[cdIndex].getIndex2();
                found = true;
                break;
            } else if (currentSum < targetSum) {
                abIndex++;
            } else {
                cdIndex--;
            }
        }

        if (found) {
            System.out.printf("%d %d %d %d%n", setA[abFoundIndex1], setB[abFoundIndex2], setC[cdFoundIndex1], setD[cdFoundIndex2]);
        }

        scanner.close();
    }
}