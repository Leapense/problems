import java.io.*;
import java.util.*;

public class Main {
    static boolean isConsonant(char c) {
        if (!Character.isLetter(c))
            return false;
        c = Character.toLowerCase(c);
        return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y');
    }

    static boolean hasMoreThanKConsecutive(String s, int k) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isConsonant(s.charAt(i))) {
                count++;
                if (count > k)
                    return true;
            } else {
                count = 0;
            }
        }
        return false;
    }

    static boolean qualifiesWord(String word) {
        return hasMoreThanKConsecutive(word, 4);
    }

    static boolean qualifiesLineForRule2(String line) {
        String[] words = line.split("\\s+");
        for (String word : words) {
            if (qualifiesWord(word))
                return true;
        }
        return false;
    }

    static class Entry {
        String line;
        boolean rule2;

        Entry(String line, boolean rule2) {
            this.line = line;
            this.rule2 = rule2;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        LinkedList<Entry> history = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            boolean accepted = true;
            if (hasMoreThanKConsecutive(line, 5))
                accepted = false;
            boolean currentRule2 = qualifiesLineForRule2(line);
            if (currentRule2 && accepted) {
                int count = 0;
                for (Entry e : history) {
                    if (e.rule2)
                        count++;
                }
                if (count > 2)
                    accepted = false;
            }
            if (accepted) {
                int dup = 0;
                for (Entry e : history) {
                    if (e.line.equals(line))
                        dup++;
                }
                if (dup > 1)
                    accepted = false;
            }
            System.out.println(accepted ? "y" : "n");
            history.add(new Entry(line, currentRule2));
            if (history.size() > 10)
                history.removeFirst();
        }
    }
}
