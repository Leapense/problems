import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int K = Integer.parseInt(br.readLine().trim());
        for (int t = 1; t <= K; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            int[] total = new int[l + 1];
            int[] sober = new int[l + 1];
            List<Integer>[] caps = new ArrayList[l + 1];
            for (int i = 1; i <= l; i++)
                caps[i] = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                int r = Integer.parseInt(st.nextToken());
                char ch = st.nextToken().charAt(0);
                total[r]++;
                if (ch == 'S')
                    sober[r]++;
            }
            for (int i = 0; i < c; i++) {
                st = new StringTokenizer(br.readLine());
                int r = Integer.parseInt(st.nextToken());
                int seat = Integer.parseInt(st.nextToken());
                caps[r].add(seat);
            }
            int stay = 0;
            for (int r = 1; r <= l; r++) {
                List<Integer> list = caps[r];
                if (list.isEmpty()) {
                    stay += total[r];
                    continue;
                }
                list.sort(Collections.reverseOrder());
                int cars = Math.min(sober[r], list.size());
                long seats = 0;
                for (int i = 0; i < cars; i++)
                    seats += list.get(i);
                int transported = (int) Math.min(total[r], seats);
                stay += total[r] - transported;
            }
            sb.append("Data Set ").append(t).append(":\n").append(stay).append('\n');
        }
        System.out.print(sb.toString());
    }
}
