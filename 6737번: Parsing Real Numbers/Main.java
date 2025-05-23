import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = Integer.parseInt(sc.nextLine());
        Pattern pattern = Pattern.compile("^\\s*[+-]?(\\d+(\\.\\d+)?)([eE][+-]?\\d+)?\\s*$");

        for (int i = 0; i < T; i++) {
            String line = sc.nextLine();
            Matcher matcher = pattern.matcher(line);
            System.out.println(matcher.matches() ? "LEGAL" : "ILLEGAL");
        }

        sc.close();
    }
}