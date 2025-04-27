import java.util.Scanner;

public class Main {
    static long gcd(long a, long b) {
        if (b == 0)
            return Math.abs(a);
        return gcd(b, a % b);
    }

    static String formatFraction(long num, long den) {
        if (den < 0) {
            num = -num;
            den = -den;
        }

        long g = gcd(num, den);
        num /= g;
        den /= g;

        return (den == 1) ? Long.toString(num) : (num + "/" + den);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long b = sc.nextLong();
        long c = sc.nextLong();
        long d = sc.nextLong();
        sc.close();

        long r = findRoot(b, c, d);

        System.out.println(r);

        long p = b + r;
        long q = c + b * r + r * r;

        long D = p * p - 4 * q;

        if (D == 0) {
            String u = formatFraction(-p, 2);
            System.out.println(u);
            System.out.println(u);
        } else {
            printRoots(p, D);
        }
    }

    static long findRoot(long b, long c, long d) {
        long r = Long.MAX_VALUE;
        for (long x = -Math.abs(d); x <= Math.abs(d); x++) {
            if (x * x * x + b * x * x + c * x + d == 0) {
                r = x;
                break;
            }
        }
        return r;
    }

    static void printRoots(long p, long D) {
        long sqrtD = (long) Math.sqrt(D);
        if (sqrtD * sqrtD == D) {
            long num1 = -p + sqrtD, num2 = -p - sqrtD;
            String root1 = formatFraction(num1, 2);
            String root2 = formatFraction(num2, 2);
            System.out.println(root1);
            System.out.println(root2);
        } else {
            String u = formatFraction(-p, 2);
            long vn = D, vd = 4;
            long g = gcd(vn, vd);
            vn /= g;
            vd /= g;
            String v = (vd == 1) ? Long.toString(vn) : (vn + "/" + vd);

            System.out.println(u + "+sqrt(" + v + ")");
            System.out.println(u + "-sqrt(" + v + ")");
        }
    }
}