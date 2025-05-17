import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int K = Integer.parseInt(in.readLine().trim());
        for (int dataSet = 1; dataSet <= K; dataSet++) {
            int N = Integer.parseInt(in.readLine().trim());

            // Read first point and initialize
            StringTokenizer st = new StringTokenizer(in.readLine());
            int x0 = Integer.parseInt(st.nextToken());
            int y0 = Integer.parseInt(st.nextToken());
            int prevX = x0, prevY = y0;

            long area2 = 0; // twice the signed area

            // Read intermediate points
            for (int i = 1; i < N; i++) {
                st = new StringTokenizer(in.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                area2 += (long) prevX * y - (long) x * prevY;
                prevX = x;
                prevY = y;
            }
            // Close the polygon (last→first)
            area2 += (long) prevX * y0 - (long) x0 * prevY;

            sb.append("Data Set ").append(dataSet).append(":\n");
            // area2 < 0 → CW → RIGHT; else → LEFT
            sb.append(area2 < 0 ? "RIGHT" : "LEFT").append("\n\n");
        }

        out.write(sb.toString());
        out.flush();
    }
}