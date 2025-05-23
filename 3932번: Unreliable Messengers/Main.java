import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String order = sc.nextLine().trim();
            String message = sc.nextLine().trim();

            for (int i = order.length() - 1; i >= 0; i--) {
                char messenger = order.charAt(i);
                message = applyInverse(messenger, message);
            }

            System.out.println(message);
        }
        sc.close();
    }

    static String applyInverse(char messenger, String message) {
        switch (messenger) {
            case 'J':
                return rotateRight(message);
            case 'C':
                return rotateLeft(message);
            case 'E':
                return swapHalves(message);
            case 'A':
                return reverse(message);
            case 'P':
                return decrementDigits(message);
            case 'M':
                return incrementDigits(message);
            default:
                return message;
        }
    }

    static String rotateRight(String s) {
        if (s.length() <= 1)
            return s;
        return s.charAt(s.length() - 1) + s.substring(0, s.length() - 1);
    }

    static String rotateLeft(String s) {
        if (s.length() <= 1)
            return s;
        return s.substring(1) + s.charAt(0);
    }

    static String swapHalves(String s) {
        int n = s.length();
        int mid = n / 2;
        if (n % 2 == 0) {
            return s.substring(mid) + s.substring(0, mid);
        } else {
            return s.substring(mid + 1) + s.charAt(mid) + s.substring(0, mid);
        }
    }

    static String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    static String decrementDigits(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                int d = c - '0';
                d = (d + 9) % 10;
                sb.append(d);
            } else {
                sb.append(c);
            }
        }

        return sb.toString();
    }

    static String incrementDigits(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                int d = c - '0';
                d = (d + 1) % 10;
                sb.append(d);
            } else {
                sb.append(c);
            }
        }

        return sb.toString();
    }
}