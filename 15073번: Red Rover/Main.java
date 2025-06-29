import java.util.Scanner;

public final class Main {
    private Main() {

    }

    private static int calculateEncodedLength(String route, String macro) {
        int routeLength = route.length();
        int macroLength = macro.length();

        int compressedStringLength = 0;
        int index = 0;

        while (index < routeLength) {
            boolean isMacroMatch = (index + macroLength <= routeLength) && route.substring(index, index + macroLength).equals(macro);

            if (isMacroMatch) {
                compressedStringLength++;
                index += macroLength;
            } else {
                compressedStringLength++;
                index++;
            }
        }

        return compressedStringLength + macroLength;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String route = sc.nextLine();
        sc.close();

        int n = route.length();
        int minLength = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                String macro = route.substring(i, j);
                if (macro.isEmpty()) {
                    continue;
                }

                int currentLength = calculateEncodedLength(route, macro);
                minLength = Math.min(minLength, currentLength);
            }
        }
        System.out.println(minLength);
    }
}