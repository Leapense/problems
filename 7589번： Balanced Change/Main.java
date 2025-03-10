import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class Main {
    static int[] coinValues = { 200, 100, 50, 20, 10 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        int problemCount = 1;
        while ((line = br.readLine()) != null) {
            if (line.trim().isEmpty())
                continue;
            StringTokenizer st = new StringTokenizer(line);
            int[] available = new int[5];
            for (int i = 0; i < 5; i++) {
                available[i] = Integer.parseInt(st.nextToken());
            }
            String moneyStr = st.nextToken();
            if (available[0] == 0 && available[1] == 0 && available[2] == 0 && available[3] == 0 && available[4] == 0
                    && moneyStr.equals("$0.00"))
                break;
            int target = convertToCents(moneyStr);
            int bestImbalance = Integer.MAX_VALUE;
            int[] bestCombo = null;
            for (int a = 0; a <= available[0] && a * coinValues[0] <= target; a++) {
                for (int b = 0; b <= available[1] && a * coinValues[0] + b * coinValues[1] <= target; b++) {
                    for (int c = 0; c <= available[2]
                            && a * coinValues[0] + b * coinValues[1] + c * coinValues[2] <= target; c++) {
                        for (int d = 0; d <= available[3] && a * coinValues[0] + b * coinValues[1] + c * coinValues[2]
                                + d * coinValues[3] <= target; d++) {
                            for (int e = 0; e <= available[4]; e++) {
                                int sum = a * coinValues[0] + b * coinValues[1] + c * coinValues[2] + d * coinValues[3]
                                        + e * coinValues[4];
                                if (sum != target)
                                    continue;
                                int[] remaining = new int[5];
                                remaining[0] = available[0] - a;
                                remaining[1] = available[1] - b;
                                remaining[2] = available[2] - c;
                                remaining[3] = available[3] - d;
                                remaining[4] = available[4] - e;
                                int min = Integer.MAX_VALUE;
                                for (int r : remaining)
                                    if (r < min)
                                        min = r;
                                int imbalance = 0;
                                for (int r : remaining)
                                    imbalance += (r - min) * (r - min);
                                if (imbalance < bestImbalance) {
                                    bestImbalance = imbalance;
                                    bestCombo = new int[] { a, b, c, d, e };
                                } else if (imbalance == bestImbalance && bestCombo != null) {
                                    if (compareCombo(new int[] { a, b, c, d, e }, bestCombo) > 0) {
                                        bestCombo = new int[] { a, b, c, d, e };
                                    }
                                }
                            }
                        }
                    }
                }
            }
            StringBuilder sb = new StringBuilder();
            sb.append("Problem #").append(problemCount).append(": ");
            if (bestCombo == null) {
                sb.append("not possible");
            } else {
                String[] names = { "$2", "$1", "50c", "20c", "10c" };
                ArrayList<String> parts = new ArrayList<>();
                for (int i = 0; i < 5; i++) {
                    if (bestCombo[i] > 0)
                        parts.add(bestCombo[i] + " " + names[i]);
                }
                if (parts.size() == 1) {
                    sb.append(parts.get(0)).append(" coin(s)");
                } else if (parts.size() > 1) {
                    for (int i = 0; i < parts.size(); i++) {
                        if (i == parts.size() - 1) {
                            sb.append("and ").append(parts.get(i)).append(" coin(s)");
                        } else {
                            sb.append(parts.get(i));
                            if (parts.size() == 2) {
                                sb.append(" ");
                            } else {
                                if (i < parts.size() - 2)
                                    sb.append(", ");
                                else
                                    sb.append(" ");
                            }
                        }
                    }
                }
            }
            System.out.println(sb.toString());
            problemCount++;
        }
    }

    static int convertToCents(String money) {
        money = money.replace("$", "");
        String[] parts = money.split("\\.");
        int dollars = Integer.parseInt(parts[0]);
        int cents = Integer.parseInt(parts[1]);
        return dollars * 100 + cents;
    }

    static int compareCombo(int[] c1, int[] c2) {
        for (int i = 0; i < 5; i++) {
            if (c1[i] != c2[i])
                return c1[i] - c2[i];
        }
        return 0;
    }
}
