import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        StringBuilder out = new StringBuilder();
        while ((line = br.readLine()) != null)
        {
            if (line.trim().isEmpty()) continue;
            StringTokenizer st = new StringTokenizer(line);
            int n = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            if (n == 0 && w == 0) break;

            int[] values = new int[n];
            int filled = 0;
            while (filled < n)
            {
                if (!st.hasMoreTokens())
                {
                    line = br.readLine();
                    st = new StringTokenizer(line);
                    continue;
                }

                values[filled++] = Integer.parseInt(st.nextToken());
            }

            int maxValue = 0;
            for (int v : values) maxValue = Math.max(maxValue, v);

            int bars = maxValue / w + 1;
            int[] cnt = new int[bars];

            for (int v : values) cnt[v / w]++;
            int maxCnt = 0;
            
            for (int c : cnt) maxCnt = Math.max(maxCnt, c);

            double ink = 0.0;
            for (int i = 0; i < bars; i++)
            {
                double height = (double) cnt[i] / maxCnt;
                double blackness;

                if (bars == 1)
                {
                    blackness = 1.0;
                }
                else
                {
                    blackness = (double)(bars - 1 - i) / (bars - 1);
                }

                ink += height * blackness;
            }

            ink += 0.01;

            out.append(ink).append('\n');
        }

        System.out.print(out.toString());
    }
}