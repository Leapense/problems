import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int waitingForK = 0;
        int waitingForP = 0;
        int frogs = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == 'K') {
                if (waitingForK > 0) {
                    waitingForK--;
                    waitingForP++;
                } else {
                    frogs++;
                    waitingForP++;
                }
            } else if (c == 'P') {
                if (waitingForP > 0) {
                    waitingForP--;
                    waitingForK++;
                } else {
                    frogs++;
                    waitingForK++;
                }
            }
        }

        System.out.println(frogs);
    }
}