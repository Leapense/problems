import java.util.*;

public class Main {
    // 나이트의 가능한 이동 방향 (x, y)
    static int[][] moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    // 메모이제이션을 위한 캐시
    // cacheWhite[whiteX][whiteY][blackX][blackY][turn]
    static double[][][][][] cacheWhite = new double[9][9][9][9][2];
    static double[][][][][] cacheBlack = new double[9][9][9][9][2];
    static boolean[][][][][] computedWhite = new boolean[9][9][9][9][2];
    static boolean[][][][][] computedBlack = new boolean[9][9][9][9][2];
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int D = sc.nextInt();
        
        // 초기 상태: white (A,B), black (C,D), white의 턴
        double whiteProb = getProbWhite(A, B, C, D, 0);
        double blackProb = getProbBlack(A, B, C, D, 0);
        
        if (Math.abs(whiteProb - blackProb) < 1e-6) {
            System.out.println("draw");
        } else if (whiteProb > blackProb) {
            System.out.println("white");
        } else {
            System.out.println("black");
        }
    }
    
    // 백색 나이트의 승리 확률을 반환하는 함수
    static double getProbWhite(int whiteX, int whiteY, int blackX, int blackY, int turn) {
        // 게임 종료 조건
        if (turn == 0 && whiteX == blackX && whiteY == blackY) {
            return 1.0;
        }
        if (turn == 1 && blackX == whiteX && blackY == whiteY) {
            return 0.0;
        }
        
        // 이미 계산된 상태라면 캐시에서 반환
        if (computedWhite[whiteX][whiteY][blackX][blackY][turn]) {
            return cacheWhite[whiteX][whiteY][blackX][blackY][turn];
        }
        
        computedWhite[whiteX][whiteY][blackX][blackY][turn] = true;
        
        double totalWhite = 0.0;
        
        if (turn == 0) { // white의 턴
            List<int[]> nextMoves = getNextMoves(whiteX, whiteY);
            int k = nextMoves.size();
            if (k > 0) {
                for (int[] move : nextMoves) {
                    int newWhiteX = move[0];
                    int newWhiteY = move[1];
                    // 승리 조건 체크
                    if (newWhiteX == blackX && newWhiteY == blackY) {
                        totalWhite += 1.0;
                    } else {
                        totalWhite += getProbWhite(newWhiteX, newWhiteY, blackX, blackY, 1);
                    }
                }
                cacheWhite[whiteX][whiteY][blackX][blackY][turn] = totalWhite / k;
            } else { // 이동 불가 시 턴을 넘김
                totalWhite = getProbWhite(whiteX, whiteY, blackX, blackY, 1);
                cacheWhite[whiteX][whiteY][blackX][blackY][turn] = totalWhite;
            }
        } else { // black의 턴
            List<int[]> nextMoves = getNextMoves(blackX, blackY);
            int m = nextMoves.size();
            if (m > 0) {
                for (int[] move : nextMoves) {
                    int newBlackX = move[0];
                    int newBlackY = move[1];
                    // 승리 조건 체크
                    if (newBlackX == whiteX && newBlackY == whiteY) {
                        // black이 승리하면 white의 승리 확률은 0
                        totalWhite += 0.0;
                    } else {
                        totalWhite += getProbWhite(whiteX, whiteY, newBlackX, newBlackY, 0);
                    }
                }
                cacheWhite[whiteX][whiteY][blackX][blackY][turn] = totalWhite / m;
            } else { // 이동 불가 시 턴을 넘김
                totalWhite = getProbWhite(whiteX, whiteY, blackX, blackY, 0);
                cacheWhite[whiteX][whiteY][blackX][blackY][turn] = totalWhite;
            }
        }
        
        return cacheWhite[whiteX][whiteY][blackX][blackY][turn];
    }
    
    // 흑색 나이트의 승리 확률을 반환하는 함수
    static double getProbBlack(int whiteX, int whiteY, int blackX, int blackY, int turn) {
        // 게임 종료 조건
        if (turn == 0 && whiteX == blackX && whiteY == blackY) {
            return 0.0;
        }
        if (turn == 1 && blackX == whiteX && blackY == whiteY) {
            return 1.0;
        }
        
        // 이미 계산된 상태라면 캐시에서 반환
        if (computedBlack[whiteX][whiteY][blackX][blackY][turn]) {
            return cacheBlack[whiteX][whiteY][blackX][blackY][turn];
        }
        
        computedBlack[whiteX][whiteY][blackX][blackY][turn] = true;
        
        double totalBlack = 0.0;
        
        if (turn == 0) { // white의 턴
            List<int[]> nextMoves = getNextMoves(whiteX, whiteY);
            int k = nextMoves.size();
            if (k > 0) {
                for (int[] move : nextMoves) {
                    int newWhiteX = move[0];
                    int newWhiteY = move[1];
                    // 승리 조건 체크
                    if (newWhiteX == blackX && newWhiteY == blackY) {
                        // white가 승리하면 black의 승리 확률은 0
                        totalBlack += 0.0;
                    } else {
                        totalBlack += getProbBlack(newWhiteX, newWhiteY, blackX, blackY, 1);
                    }
                }
                cacheBlack[whiteX][whiteY][blackX][blackY][turn] = totalBlack / k;
            } else { // 이동 불가 시 턴을 넘김
                totalBlack = getProbBlack(whiteX, whiteY, blackX, blackY, 1);
                cacheBlack[whiteX][whiteY][blackX][blackY][turn] = totalBlack;
            }
        } else { // black의 턴
            List<int[]> nextMoves = getNextMoves(blackX, blackY);
            int m = nextMoves.size();
            if (m > 0) {
                for (int[] move : nextMoves) {
                    int newBlackX = move[0];
                    int newBlackY = move[1];
                    // 승리 조건 체크
                    if (newBlackX == whiteX && newBlackY == whiteY) {
                        totalBlack += 1.0;
                    } else {
                        totalBlack += getProbBlack(whiteX, whiteY, newBlackX, newBlackY, 0);
                    }
                }
                cacheBlack[whiteX][whiteY][blackX][blackY][turn] = totalBlack / m;
            } else { // 이동 불가 시 턴을 넘김
                totalBlack = getProbBlack(whiteX, whiteY, blackX, blackY, 0);
                cacheBlack[whiteX][whiteY][blackX][blackY][turn] = totalBlack;
            }
        }
        
        return cacheBlack[whiteX][whiteY][blackX][blackY][turn];
    }
    
    // 현재 위치에서 가능한 모든 이동을 반환하는 함수
    static List<int[]> getNextMoves(int x, int y) {
        List<int[]> movesList = new ArrayList<>();
        for (int[] move : moves) {
            int nx = x + move[0];
            int ny = y + move[1];
            if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
                movesList.add(new int[]{nx, ny});
            }
        }
        return movesList;
    }
}
