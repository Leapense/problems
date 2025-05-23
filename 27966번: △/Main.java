import java.io.*;

public class Main {
    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int N = Integer.parseInt(br.readLine());
        long result = (long) (N - 1) * (N - 1);
        out.println(result);

        for (int i = 2; i <= N; i++) {
            out.println("1 " + i);
        }
        out.flush();
    }
}