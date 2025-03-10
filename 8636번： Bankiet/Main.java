
/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8636                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8636                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 18:03:47 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] left = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            left[i] = Integer.parseInt(br.readLine());
        }

        boolean[] visited = new boolean[N + 1];
        int tableCount = 0;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                tableCount++;
                int current = i;
                while (!visited[current]) {
                    visited[current] = true;
                    current = left[current];
                }
            }
        }
        System.out.println(tableCount);
    }
}