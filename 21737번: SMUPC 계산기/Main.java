import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringJoiner;

public final class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String expression = br.readLine();

		List<String> results = new ArrayList<>();
		long currentValue = 0;
		char pendingOperator = '\0';
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < expression.length(); i++) {
			char ch = expression.charAt(i);
			if (Character.isDigit(ch)) {
				sb.append(ch);
			} else {
				if (sb.length() > 0) {
					long operand = Long.parseLong(sb.toString());
					if (pendingOperator == '\0') {
						currentValue = operand;
					} else {
						currentValue = calculate(currentValue, operand, pendingOperator);
					}
					sb.setLength(0);
				}

				if (ch == 'C') {
					results.add(String.valueOf(currentValue));
				} else {
					pendingOperator = ch;
				}
			}
		}

		if (results.isEmpty()) {
			System.out.println("NO OUTPUT");
		} else {
			StringJoiner joiner = new StringJoiner(" ");
			for (String result : results) {
				joiner.add(result);
			}
			System.out.println(joiner.toString());
		}
	}

	private static long calculate(long val1, long val2, char op) {
		switch (op) {
			case 'S':
				return val1 - val2;
			case 'M':
				return val1 * val2;
			case 'U':
				if (val1 < 0) {
					return -(Math.abs(val1) / val2);
				}
				return val1 / val2;
			case 'P':
				return val1 + val2;
			default:
				return val2;
		}
	}
}
