import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(reader.readLine());
        int[] xs = new int[count];
        int[] ys = new int[count];

        for (int i = 0; i < count; i++) {
            StringTokenizer tk = new StringTokenizer(reader.readLine());
            xs[i] = Integer.parseInt(tk.nextToken());
            ys[i] = Integer.parseInt(tk.nextToken());
        }

        Arrays.sort(xs);
        Arrays.sort(ys);
        int medianX = xs[count / 2];
        int medianY = ys[count / 2];
        System.out.println(medianX + " " + medianY);
    }
}