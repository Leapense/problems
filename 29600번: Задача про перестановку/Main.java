import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static int n, k;
    static ArrayList<ArrayList<Integer>> validPermutations = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        ArrayList<Integer> current = new ArrayList<>();
        boolean[] used = new boolean[n + 1];
        generatePermutations(current, used);

        Collections.sort(validPermutations, (a, b) -> {
            for (int i = 0; i < a.size(); i++) {
                if (!a.get(i).equals(b.get(i))) {
                    return a.get(i) - b.get(i);
                }
            }

            return 0;
        });

        ArrayList<Integer> answer = validPermutations.get(k - 1);
        for (int num : answer) {
            out.print(num + " ");
        }

        out.flush();
        out.close();
    }

    static void generatePermutations(ArrayList<Integer> current, boolean[] used) {
        if (current.size() == n) {
            validPermutations.add(new ArrayList<>(current));
            return;
        }

        for (int num = 1; num <= n; num++) {
            if (!used[num]) {
                if (!current.isEmpty()) {
                    int last = current.get(current.size() - 1);
                    if ((last == 1 && num == 2) || (last == 2 && num == 1)) {
                        continue;
                    }
                }

                used[num] = true;
                current.add(num);
                generatePermutations(current, used);
                current.remove(current.size() - 1);
                used[num] = false;
            }
        }
    }
}