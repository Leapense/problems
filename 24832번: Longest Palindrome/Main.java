import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());

        int numStrings = Integer.parseInt(st.nextToken());
        int stringLength = Integer.parseInt(st.nextToken());

        List<String> allStrings = new ArrayList<>(numStrings);
        for (int i = 0; i < numStrings; i++) {
            allStrings.add(reader.readLine());
        }

        solve(numStrings, allStrings);
    }

    private static void solve(int n, List<String> allStrings) {
        StringBuilder leftPart = new StringBuilder();
        String centerPart = "";
        boolean[] used = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (used[j]) {
                    continue;
                }
                String s1 = allStrings.get(i);
                String s2 = allStrings.get(j);
                String reversedS1 = new StringBuilder(s1).reverse().toString();

                if (reversedS1.equals(s2)) {
                    leftPart.append(s1);
                    used[i] = true;
                    used[j] = true;
                    break;
                }
            }
        }

        int bestPalindromeScore = -1;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                String currentString = allStrings.get(i);
                String reversedString = new StringBuilder(currentString).reverse().toString();
                if (currentString.equals(reversedString)) {
                    centerPart = currentString;
                    break;
                }
            }
        }

        StringBuilder rightPart = new StringBuilder(leftPart).reverse();
        String result = leftPart.toString() + centerPart + rightPart.toString();
        System.out.println(result.length());
        System.out.println(result);
    }
}