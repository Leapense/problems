import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            String[] parts = br.readLine().split(" ");
            Deque<Integer> initial = new ArrayDeque<>();
            for (int i = 0; i < N; i++) {
                initial.addLast(Integer.parseInt(parts[i]));
            }

            Deque<Integer> pile = new ArrayDeque<>();
            Deque<Integer> helper = new ArrayDeque<>();
            int nextGoal = 1;
            int resets = 0;

            while (nextGoal <= N) {
                boolean moved = true;
                while (moved) {
                    moved = false;

                    if (!helper.isEmpty() && helper.peekLast() == nextGoal) {
                        helper.pollLast();
                        nextGoal++;
                        moved = true;
                        continue;
                    }

                    if (!pile.isEmpty() && pile.peekLast() == nextGoal) {
                        pile.pollLast();
                        nextGoal++;
                        moved = true;
                        continue;
                    }

                    if (!pile.isEmpty()) {
                        if (helper.isEmpty() && pile.peekLast() == N) {
                            helper.addLast(pile.pollLast());
                            moved = true;
                            continue;
                        }

                        if (!helper.isEmpty() && pile.peekLast() == helper.peekLast() - 1) {
                            helper.addLast(pile.pollLast());
                            moved = true;
                            continue;
                        }
                    }
                }

                if (nextGoal > N)
                    break;
                if (!initial.isEmpty()) {
                    pile.addLast(initial.pollLast());
                } else {
                    if (pile.isEmpty())
                        break;
                    resets++;
                    while (!pile.isEmpty()) {
                        initial.addLast(pile.pollLast());
                    }
                }
            }

            sb.append(resets).append("\n");
        }

        System.out.print(sb);
    }
}