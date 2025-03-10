
/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8631                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8631                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 13:22:56 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int h = sc.nextInt();
            map.put(h, map.getOrDefault(h, 0) + 1);
        }

        boolean allSame = (map.size() == 1);
        int multiplier = allSame ? 1 : 2;
        boolean small = true;
        long fullVal = 1;
        int modVal = 1;
        for (int freq : map.values()) {
            for (int i = 1; i <= freq; i++) {
                if (small) {
                    fullVal *= i;
                    if (fullVal >= 1000) {
                        small = false;
                        modVal = (int) (fullVal % 10000);
                    }
                } else {
                    modVal = (int) ((long) modVal * i % 10000);
                }
            }
        }

        if (small) {
            fullVal *= multiplier;
            if (fullVal >= 1000) {
                small = false;
                modVal = (int) (fullVal % 10000);
            }
        } else {
            modVal = (int) ((long) modVal * multiplier % 10000);
        }
        if (small) {
            System.out.println(fullVal);
        } else {
            System.out.printf("%04d", modVal);
        }
    }
}