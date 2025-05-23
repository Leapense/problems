import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt();
        sc.close();
        String[] words = { "WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY" };
        List<String> result = new ArrayList<>();
        int index = 0;

        while (index < words.length) {
            int count = words[index].length();
            int last = index + 1;
            while (last < words.length) {
                if (count + 1 + words[last].length() > w)
                    break;
                count += 1 + words[last].length();
                last++;
            }

            StringBuilder line = new StringBuilder();
            int numWords = last - index;
            if (numWords == 1) {
                line.append(words[index]);
                for (int i = line.length(); i < w; i++)
                    line.append(".");
            } else {
                int totalSpaces = w;
                for (int i = index; i < last; i++)
                    totalSpaces -= words[i].length();
                int spaceBetween = totalSpaces / (numWords - 1);
                int extra = totalSpaces % (numWords - 1);
                for (int i = index; i < last; i++) {
                    line.append(words[i]);
                    if (i < last - 1) {
                        int spaces = spaceBetween + (i - index < extra ? 1 : 0);
                        for (int j = 0; j < spaces; j++)
                            line.append(".");
                    }
                }
            }

            result.add(line.toString());
            index = last;
        }

        for (String s : result) {
            System.out.println(s);
        }
    }
}