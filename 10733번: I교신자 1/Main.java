import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Scanner;

final class StackTuple {
    private final List<BigInteger> values;
    private final int precomputedHashCode;

    public StackTuple(List<BigInteger> list) {
        this.values = List.copyOf(list);
        this.precomputedHashCode = this.values.hashCode();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }

        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        StackTuple that = (StackTuple) o;
        return this.values.equals(that.values);
    }

    @Override
    public int hashCode() {
        return this.precomputedHashCode;
    }

    public int size() {
        return values.size();
    }

    public BigInteger get(int index) {
        return values.get(index);
    }
}

final class MemoKey {
    private final int remA;
    private final int remB;
    private final int remC;
    private final StackTuple stackTuple;
    private final int precomputedHashCode;

    public MemoKey(int remA, int remB, int remC, StackTuple stackTuple) {
        this.remA = remA;
        this.remB = remB;
        this.remC = remC;
        this.stackTuple = stackTuple;
        this.precomputedHashCode = Objects.hash(remA, remB, remC, stackTuple);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }

        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        MemoKey memoKey = (MemoKey) o;
        return remA == memoKey.remA && remB == memoKey.remB && remC == memoKey.remC && stackTuple.equals(memoKey.stackTuple);
    }

    @Override
    public int hashCode() {
        return this.precomputedHashCode;
    }
}

public class Main {
    private static final long MOD = 1_000_000_007L;
    private static final BigInteger BIG_INT_MOD = BigInteger.valueOf(MOD);
    private Map<MemoKey, long[]> memo;
    private BigInteger iValue;
    private int kValue;

    public Main() {
        this.memo = new HashMap<>();
    }

    public long[] solve(int remA, int remB, int remC, List<BigInteger> currentStackInternal) {
        if (remA == 0 && remB == 0 && remC == 0) {
            long[] baseRes = new long[this.kValue];
            StackTuple finalStackTuple = new StackTuple(currentStackInternal);
            for (int i = 0; i < this.kValue; i++) {
                if (i < finalStackTuple.size()) {
                    baseRes[i] = finalStackTuple.get(finalStackTuple.size() - 1 - i).mod(BIG_INT_MOD).longValue();
                } else {
                    baseRes[i] = 0;
                }
            }

            return baseRes;
        }

        StackTuple currentStackTuple = new StackTuple(currentStackInternal);
        MemoKey key = new MemoKey(remA, remB, remC, currentStackTuple);

        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        long[] ans = new long[this.kValue];

        if (remA > 0) {
            List<BigInteger> stackAfterI = new ArrayList<>(currentStackInternal);
            stackAfterI.add(this.iValue);
            long[] resFromI = solve(remA - 1, remB, remC, stackAfterI);
            accumulateResults(ans, resFromI);
        }

        if (remB > 0 && currentStackTuple.size() >= 2) {
            List<BigInteger> stackAfterPlus = new ArrayList<>(currentStackInternal);
            BigInteger val1 = stackAfterPlus.remove(stackAfterPlus.size() - 1);
            BigInteger val2 = stackAfterPlus.remove(stackAfterPlus.size() - 1);
            stackAfterPlus.add(val1.add(val2));
            long[] resFromPlus = solve(remA, remB - 1, remC, stackAfterPlus);
            accumulateResults(ans, resFromPlus);
        }

        if (remC > 0 && currentStackTuple.size() >= 2) {
            List<BigInteger> stackAfterMultiply = new ArrayList<>(currentStackInternal);
            BigInteger val1 = stackAfterMultiply.remove(stackAfterMultiply.size() - 1);
            BigInteger val2 = stackAfterMultiply.remove(stackAfterMultiply.size() - 1);
            stackAfterMultiply.add(val1.multiply(val2));
            long[] resFromMultiply = solve(remA, remB, remC - 1, stackAfterMultiply);
            accumulateResults(ans, resFromMultiply);
        }

        memo.put(key, ans);
        return ans;
    }

    private void accumulateResults(long[] mainAns, long[] subResult) {
        for (int i = 0; i < this.kValue; i++) {
            mainAns[i] = (mainAns[i] + subResult[i]) % MOD;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long i = scanner.nextLong();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int k = scanner.nextInt();

        Main solver = new Main();
        solver.iValue = BigInteger.valueOf(i);
        solver.kValue = k;
        
        long[] results = solver.solve(a, b, c, new ArrayList<>());

        for (int j = 0; j < k; j++) {
            System.out.println(results[j]);
        }

        scanner.close();
    }
}