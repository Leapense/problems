import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String dna = br.readLine().trim();
        int n = dna.length();

        int[][] prefix = new int[4][n + 1];
        for (int i = 1; i <= n; i++) {
            char ch = dna.charAt(i - 1);
            for (int k = 0; k < 4; k++) {
                prefix[k][i] = prefix[k][i - 1];
            }

            switch (ch) {
                case 'A':
                    prefix[0][i]++;
                    break;
                case 'T':
                    prefix[1][i]++;
                    break;
                case 'G':
                    prefix[2][i]++;
                    break;
                case 'C':
                    prefix[3][i]++;
                    break;
            }
        }

        int m = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        char[] order = { 'A', 'T', 'G', 'C' };
        for (int qi = 0; qi < m; qi++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            Pair[] arr = new Pair[4];
            for (int k = 0; k < 4; k++) {
                int cnt = prefix[k][e] - prefix[k][s - 1];
                arr[k] = new Pair(cnt, order[k], k);
            }

            Arrays.sort(arr, (p1, p2) -> {
                if (p1.count != p2.count) {
                    return Integer.compare(p2.count, p1.count);
                }

                return Integer.compare(p1.idx, p2.idx);
            });

            for (Pair p : arr) {
                sb.append(p.ch);
            }
            sb.append('\n');
        }

        System.out.print(sb);
    }

    static class Pair {
        int count;
        char ch;
        int idx;

        Pair(int c, char ch, int i) {
            this.count = c;
            this.ch = ch;
            this.idx = i;
        }
    }
}