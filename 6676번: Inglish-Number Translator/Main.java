import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    private static final Map<String, Integer> WORD_TO_NUMBER = createWordToNumberMap();
    private static final Set<String> SCALE_WORDS = Set.of("hundred", "thousand", "million");

    private static Map<String, Integer> createWordToNumberMap() {
        Map<String, Integer> map = new HashMap<>();

        // 기본 숫자들
        String[] basicNumbers = {
                "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                "seventeen", "eighteen", "nineteen"
        };

        for (int i = 0; i < basicNumbers.length; i++) {
            map.put(basicNumbers[i], i);
        }

        // 십의 자리 숫자들
        String[] tens = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
        for (int i = 0; i < tens.length; i++) {
            map.put(tens[i], (i + 2) * 10);
        }

        // 단위들
        map.put("hundred", 100);
        map.put("thousand", 1000);
        map.put("million", 1000000);

        return Collections.unmodifiableMap(map);
    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
                BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out))) {

            EnglishNumberTranslator translator = new EnglishNumberTranslator();
            String line;

            while ((line = reader.readLine()) != null && !line.trim().isEmpty()) {
                int result = translator.translateToNumber(line.trim());
                writer.write(String.valueOf(result));
                writer.newLine();
            }
        }
    }

    static class EnglishNumberTranslator {

        public int translateToNumber(String englishNumber) {
            if (englishNumber == null || englishNumber.isEmpty()) {
                return 0;
            }

            List<String> tokens = tokenize(englishNumber);
            boolean isNegative = tokens.get(0).equals("negative");

            if (isNegative) {
                tokens = tokens.subList(1, tokens.size());
            }

            int result = parseTokens(tokens);
            return isNegative ? -result : result;
        }

        private List<String> tokenize(String input) {
            return Arrays.stream(input.toLowerCase().split("\\s+"))
                    .filter(token -> !token.isEmpty())
                    .collect(Collectors.toList());
        }

        private int parseTokens(List<String> tokens) {
            if (tokens.isEmpty()) {
                return 0;
            }

            if (tokens.size() == 1) {
                return WORD_TO_NUMBER.getOrDefault(tokens.get(0), 0);
            }

            return parseByScale(tokens);
        }

        private int parseByScale(List<String> tokens) {
            int result = 0;

            // million 단위 처리
            int millionIndex = findScaleIndex(tokens, "million");
            if (millionIndex != -1) {
                List<String> millionPart = tokens.subList(0, millionIndex);
                result += parseHundreds(millionPart) * 1_000_000;
                tokens = tokens.subList(millionIndex + 1, tokens.size());
            }

            // thousand 단위 처리
            int thousandIndex = findScaleIndex(tokens, "thousand");
            if (thousandIndex != -1) {
                List<String> thousandPart = tokens.subList(0, thousandIndex);
                result += parseHundreds(thousandPart) * 1_000;
                tokens = tokens.subList(thousandIndex + 1, tokens.size());
            }

            // 나머지 (hundreds 이하) 처리
            result += parseHundreds(tokens);

            return result;
        }

        private int parseHundreds(List<String> tokens) {
            if (tokens.isEmpty()) {
                return 0;
            }

            int result = 0;
            int hundredIndex = findScaleIndex(tokens, "hundred");

            if (hundredIndex != -1) {
                // hundred 앞의 숫자
                if (hundredIndex > 0) {
                    result += parseBasicNumber(tokens.subList(0, hundredIndex)) * 100;
                }
                // hundred 뒤의 숫자
                if (hundredIndex + 1 < tokens.size()) {
                    result += parseBasicNumber(tokens.subList(hundredIndex + 1, tokens.size()));
                }
            } else {
                result = parseBasicNumber(tokens);
            }

            return result;
        }

        private int parseBasicNumber(List<String> tokens) {
            if (tokens.isEmpty()) {
                return 0;
            }

            if (tokens.size() == 1) {
                return WORD_TO_NUMBER.getOrDefault(tokens.get(0), 0);
            }

            // 두 자리 수 처리 (예: twenty one)
            if (tokens.size() == 2) {
                int first = WORD_TO_NUMBER.getOrDefault(tokens.get(0), 0);
                int second = WORD_TO_NUMBER.getOrDefault(tokens.get(1), 0);

                // first가 십의 자리이고 second가 일의 자리인 경우
                if (first >= 20 && first <= 90 && second >= 1 && second <= 9) {
                    return first + second;
                }
            }

            // 기본적으로 첫 번째 토큰만 반환
            return WORD_TO_NUMBER.getOrDefault(tokens.get(0), 0);
        }

        private int findScaleIndex(List<String> tokens, String scale) {
            for (int i = 0; i < tokens.size(); i++) {
                if (tokens.get(i).equals(scale)) {
                    return i;
                }
            }
            return -1;
        }
    }
}