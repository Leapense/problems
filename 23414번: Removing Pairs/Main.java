import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String source = br.readLine();
        String target = br.readLine();

        int sourceIdx = source.length() - 1;
        int targetIdx = target.length() - 1;
        int pending = 0;

        char[] src = source.toCharArray();
        char[] tgt = target.toCharArray();

        while (targetIdx >= 0) {
            if (pending > 0) {
                pending--;
                targetIdx--;
            } else if (sourceIdx >= 0 && tgt[targetIdx] == src[sourceIdx]) {
                targetIdx--;
                sourceIdx--;
            } else {
                pending++;
                targetIdx--;
            }
        }
        if (sourceIdx < 0 && pending == 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}