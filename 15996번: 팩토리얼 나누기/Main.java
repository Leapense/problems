import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int A = Integer.parseInt(input[1]);

        int i = 1;
        int res = 0;
        // A의 i제곱값이 N보다 작거나 같을 때까지 i를 증가시킨다.
        while (Math.pow(A, i) <= N) {
            // N을 A의 i제곱값을 나누었을 때의 정수 몫을 가져와서 res의 값에다가 더해준다.
            res += N / (int) Math.pow(A, i);
            i++;
        }

        System.out.println(res);

        br.close();
    }
}