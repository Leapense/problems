import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] d = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) d[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(d);
        long total = 0;
        for (int i = 0; i < n; i++) {
            int latency = d[n - 1 - i];
            int depth = i / k + 1;
            total += (long) latency * depth;
        }

        System.out.println(total);
    }
}
