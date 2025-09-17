import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(br.readLine().trim());
        int flog2 = 63 - Long.numberOfLeadingZeros(N);
        long answer = 10L + flog2;
        System.out.println(answer);
    }
}