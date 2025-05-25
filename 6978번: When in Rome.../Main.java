import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCount = Integer.parseInt(sc.nextLine().trim());
        RomanConverter converter = new RomanConverter();

        for (int i = 0; i < testCount; i++) {
            String line = sc.nextLine().trim();
            String[] parts = line.split("[+=]");
            String leftRoman = parts[0];
            String rightRoman = parts[1];

            int sum = converter.toInteger(leftRoman) + converter.toInteger(rightRoman);
            String result = (sum > 1000) ? "CONCORDIA CUM VERITATE" : converter.toRoman(sum);

            System.out.printf("%s+%s=%s%n", leftRoman, rightRoman, result);

            if (i < testCount - 1) {
                System.out.println();
            }
        }

        sc.close();
    }
}

class RomanConverter {
    private static final LinkedHashMap<String, Integer> ROMAN_TO_VALUE = new LinkedHashMap<>();
    private static final List<Map.Entry<String, Integer>> VALUE_TO_ROMAN = new ArrayList<>();

    static {
        ROMAN_TO_VALUE.put("M", 1000);
        ROMAN_TO_VALUE.put("D", 500);
        ROMAN_TO_VALUE.put("C", 100);
        ROMAN_TO_VALUE.put("L", 50);
        ROMAN_TO_VALUE.put("X", 10);
        ROMAN_TO_VALUE.put("V", 5);
        ROMAN_TO_VALUE.put("I", 1);

        VALUE_TO_ROMAN.add(Map.entry("M", 1000));
        VALUE_TO_ROMAN.add(Map.entry("CM", 900));
        VALUE_TO_ROMAN.add(Map.entry("D", 500));
        VALUE_TO_ROMAN.add(Map.entry("CD", 400));
        VALUE_TO_ROMAN.add(Map.entry("C", 100));
        VALUE_TO_ROMAN.add(Map.entry("XC", 90));
        VALUE_TO_ROMAN.add(Map.entry("L", 50));
        VALUE_TO_ROMAN.add(Map.entry("XL", 40));
        VALUE_TO_ROMAN.add(Map.entry("X", 10));
        VALUE_TO_ROMAN.add(Map.entry("IX", 9));
        VALUE_TO_ROMAN.add(Map.entry("V", 5));
        VALUE_TO_ROMAN.add(Map.entry("IV", 4));
        VALUE_TO_ROMAN.add(Map.entry("I", 1));
    }

    public int toInteger(String roman) {
        int result = 0;

        for (int i = 0; i < roman.length(); i++) {
            int value = ROMAN_TO_VALUE.get(roman.substring(i, i + 1));
            boolean subtract = (i + 1 < roman.length())
                    && ROMAN_TO_VALUE.get(roman.substring(i + 1, i + 2)) > value;

            result += subtract ? -value : value;
        }

        return result;
    }

    public String toRoman(int number) {
        StringBuilder builder = new StringBuilder();

        for (Map.Entry<String, Integer> entry : VALUE_TO_ROMAN) {
            int count = number / entry.getValue();
            number %= entry.getValue();

            builder.append(entry.getKey().repeat(count));
        }

        return builder.toString();
    }
}