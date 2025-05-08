import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class TestMain {
    public static void main(String[] args) throws IOException {
        Runtime runtime = Runtime.getRuntime();

        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Used Memory Before (bytes): " + usedMemoryBefore);
        System.out.println("Used Memory Before (MB): " + bytesToMegabytes(usedMemoryBefore));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] A = new int[N];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        boolean[] visited = new boolean[N];
        boolean possible = true;

        for (int startIdx = 0; startIdx < N; startIdx++) {
            if (!visited[startIdx]) {
                List<Integer> currentValuesInCycle = new ArrayList<>();
                List<Integer> targetValuesForCycle = new ArrayList<>();

                int currentIdx = startIdx;

                while (!visited[currentIdx]) {
                    visited[currentIdx] = true;
                    currentValuesInCycle.add(A[currentIdx]);
                    targetValuesForCycle.add(currentIdx);

                    currentIdx = (currentIdx + K) % N;
                }

                Collections.sort(currentValuesInCycle);
                Collections.sort(targetValuesForCycle);

                if (!currentValuesInCycle.equals(targetValuesForCycle)) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Used Memory After (bytes): " + usedMemoryAfter);
        System.out.println("Used Memory After (MB): " + bytesToMegabytes(usedMemoryAfter));

        System.out.println("Memory used by logic (approx MB): " + bytesToMegabytes(usedMemoryAfter - usedMemoryBefore));
    }

    private static long bytesToMegabytes(long bytes) {
        return bytes / (1024 * 1024);
    }
}
