import java.util.Scanner;

public class Main {
    static class Throw {
        int i, d, count, length;

        Throw(int i, int d, int count, int length) {
            this.i = i;
            this.d = d;
            this.count = count;
            this.length = length;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            String map = sc.nextLine();
            if (map.equals("END"))
                break;
            int n = map.length();
            Throw best = new Throw(0, 1, -1, -1);
            for (int i = 0; i < n; i++) {
                for (int d = 1; d <= n; d++) {
                    int pos = i;
                    int count = 0;
                    int length = pos;
                    while (pos < n) {
                        if (map.charAt(pos) == '.') {
                            count++;
                            length = pos;
                        } else {
                            length = pos;
                            break;
                        }
                        pos += d;
                    }
                    if (pos >= n)
                        length = pos - d;
                    Throw current = new Throw(i, d, count, length);
                    if (isBetter(current, best))
                        best = current;
                }
            }
            System.out.println(best.i + " " + best.d);
        }
        sc.close();
    }

    static boolean isBetter(Throw a, Throw b) {
        if (a.count != b.count)
            return a.count > b.count;
        if (a.length != b.length)
            return a.length > b.length;
        if (a.i != b.i)
            return a.i > b.i;
        return a.d < b.d;
    }
}