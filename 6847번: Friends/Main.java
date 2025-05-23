import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Integer, Integer> friendMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            friendMap.put(a, b);
        }
        while (true) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (a == 0 && b == 0)
                break;
            int steps = 0;
            int curr = a;
            boolean found = false;
            while (true) {
                curr = friendMap.get(curr);
                if (curr == b) {
                    System.out.println("Yes " + steps);
                    found = true;
                    break;
                }
                if (curr == a)
                    break;
                steps++;
            }
            if (!found)
                System.out.println("No");
        }
    }
}
