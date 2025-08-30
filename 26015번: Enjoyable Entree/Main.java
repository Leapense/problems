import java.io.*;

public class Main
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine().trim());
        double pow2 = Math.pow(2.0, -n);
        double sign = (n % 2 == 0) ? 1.0 : -1.0;
        double term = sign * pow2;
        double a = 1.0 / 3.0 + (-4.0 / 3.0) * term;
        double b = 2.0 / 3.0 + (4.0 / 3.0) * term;
        System.out.printf("%.10f %.10f%n", a * 100.0, b * 100.0);
    }
}