//=====================================================================
//   19769번:    Робот                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/19769  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] nk = br.readLine().split(" ");
		int n = Integer.parseInt(nk[0]);
		int k = Integer.parseInt(nk[1]);
		String[] s = br.readLine().split(" ");

		long sum = 0;

		ArrayList<Integer> neg = new ArrayList<>();
		ArrayList<Integer> pos = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			int a = Integer.parseInt(s[i]);
			sum += a;
			if (a < 0) neg.add(a);
			else pos.add(a);
		}

		Collections.sort(neg);
		long max_sum = sum;

		for (int i = 0; i < Math.min(k, neg.size()); i++) {
			max_sum += (-2L * neg.get(i));
		}

		Collections.sort(pos, Collections.reverseOrder());
		long min_sum = sum;

		for (int i = 0; i < Math.min(k, pos.size()); i++) {
			min_sum += (-2L * pos.get(i));
		}

		long result = Math.max(Math.abs(max_sum), Math.abs(min_sum));
		System.out.println(result);
	}
}
