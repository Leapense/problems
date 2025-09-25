import java.io.*;
import java.util.*;

public class Main {
	static void appendChars(StringBuilder sb, char c, int cnt) {
		for (int i = 0; i < cnt; i++) sb.append(c);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int K = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());

		int lower = (N + 2) / 3;
		int upper = (N + 1) / 2;
		if (K < lower || K > upper) {
			System.out.println("*");
			return;
		}
		int extras = N - (2 * K - 1);

		StringBuilder sb = new StringBuilder(N);

		int g0 = Math.min(1, extras);
		extras -= g0;
		appendChars(sb, '-', g0);

		for (int i = 0; i < K; i++) {
			sb.append('X');
			if (i < K - 1) {
				int gap = 1 + (extras > 0 ? 1 : 0);
				if (extras > 0) extras--;
				appendChars(sb, '-', gap);
			}
		}

		int gK = Math.min(1, extras);
		extras -= gK;
		appendChars(sb, '-', gK);

		System.out.println(sb.toString());
	}
}
