import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
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
    }
}