import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public final class Main {
    private static final int TOPPING_COUNT = 16;
    private static final int MAX_MASK = 1 << TOPPING_COUNT;

    private Main() {

    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String line;
            List<Clause> clauses = new ArrayList<>();
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty())
                    continue;
                if (line.equals(".")) {
                    solveAndPrint(clauses);
                    clauses.clear();
                    continue;
                }

                clauses.add(parseClause(line));
            }

            if (!clauses.isEmpty()) {
                solveAndPrint(clauses);
            }
        }
    }

    private static final class Clause {
        final int positiveMask;
        final int negativeMask;

        Clause(int pos, int neg) {
            this.positiveMask = pos;
            this.negativeMask = neg;
        }

        boolean isSatisfied(int pizzaMask) {
            return ((pizzaMask & positiveMask) != 0) || (((~pizzaMask) & negativeMask) != 0);
        }
    }

    private static Clause parseClause(String raw) {
        int pos = 0;
        int neg = 0;
        for (int i = 0; i < raw.length(); i++) {
            char ch = raw.charAt(i);
            if (ch == '+' || ch == '-') {
                char topping = raw.charAt(++i);
                int bit = topping - 'A';
                if (bit < 0 || bit >= TOPPING_COUNT) {
                    throw new IllegalArgumentException("Invalid topping: " + topping);
                }

                if (ch == '+') {
                    pos |= 1 << bit;
                } else {
                    neg |= 1 << bit;
                }
            }
        }

        return new Clause(pos, neg);
    }

    private static void solveAndPrint(List<Clause> clauses) {
        int winningMask = findSatisfyingPizza(clauses);
        if (winningMask == -1) {
            System.out.println("No pizza can satisfy these requests.");
        } else {
            System.out.print("Toppings: ");
            System.out.println(maskToString(winningMask));
        }
    }

    private static int findSatisfyingPizza(List<Clause> clauses) {
        outer: for (int pizza = 0; pizza < MAX_MASK; pizza++) {
            for (Clause clause : clauses) {
                if (!clause.isSatisfied(pizza)) {
                    continue outer;
                }
            }

            return pizza;
        }

        return -1;
    }

    private static String maskToString(int mask) {
        StringBuilder sb = new StringBuilder();
        for (int bit = 0; bit < TOPPING_COUNT; bit++) {
            if ((mask & (1 << bit)) != 0) {
                sb.append((char) ('A' + bit));
            }
        }

        return sb.toString();
    }
}