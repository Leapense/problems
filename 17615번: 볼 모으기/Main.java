import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        String balls = reader.readLine();
        if (balls.chars().allMatch(c -> c == balls.charAt(0))) {
            System.out.print(0);
            return;
        }

        int result = Integer.MAX_VALUE;
        result = Math.min(result, countMoves(balls, 'R', true));
        result = Math.min(result, countMoves(balls, 'R', false));
        result = Math.min(result, countMoves(balls, 'B', true));
        result = Math.min(result, countMoves(balls, 'B', false));
        System.out.print(result);
    }

    private static int countMoves(String balls, char target, boolean leftToRight) {
        int moves = 0;
        boolean started = false;
        if (leftToRight) {
            for (char ball : balls.toCharArray()) {
                if (ball == target) {
                    started = true;
                } else if (started && ball != target) {
                    moves++;
                }
            }
        } else {
            for (int i = balls.length() - 1; i >= 0; i--) {
                char ball = balls.charAt(i);
                if (ball == target) {
                    started = true;
                } else if (started && ball != target) {
                    moves++;
                }
            }
        }

        return moves;
    }
}