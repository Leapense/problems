import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();

        String result;
        if (A == C) {
            result = "" + A + B + A;
        } else if (C == B) {
            result = "" + A + B + C + A;
        } else {
            result = "" + A + B + C + B + A;
        }

        System.out.println(result);
    }
}