import java.io.*;

public class Main
{
    public void run() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        if (line != null && !line.trim().isEmpty()) {
            long targetIndex = Long.parseLong(line);
            char result = solve(targetIndex);
            System.out.println(result);
        }
    }

    private char solve(long k) {
        long targetIndex = k;
        long stringLength = 1;
        long powerOf26 = 26;

        while (true) {
            long charsInBlock = stringLength * powerOf26;
            if (targetIndex < charsInBlock) {
                break;
            }

            targetIndex -= charsInBlock;
            stringLength++;
            powerOf26 *= 26;
        }

        long stringIndexInBlock = targetIndex / stringLength;
        long charIndexInString = targetIndex % stringLength;

        long rightShiftCount = stringLength - 1 - charIndexInString;

        for (int i = 0; i < rightShiftCount; i++) {
            stringIndexInBlock /= 26;
        }

        long charCode = stringIndexInBlock % 26;
        return (char) ('A' + charCode);
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}