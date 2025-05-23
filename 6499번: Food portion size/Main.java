import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public final class Main {
    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            String line;
            while ((line = reader.readLine()) != null) {
                int n = Integer.parseInt(line.trim());
                if (n == 0)
                    break;

                StringTokenizer st = new StringTokenizer(reader.readLine());
                long weightWaste = Long.parseLong(st.nextToken());
                long weightTrips = Long.parseLong(st.nextToken());
                long[] consumption = new long[n];

                st = new StringTokenizer(reader.readLine());
                long maxConsumption = 0L;
                long totalConsumption = 0L;

                for (int i = 0; i < n; i++) {
                    consumption[i] = Long.parseLong(st.nextToken());
                    totalConsumption += consumption[i];
                    if (consumption[i] > maxConsumption) {
                        maxConsumption = consumption[i];
                    }
                }

                long minNum = maxConsumption;
                long minDen = 3L;

                BigInteger bestNum = null;
                BigInteger bestDen = BigInteger.ONE;

                for (long y : consumption) {
                    for (long k = 1; k <= 3; k++) {
                        if (3 * y < k * maxConsumption) {
                            continue;
                        }

                        long sNum = y;
                        long sDen = k;

                        long sumC = 0L;
                        boolean valid = true;

                        for (long yj : consumption) {
                            long mul = yj * sDen;
                            long c = mul / sNum + ((mul % sNum == 0) ? 0 : 1);
                            if (c > 3L) {
                                valid = false;
                                break;
                            }

                            sumC += c;
                        }

                        if (!valid) {
                            continue;
                        }

                        BigInteger bigSumC = BigInteger.valueOf(sumC);
                        BigInteger bigTotalY = BigInteger.valueOf(totalConsumption);
                        BigInteger bigSnum = BigInteger.valueOf(sNum);
                        BigInteger bigSden = BigInteger.valueOf(sDen);
                        BigInteger numPart1 = bigSumC.multiply(bigSnum).multiply(BigInteger.valueOf(weightWaste));
                        BigInteger numPart2 = bigSumC.multiply(BigInteger.valueOf(weightTrips))
                                .subtract(bigTotalY.multiply(BigInteger.valueOf(weightWaste)))
                                .multiply(bigSden);
                        BigInteger costNum = numPart1.add(numPart2);
                        BigInteger costDen = bigSden;

                        BigInteger gcd = costNum.gcd(costDen);
                        costNum = costNum.divide(gcd);
                        costDen = costDen.divide(gcd);

                        if (bestNum == null || costNum.multiply(bestDen).compareTo(bestNum.multiply(costDen)) < 0) {
                            bestNum = costNum;
                            bestDen = costDen;
                        }
                    }
                }

                if (bestDen.equals(BigInteger.ONE)) {
                    System.out.println(bestNum);
                } else {
                    System.out.println(bestNum + " / " + bestDen);
                }
            }
        }
    }
}