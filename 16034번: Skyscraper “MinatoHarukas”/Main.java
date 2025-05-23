import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            int b = Integer.parseInt(br.readLine());
            if (b == 0) break;

            int maxFloors = 0;
            int startFloor = 0;

            for (int k = 1; k * (k - 1) / 2 < b; k++) {
                int temp = b - (k * (k - 1)) / 2;

                if (temp % k == 0) {
                    int n = temp / k;

                    if (n > 0 && k > maxFloors) {
                        maxFloors = k;
                        startFloor = n;
                    }
                }
            }

            sb.append(startFloor).append(" ").append(maxFloors).append("\n");
        }

        System.out.print(sb);

        br.close();
    }
}