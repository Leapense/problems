import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {
    private static final int[] flipMask = new int[16];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int startMask = 0;
        for (int r = 0; r < 4; r++) {
            String line = br.readLine();
            for (int c = 0; c < 4; c++) {
                if (line.charAt(c) == 'b') {
                    startMask |= 1 << (r * 4 + c);
                }
            }
        }

        preprocessFlipMasks();

        int result = bfsMinSteps(startMask);

        if (result < 0) {
            System.out.println("Impossible");
        } else {
            System.out.println(result);
        }
    }

    private static void preprocessFlipMasks() {
        for (int i = 0; i < 16; i++) {
            int mask = 0;
            int r = i / 4;
            int c = i % 4;

            mask |= 1 << i;
            if (r > 0)
                mask |= 1 << ((r - 1) * 4 + c);
            if (r < 3)
                mask |= 1 << ((r + 1) * 4 + c);
            if (c > 0)
                mask |= 1 << (r * 4 + (c - 1));
            if (c < 3)
                mask |= 1 << (r * 4 + (c + 1));
            flipMask[i] = mask;
        }
    }

    private static int bfsMinSteps(int start) {
        if (start == 0 || start == 0xFFFF) {
            return 0;
        }

        boolean[] visited = new boolean[1 << 16];
        Queue<int[]> queue = new ArrayDeque<>();
        visited[start] = true;
        queue.add(new int[] { start, 0 });

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int mask = curr[0], depth = curr[1];
            for (int i = 0; i < 16; i++) {
                int nextMask = mask ^ flipMask[i];
                if (!visited[nextMask]) {
                    if (nextMask == 0 || nextMask == 0xFFFF) {
                        return depth + 1;
                    }

                    visited[nextMask] = true;
                    queue.add(new int[] { nextMask, depth + 1 });
                }
            }
        }

        return -1; // 불가능
    }
}
