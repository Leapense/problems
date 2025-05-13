import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        BitSet[] leftAdj = new BitSet[N + 1];
        for (int i = 1; i <= N; i++) {
            leftAdj[i] = new BitSet(N + 1);
        }

        for (int e = 0; e < M; e++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            leftAdj[u].set(v);
        }

        long answer = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                BitSet tmp = (BitSet) leftAdj[i].clone();
                tmp.and(leftAdj[j]);
                int c = tmp.cardinality();
                if (c >= 2) {
                    answer += (long) c * (c - 1) / 2;
                }
            }
        }

        System.out.println(answer);
    }
}