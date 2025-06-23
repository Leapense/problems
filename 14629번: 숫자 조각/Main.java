import java.util.Scanner;

public final class Main {

    /**
     * 유틸리티 클래스이므로 인스턴스화를 방지한다.
     */
    private Main() {
        throw new UnsupportedOperationException("이 클래스는 인스턴스화할 수 없습니다.");
    }
    
    /**
     * 프로그램의 메인 메서드이다.
     * @param args 커맨드 라인 인자 (사용되지 않음)
     */
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            long n = scanner.nextLong();
            NumberPieceSolver solver = new NumberPieceSolver(n);
            long result = solver.solve();
            System.out.println(result);
        }
    }
}

/**
 * '숫자 조각' 문제의 해결 록직을 캡슐화한 클래스입니다.
 */
class NumberPieceSolver {
    private final long targetN;
    private long minDifference;
    private long bestCandidate;

    /**
     * NumberPieceSolver 클래스의 생성자
     * @param targetN 비교 대상이 되는 숫자
     */
    public NumberPieceSolver(long targetN) {
        this.targetN = targetN;
        this.minDifference = Long.MAX_VALUE;
        this.bestCandidate = -1;
    }

    /**
     * 문제를 해결하고 N과 가장 차이가 적은 숫자를 반환한다.
     * @return N과 가장 차이가 적은 숫자
     */
    public long solve() {
        boolean[] used = new boolean[10];
        generatePermutation("", used);
        return this.bestCandidate;
    }

    /**
     * 백트래킹을 사용하여 0-9 숫자의 순열을 생성하고 최적의 후보를 찾는다.
     * @param currentNumberStr 현재까지 만들어진 숫자 문자열
     * @param used 각 숫자의 사용 여부를 나타내는 boolean 배열
     */
    private void generatePermutation(String currentNumberStr, boolean[] used) {
        if (!currentNumberStr.isEmpty()) {
            long currentNum = Long.parseLong(currentNumberStr);
            updateBestCandidate(currentNum);
        }

        for (int i = 0; i < 10; i++) {
            if (!used[i]) {
                used[i] = true;
                generatePermutation(currentNumberStr + i, used);
                used[i] = false;
            }
        }
    }

    /**
     * 새로운 후보 숫자를 현재까지의 최적 후보와 비교하고 필요한 경우 갱신합니다.
     * @param candidate 새로 생성된 후보 숫자
     */
    private void updateBestCandidate(long candidate) {
        long diff = Math.abs(this.targetN - candidate);

        if (this.bestCandidate == -1 || diff < this.minDifference) {
            this.minDifference = diff;
            this.bestCandidate = candidate;
        } else if (diff == this.minDifference) {
            this.bestCandidate = Math.min(this.bestCandidate, candidate);
        }
    }
}