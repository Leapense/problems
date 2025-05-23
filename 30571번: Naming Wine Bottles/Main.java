import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());

        Map<String, String> nameMap = new HashMap<>();
        int counter = 0;

        StringBuilder output = new StringBuilder();
        for (int i = 0; i < n; i++) {
            String line = br.readLine().trim();
            String volumeStr = line.substring(0, line.length() - 1);

            BigDecimal volume = new BigDecimal(volumeStr).stripTrailingZeros();
            String key = volume.toPlainString();

            if (!nameMap.containsKey(key)) {
                String generatedName = generateName(counter);
                nameMap.put(key, generatedName);
                counter++;
            }

            output.append(nameMap.get(key)).append("\n");
        }

        System.out.println(output);
    }

    private static String generateName(int num) {
        StringBuilder sb = new StringBuilder();
        do {
            char c = (char) ('a' + (num % 26));
            sb.append(c);
            num /= 26;
        } while (num > 0);

        return sb.reverse().toString();
    }
}