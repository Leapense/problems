import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static String[][] digitPattern = new String[10][];
    static int[][] cost = new int[10][10];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int d = 0; d < 10; d++) {
            digitPattern[d] = new String[n];
            for (int i = 0; i < n; i++) {
                digitPattern[d][i] = br.readLine();
            }
        }

        for (int d1 = 0; d1 < 10; d1++) {
            for (int d2 = 0; d2 < 10; d2++) {
                int diff = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (digitPattern[d1][i].charAt(j) != digitPattern[d2][i].charAt(j)) {
                            diff++;
                        }
                    }
                }
                cost[d1][d2] = diff;
            }
        }

        int totalEnergy = 0;

        int currentTime = 0;

        for (int t = 0; t < 1440; t++) {
            int nextTime = (currentTime + 1) % 1440;
            int curHour = currentTime / 60;
            int curMin = currentTime % 60;
            int nextHour = nextTime / 60;
            int nextMin = nextTime % 60;

            int curDigits[] = { curHour / 10, curHour % 10, curMin / 10, curMin % 10 };
            int nextDigits[] = { nextHour / 10, nextHour % 10, nextMin / 10, nextMin % 10 };

            for (int pos = 0; pos < 4; pos++) {
                totalEnergy += cost[curDigits[pos]][nextDigits[pos]];
            }

            currentTime = nextTime;
        }

        out.println(totalEnergy);
        out.flush();
        out.close();
    }
}