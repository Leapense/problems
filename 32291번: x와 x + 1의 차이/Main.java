import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		while (line != null && line.trim().isEmpty()) line = br.readLine();
		long x = Long.parseLong(line.trim());
		long n = x + 1;

		List<Long> small = new ArrayList<>();
		List<Long> large = new ArrayList<>();

		for (long i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				long a = i;
				long b = n / i;
				if (a <= x) small.add(a);
				if (b != a && b <= x) large.add(b);
			}
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < small.size(); i++) {
			if (sb.length() > 0) sb.append(' ');
			sb.append(small.get(i));
		}

		for (int i = large.size() - 1; i >= 0; i--) {
			if (sb.length() > 0) sb.append(' ');
			sb.append(large.get(i));
		}
		System.out.println(sb.toString());
	}
}
