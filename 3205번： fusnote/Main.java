import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int F = sc.nextInt();
        int[] footnotes = new int[N + 1];
        for (int i = 0; i < F; i++) {
            int X = sc.nextInt();
            int Y = sc.nextInt();
            footnotes[X] += Y;
        }
        int pages = 0;
        int currentMain = 0;
        int reserved = 0;
        for (int i = 1; i <= N; i++) {
            int required = 1 + footnotes[i];
            if (currentMain + reserved + required <= K) {
                currentMain++;
                reserved += footnotes[i];
            } else {
                pages++;
                currentMain = 1;
                reserved = footnotes[i];
            }
        }
        if (currentMain + reserved > 0)
            pages++;
        System.out.println(pages);
    }
}
