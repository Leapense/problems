import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main
{
    static long gcd(long a, long b)
    {
        while (b != 0)
        {
            long tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    static long lcm(long a, long b)
    {
        return a / gcd(a, b) * b;
    }

    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String line;
        StringBuilder out = new StringBuilder();

        while (true)
        {
            line = br.readLine();
            if (line == null) break;

            st = new StringTokenizer(line);

            int n = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            if (n == 0 && t == 0) break;
            long[] c = new long[n];

            for (int i = 0; i < n; i++) c[i] = Long.parseLong(br.readLine().trim());
            long[] h = new long[t];
            
            for (int i = 0; i < t; i++) h[i] = Long.parseLong(br.readLine().trim());
            long[] bestLow = new long[t];
            long[] bestHigh = new long[t];

            for (int i = 0; i < t; i++) bestHigh[i] = Long.MAX_VALUE;

            for (int i = 0; i < n - 3; i++)
            {
                for (int j = i + 1; j < n - 2; j++)
                {
                    long lcm2 = lcm(c[i], c[j]);
                    for (int k = j + 1; k < n - 1; k++)
                    {
                        long lcm3 = lcm(lcm2, c[k]);
                        for (int l = k + 1; l < n; l++)
                        {
                            long L = lcm(lcm3, c[l]);
                            for (int q = 0; q < t; q++)
                            {
                                long H = h[q];
                                long low = (H / L) * L;
                                if (low > bestLow[q]) bestLow[q] = low;

                                long high = (H % L == 0) ? H : (H / L + 1) * L;

                                if (high < bestHigh[q]) bestHigh[q] = high;
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < t; i++) {
                out.append(bestLow[i]).append(' ').append(bestHigh[i]).append('\n');
            }
        }

        System.out.print(out.toString());
    }
}