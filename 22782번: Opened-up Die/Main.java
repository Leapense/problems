import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Solution for the "Opened-up Die" problem.
 */
public class Main {

    private int minMValue;
    private int[] bestFaces;

    // Adjacency pairs are derived from the M-value formula given in the problem:
    // M-value = |v1 − v4| + |v2 − v4| + |v4 − v5| + |v5 − v3| + |v4 − v6|
    // The indices in the pairs are 1-based.
    private static final int[][] ADJACENT_PAIRS = {
        {1, 4}, {2, 4}, {4, 5}, {5, 3}, {4, 6}
    };

    /**
     * Main method to handle multiple test cases.
     */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String line = br.readLine();
            new Main().solve(line);
        }
    }

    /**
     * Solves a single test case.
     */
    private void solve(String input) {
        // Initialize state for this test case
        this.minMValue = Integer.MAX_VALUE;
        this.bestFaces = new int[7];

        int[] initialFaces = new int[7];      // 1-based indexing for face indices
        boolean[] usedNumbers = new boolean[7]; // 1-based indexing for numbers 1-6
        List<Integer> unknownIndices = new ArrayList<>();

        // 1. Parse input to identify knowns and unknowns
        for (int i = 0; i < 6; i++) {
            char c = input.charAt(i);
            int faceIndex = i + 1;
            if (c == 'x') {
                unknownIndices.add(faceIndex);
            } else {
                int number = Character.getNumericValue(c);
                initialFaces[faceIndex] = number;
                usedNumbers[number] = true;
            }
        }

        List<Integer> missingNumbers = new ArrayList<>();
        for (int i = 1; i <= 6; i++) {
            if (!usedNumbers[i]) {
                missingNumbers.add(i);
            }
        }
        
        // 2. Start the backtracking process to find the optimal permutation
        permute(initialFaces, unknownIndices, missingNumbers, new boolean[missingNumbers.size()], new int[missingNumbers.size()], 0);

        // 6. Print the final result
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= 6; i++) {
            sb.append(this.bestFaces[i]);
        }
        System.out.println(sb.toString());
    }

    /**
     * Recursively generates permutations of missing numbers to fill unknown faces.
     *
     * @param currentFaces   The array of faces with known numbers filled in.
     * @param unknownIndices The list of indices (1-6) for the unknown faces.
     * @param missingNumbers The list of numbers (1-6) available to be placed.
     * @param usedInPerm     A boolean array to track which missing numbers are used in the current permutation path.
     * @param permutation    The current permutation of missing numbers being built.
     * @param depth          The current depth in the recursion, corresponding to an index in the permutation.
     */
    private void permute(int[] currentFaces, List<Integer> unknownIndices, List<Integer> missingNumbers,
                         boolean[] usedInPerm, int[] permutation, int depth) {
        
        // 3. Base case: a full permutation is generated.
        if (depth == missingNumbers.size()) {
            // Construct a full candidate net
            int[] candidateFaces = Arrays.copyOf(currentFaces, currentFaces.length);
            for (int i = 0; i < unknownIndices.size(); i++) {
                int faceIndex = unknownIndices.get(i);
                int number = permutation[i];
                candidateFaces[faceIndex] = number;
            }

            // 4. Calculate its M-value
            int mValue = calculateMValue(candidateFaces);

            // 5. If this is a better solution, update the best one found so far.
            if (mValue < this.minMValue) {
                this.minMValue = mValue;
                this.bestFaces = candidateFaces;
            }
            return;
        }

        // Recursive step: Try placing each unused missing number at the current depth.
        for (int i = 0; i < missingNumbers.size(); i++) {
            if (!usedInPerm[i]) {
                usedInPerm[i] = true;
                permutation[depth] = missingNumbers.get(i);
                
                permute(currentFaces, unknownIndices, missingNumbers, usedInPerm, permutation, depth + 1);
                
                // Backtrack to explore other possibilities
                usedInPerm[i] = false;
            }
        }
    }

    /**
     * Calculates the M-value for a fully specified net.
     *
     * @param faces An array of 7 integers (index 0 unused) where faces[i] is the number on face i.
     * @return The calculated M-value.
     */
    private int calculateMValue(int[] faces) {
        int sum = 0;
        for (int[] pair : ADJACENT_PAIRS) {
            int u = pair[0];
            int v = pair[1];
            sum += Math.abs(faces[u] - faces[v]);
        }
        return sum;
    }
}