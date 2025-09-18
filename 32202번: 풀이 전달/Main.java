import java.io.*;
import java.util.*;

public class Main {
	static final long MOD = 1_000_000_007L;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine().trim());

		if (N == 1) {
			System.out.println(3);
			return;
		}

		long a = 1;
		long b = 2;

		for (int n = 2; n <= N; n++) {
			long nextA = b % MOD;
			long nextB = ((a + b) % MOD) * 2 % MOD;
			a = nextA;
			b = nextB;
		}

		long ans = (a + b) % MOD;
		System.out.println(ans);
	}
}
