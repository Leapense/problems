import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        Map<Character, int[]> pos = new HashMap<>();
        String row1 = "qwertyuiop";
        String row2 = "asdfghjkl";
        String row3 = "zxcvbnm";

        for (int i = 0; i < row1.length(); i++) {
            pos.put(row1.charAt(i), new int[] { 0, i });
        }
        for (int i = 0; i < row2.length(); i++) {
            pos.put(row2.charAt(i), new int[] { 1, i });
        }
        for (int i = 0; i < row3.length(); i++) {
            pos.put(row3.charAt(i), new int[] { 2, i });
        }

        while (t-- > 0) {
            String input = sc.next();
            int l = sc.nextInt();
            List<WordDistance> list = new ArrayList<>();
            for (int i = 0; i < l; i++) {
                String word = sc.next();
                int distance = 0;
                for (int j = 0; j < word.length(); j++) {
                    int[] p1 = pos.get(input.charAt(j));
                    int[] p2 = pos.get(word.charAt(j));
                    distance += Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
                }
                list.add(new WordDistance(word, distance));
            }

            Collections.sort(list);
            for (WordDistance wd : list) {
                System.out.println(wd.word + " " + wd.distance);
            }
        }
        sc.close();
    }
}

class WordDistance implements Comparable<WordDistance> {
    String word;
    int distance;

    WordDistance(String word, int distance) {
        this.word = word;
        this.distance = distance;
    }

    public int compareTo(WordDistance other) {
        if (this.distance == other.distance) {
            return this.word.compareTo(other.word);
        }

        return this.distance - other.distance;
    }
}