import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int V = sc.nextInt();
        int Z = sc.nextInt();
        int T = sc.nextInt();

        sc.close();

        int barboraTime = 0;
        int totalWait = 0;

        for (int i = 1; i <= N; i++) {
            int tomasFinishTime = -T + i * V;
            if (tomasFinishTime > barboraTime) {
                totalWait += tomasFinishTime - barboraTime;
                barboraTime = tomasFinishTime;
            }
            barboraTime += Z;
        }

        System.out.println(totalWait);
    }
}