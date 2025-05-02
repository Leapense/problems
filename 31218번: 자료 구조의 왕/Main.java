import java.io.*;
import java.util.*;

public class Main {
    static class Job {
        int dy, dx, y, x;

        Job(int dy, int dx, int y, int x) {
            this.dy = dy;
            this.dx = dx;
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());

        boolean[][] grass = new boolean[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(grass[i], true);
        }

        int remaining = n * m;

        List<Job> pendingJobs = new ArrayList<>();
        StringBuilder sb = new StringBuilder();

        for (int qi = 0; qi < Q; qi++) {
            st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());

            if (type == 1) {
                int dy = Integer.parseInt(st.nextToken());
                int dx = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken());
                pendingJobs.add(new Job(dy, dx, y, x));
            } else {
                for (Job job : pendingJobs) {
                    int dy = job.dy;
                    int dx = job.dx;
                    int y = job.y;
                    int x = job.x;
                    while (y >= 1 && y <= n && x >= 1 && x <= m && grass[y][x]) {
                        grass[y][x] = false;
                        remaining--;
                        y += dy;
                        x += dx;
                    }
                }

                pendingJobs.clear();

                if (type == 2) {
                    int y = Integer.parseInt(st.nextToken());
                    int x = Integer.parseInt(st.nextToken());
                    sb.append(grass[y][x] ? 0 : 1).append('\n');
                } else {
                    sb.append(remaining).append('\n');
                }
            }
        }
        System.out.print(sb);
    }
}