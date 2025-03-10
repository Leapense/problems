import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            int n = Integer.parseInt(br.readLine().trim());
            if (n == 0)
                break;
            int[] oldSchedule = new int[n];
            int[] newSchedule = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                oldSchedule[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                newSchedule[i] = Integer.parseInt(st.nextToken());
            }
            List<Integer> ops = new ArrayList<>();
            for (int i = n - 1; i >= 0; i--) {
                if (oldSchedule[i] == newSchedule[i])
                    continue;
                int pos = -1;
                for (int j = i - 1; j >= 0; j--) {
                    if (oldSchedule[j] == newSchedule[i]) {
                        pos = j;
                        break;
                    }
                }
                if (pos != -1) {
                    if (pos != 0) {
                        ops.add(pos + 1);
                        reverse(oldSchedule, pos + 1);
                    }
                    ops.add(i + 1);
                    reverse(oldSchedule, i + 1);
                }
            }
            for (int i = 0; i < ops.size(); i++) {
                sb.append(ops.get(i));
                if (i < ops.size() - 1)
                    sb.append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb.toString());
    }

    static void reverse(int[] arr, int d) {
        int i = 0, j = d - 1;
        while (i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
}