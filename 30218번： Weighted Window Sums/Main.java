import java.io.*;
import java.util.*;

public class Main {
    static class Window implements Comparable<Window> {
        int index;
        long weightedSum;

        public Window(int index, long weightedSum) {
            this.index = index;
            this.weightedSum = weightedSum;
        }

        @Override
        public int compareTo(Window other) {
            if (this.weightedSum != other.weightedSum) {
                return Long.compare(this.weightedSum, other.weightedSum);
            }
            return Integer.compare(this.index, other.index);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] firstLine = br.readLine().split(" ");
        int n = Integer.parseInt(firstLine[0]);
        int k = Integer.parseInt(firstLine[1]);

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        int totalWindows = n - k + 1;
        Window[] windows = new Window[totalWindows];

        long sum = 0;
        long weightedSum = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
            weightedSum += (long) (i + 1) * arr[i];
        }

        windows[0] = new Window(1, weightedSum);

        for (int i = 0; i < totalWindows - 1; i++) {
            weightedSum = weightedSum - sum + (long) k * arr[i + k];
            sum = sum - arr[i] + arr[i + k];
            windows[i + 1] = new Window(i + 2, weightedSum);
        }

        Arrays.sort(windows);

        for (Window win : windows) {
            bw.write(win.index + " " + win.weightedSum);
            bw.newLine();
        }

        bw.flush();
        bw.close();
        br.close();
    }
}