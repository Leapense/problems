import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static boolean canPlace(
        long moduleCount,
        long coreWidth,
        long coreHeight,
        long fieldWidth,
        long fieldHeight,
        long thickness
    ) {
        long widthWithLayer = coreWidth + (thickness << 1);
        long heightWithLayer = coreHeight + (thickness << 1);
        
        if (widthWithLayer <= 0 || heightWithLayer <= 0) {
            return false;
        }

        long horizontalFit = fieldWidth / widthWithLayer;
        long verticalFit = fieldHeight / heightWithLayer;

        if (horizontalFit >= 1 && verticalFit >= 1 && horizontalFit >= moduleCount / Math.max(verticalFit, 1L)) {
            if (horizontalFit * verticalFit >= moduleCount) {
                return true;
            }
        }

        long widthRotated = coreHeight + (thickness << 1);
        long heightRotated = coreWidth + (thickness << 1);

        horizontalFit = fieldWidth / widthRotated;
        verticalFit = fieldHeight / heightRotated;

        return horizontalFit >= 1 && verticalFit >= 1 && horizontalFit * verticalFit >= moduleCount;
    }

    public static void main(String[] args) throws Exception {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
            long moduleCount = Long.parseLong(tokenizer.nextToken());
            long coreWidth = Long.parseLong(tokenizer.nextToken());
            long coreHeight = Long.parseLong(tokenizer.nextToken());
            long fieldWidth = Long.parseLong(tokenizer.nextToken());
            long fieldHeight = Long.parseLong(tokenizer.nextToken());

            long low = 0;
            long high = Math.min(fieldWidth, fieldHeight);

            while (low < high) {
                long mid = (low + high + 1) >>> 1;
                if (canPlace(moduleCount, coreWidth, coreHeight, fieldWidth, fieldHeight, mid)) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }

            System.out.println(low);
        }
    }
}