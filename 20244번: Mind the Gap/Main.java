//=====================================================================
//   20244번:    Mind the Gap                   
//   @date:   2024-10-15              
//   @link:   https://www.acmicpc.net/problem/20244  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[] tokens = br.readLine().split("\\s+");
		long[] cards = new long[n];
		for (int i = 0; i < n; i++) {
			cards[i] = Long.parseLong(tokens[i]);
		}

		Arrays.sort(cards);
		long maxRequired = cards[0];
		for (int i = 1; i < n; i++) {
			maxRequired = Math.max(maxRequired, cards[i] - cards[i - 1]);
		}

		long minAllowed = Long.MAX_VALUE;
		for (int i = 1; i < n; i++) {
			if (i - 2 >= 0) {
				minAllowed = Math.min(minAllowed, cards[i] - cards[i - 2]);
			} else {
				minAllowed = Math.min(minAllowed, cards[i]);
			}
		}

		if (maxRequired < minAllowed) {
			System.out.println(minAllowed - 1);
		} else {
			System.out.println(0);
		}
	}
}
