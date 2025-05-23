import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int b = 0, w = 0;
        for (char c : s.toCharArray()) {
            if (c == 'B') b++;
            else w++;
        }

        System.out.println(b == w ? 1 : 0);
    }
}