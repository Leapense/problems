import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public final class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		if (n == 0) {
			System.out.println("0 0");
			return;
		}

		List<Integer> blockSequence = new ArrayList<>();
		int prevColor = -1;
		for (int i = 0; i < n; i++) {
			int currentColor = Integer.parseInt(st.nextToken());
			if (currentColor != prevColor) {
				blockSequence.add(currentColor);
				prevColor = currentColor;
			}
		}

		int initialBlocks = blockSequence.size();
		Map<Integer, Integer> colorBlockCounts = new HashMap<>();
		Map<Integer, Integer> mergesCausedBy = new HashMap<>();
		for (int color : blockSequence) {
			colorBlockCounts.put(color, colorBlockCounts.getOrDefault(color, 0) + 1);
			mergesCausedBy.putIfAbsent(color, 0);
		}

		for (int i = 1; i < blockSequence.size() - 1; i++) {
			int prev = blockSequence.get(i - 1);
			int current = blockSequence.get(i);
			int next = blockSequence.get(i + 1);
			if (prev == next) {
				mergesCausedBy.put(current, mergesCausedBy.get(current) + 1);
			}
		}

		long maxBlocks = -1;
		int bestColor = -1;

		for (int color : colorBlockCounts.keySet()) {
			int blocksOfThisColor = colorBlockCounts.get(color);
			int merges = mergesCausedBy.get(color);
			long remainingBlocks = (long) initialBlocks - blocksOfThisColor - merges;
			if (remainingBlocks > maxBlocks) {
				maxBlocks = remainingBlocks;
				bestColor = color;
			} else if (remainingBlocks == maxBlocks) {
				if (bestColor == -1 || color < bestColor) {
					bestColor = color;
				}
			}
		}

		if (bestColor == -1 && !blockSequence.isEmpty()) {
			bestColor = blockSequence.get(0);
			maxBlocks = 0;
		}

		System.out.println(maxBlocks + " " + bestColor);
	}
}
