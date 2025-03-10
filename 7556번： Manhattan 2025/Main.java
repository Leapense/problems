import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int scenarios = sc.nextInt();
        for (int s = 1; s <= scenarios; s++) {
            int u = sc.nextInt();
            int size = 2 * u + 1;
            System.out.println("Scenario #" + s + ":");
            for (int z = -u, slice = 1; z <= u; z++, slice++) {
                System.out.println("slice #" + slice + ":");
                for (int y = u; y >= -u; y--) {
                    StringBuilder sb = new StringBuilder();
                    for (int x = -u; x <= u; x++) {
                        int distance = Math.abs(x) + Math.abs(y) + Math.abs(z);

                        if (distance <= u) {
                            sb.append(distance);
                        } else {
                            sb.append(".");
                        }
                    }
                    System.out.println(sb.toString());
                }
            }
            System.out.println();
        }
        sc.close();
    }
}