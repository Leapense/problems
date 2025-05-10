import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        String[] words = new String[N];
        int totalWordLength = 0;

        for (int i = 0; i < N; i++) {
            words[i] = br.readLine();
            totalWordLength += words[i].length();
        }

        int numGaps = N - 1;
        int totalUnderscoresToDistribute = M - totalWordLength;

        int baseUnderscoresPerGap = totalUnderscoresToDistribute / numGaps;

        int numGapsWithOneMoreUnderscore = totalUnderscoresToDistribute % numGaps;

        int[] underscoreCountsInGaps = new int[numGaps];
        for (int i = 0; i < numGaps; i++) {
            underscoreCountsInGaps[i] = baseUnderscoresPerGap;
        }

        for (int i = 0; i < numGaps; i++) {
            if (numGapsWithOneMoreUnderscore == 0) {
                break;
            }

            if (Character.isLowerCase(words[i + 1].charAt(0))) {
                underscoreCountsInGaps[i]++;
                numGapsWithOneMoreUnderscore--;
            }
        }

        for (int i = numGaps - 1; i >= 0; i--) {
            if (numGapsWithOneMoreUnderscore == 0) {
                break;
            }

            if (underscoreCountsInGaps[i] == baseUnderscoresPerGap) {
                underscoreCountsInGaps[i]++;
                numGapsWithOneMoreUnderscore--;
            }
        }

        StringBuilder resultBuilder = new StringBuilder();
        resultBuilder.append(words[0]);
        for (int i = 0; i < numGaps; i++) {
            for (int j = 0; j < underscoreCountsInGaps[i]; j++) {
                resultBuilder.append('_');
            }

            resultBuilder.append(words[i + 1]);
        }

        System.out.println(resultBuilder.toString());
    }
}