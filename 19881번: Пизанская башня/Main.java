import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(reader.readLine().trim());
        if (n == 1L) {
            System.out.println(1);
            return;
        }

        long prevPrev = 1;
        long prev = 3;
        for (long i = 3; i <= n; i++) {
            long current = prev + prevPrev + 1;
            prevPrev = prev;
            prev = current;
        }
        System.out.println(prev);
    }
}