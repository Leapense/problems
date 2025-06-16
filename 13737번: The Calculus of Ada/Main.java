import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public void run() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while (true)
        {
            String line = reader.readLine();
            if (line == null || line.trim().isEmpty()) {
                break;
            }

            StringTokenizer st = new StringTokenizer(line);
            if (!st.hasMoreTokens()) 
            {
                continue;
            }

            int n = Integer.parseInt(st.nextToken());
            List<Integer> initialSequence = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                initialSequence.add(Integer.parseInt(st.nextToken()));
            }

            solve(initialSequence);
        }
    }

    private void solve(List<Integer> sequence) {
        List<List<Integer>> differencePyramid = new ArrayList<>();
        differencePyramid.add(sequence);

        List<Integer> currentSequence = sequence;
        while (true) {
            if (isConstant(currentSequence)) {
                break;
            }

            List<Integer> nextDifference = new ArrayList<>();
            for (int i = 0; i < currentSequence.size() - 1; i++) {
                int diff = currentSequence.get(i + 1) - currentSequence.get(i);
                nextDifference.add(diff);
            }

            differencePyramid.add(nextDifference);
            currentSequence = nextDifference;
        }

        int degree = differencePyramid.size() - 1;

        for (int i = degree; i > 0; i--) {
            List<Integer> lowerRow = differencePyramid.get(i);
            List<Integer> upperRow = differencePyramid.get(i - 1);

            int valueToAdd = lowerRow.get(lowerRow.size() - 1);
            int lastValueOfUpper = upperRow.get(upperRow.size() - 1);

            upperRow.add(lastValueOfUpper + valueToAdd);
        }

        int nextValue = differencePyramid.get(0).get(differencePyramid.get(0).size() - 1);
        System.out.println(degree + " " + nextValue);
    }

    private boolean isConstant(List<Integer> list) {
        if (list.size() < 2) {
            return true;
        }

        int first = list.get(0);
        for (int i = 1; i < list.size(); i++) {
            if (!list.get(i).equals(first)) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}