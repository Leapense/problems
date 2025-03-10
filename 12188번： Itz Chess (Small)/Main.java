import java.util.*;

public class Main {
    static class Piece {
        int row, col;
        char type;

        Piece(String pos) {
            String[] parts = pos.split("-");
            String coord = parts[0];
            this.type = parts[1].charAt(0);
            this.row = coord.charAt(0) - 'A';
            this.col = coord.charAt(1) - '1';
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = sc.nextInt();
            List<Piece> pieces = new ArrayList<>();
            boolean[][] board = new boolean[8][8];
            for (int i = 0; i < N; i++) {
                String token = sc.next();
                Piece p = new Piece(token);
                pieces.add(p);
                board[p.row][p.col] = true;
            }
            int count = 0;
            for (int i = 0; i < pieces.size(); i++) {
                Piece attacker = pieces.get(i);
                for (int j = 0; j < pieces.size(); j++) {
                    if (i == j)
                        continue;
                    Piece target = pieces.get(j);
                    if (canCapture(attacker, target, board))
                        count++;
                }
            }
            System.out.println("Case #" + t + ": " + count);
        }
        sc.close();
    }

    static boolean canCapture(Piece attacker, Piece target, boolean[][] board) {
        int dr = target.row - attacker.row;
        int dc = target.col - attacker.col;
        switch (attacker.type) {
            case 'K':
                if (Math.abs(dr) <= 1 && Math.abs(dc) <= 1)
                    return true;
                break;
            case 'Q':
                if (dr == 0 || dc == 0 || Math.abs(dr) == Math.abs(dc))
                    if (isClearPath(attacker.row, attacker.col, target.row, target.col, board))
                        return true;
                break;
            case 'R':
                if (dr == 0 || dc == 0)
                    if (isClearPath(attacker.row, attacker.col, target.row, target.col, board))
                        return true;
                break;
            case 'B':
                if (Math.abs(dr) == Math.abs(dc))
                    if (isClearPath(attacker.row, attacker.col, target.row, target.col, board))
                        return true;
                break;
            case 'N':
                if ((Math.abs(dr) == 2 && Math.abs(dc) == 1) || (Math.abs(dr) == 1 && Math.abs(dc) == 2))
                    return true;
                break;
            case 'P':
                if (dr == 1 && Math.abs(dc) == 1)
                    return true;
                break;
        }
        return false;
    }

    static boolean isClearPath(int r1, int c1, int r2, int c2, boolean[][] board) {
        int dr = Integer.compare(r2, r1);
        int dc = Integer.compare(c2, c1);
        int curR = r1 + dr;
        int curC = c1 + dc;
        while (curR != r2 || curC != c2) {
            if (board[curR][curC])
                return false;
            curR += dr;
            curC += dc;
        }
        return true;
    }
}
