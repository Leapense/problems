import java.io.*;
import java.util.*;

public class Main {
    static class Password {
        String pwd;
        double prob;

        public Password(String pwd, double prob) {
            this.pwd = pwd;
            this.prob = prob;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        List<Password> list = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            String[] parts = br.readLine().trim().split("\\s+");
            String pwd = parts[0];
            double prob = Double.parseDouble(parts[1]);
            list.add(new Password(pwd, prob));
        }

        list.sort((a, b) -> {
            if (Double.compare(b.prob, a.prob) != 0) {
                return Double.compare(b.prob, a.prob);
            }
            return 0;
        });

        double expected = 0.0;
        for (int i = 0; i < N; i++) {
            expected += (i+1) * list.get(i).prob;
        }
        System.out.printf("%.4f", expected);

        br.close();
    }
}