import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * GlobalWarming 문제를 스위프 라인과 DSU를 사용하여 효율적으로 해결하는 클래스입니다.
 */
public class Main {

    /**
     * 지형의 고도와 인덱스를 저장하는 내부 클래스입니다.
     * Comparable을 구현하지 않고, 정렬 시 Comparator를 사용합니다.
     */
    static class Point {
        int altitude;
        int index;

        Point(int altitude, int index) {
            this.altitude = altitude;
            this.index = index;
        }
    }

    /**
     * Disjoint Set Union (DSU) 자료구조를 구현한 내부 클래스입니다.
     * 경로 압축과 (단순) 합병을 사용합니다.
     */
    static class DSU {
        int[] parent;
        // int n; // SonarQube: Private field 'n' is assigned but never read. 제거.

        DSU(int count) {
            // this.n = count; // 제거
            parent = new int[count];
            for (int i = 0; i < count; i++) {
                parent[i] = i;
            }
        }

        int find(int i) {
            if (parent[i] == i) {
                return i;
            }
            parent[i] = find(parent[i]); // Path compression
            return parent[i];
        }

        /**
         * 두 원소 i와 j가 속한 집합을 합칩니다.
         * @param i 첫 번째 원소
         * @param j 두 번째 원소
         * @return 합병이 실제로 일어났으면 (원래 다른 집합이었으면) true, 아니면 false
         */
        boolean union(int i, int j) {
            int rootI = find(i);
            int rootJ = find(j);
            if (rootI != rootJ) {
                parent[rootI] = rootJ; // Simple union by making rootI child of rootJ
                return true;
            }
            return false;
        }
    }

    /**
     * 프로그램의 주 진입점입니다.
     * @param args 명령줄 인자 (사용되지 않음)
     * @throws IOException 입력 오류 발생 시
     */
    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(reader.readLine());

            if (n == 0) {
                System.out.println(0);
                return;
            }

            List<Integer> altitudesList = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                altitudesList.add(Integer.parseInt(reader.readLine()));
            }

            int maxIslands = 0;

            // 1. 해수면이 0일 때의 섬 개수 계산
            // 고도가 0보다 큰 육지들로 이루어진 섬을 셉니다.
            if (n > 0) { // n=0은 위에서 처리되었지만, 명시적으로.
                int islandsAtSeaLevelZero = 0;
                boolean submergedPreviously = true;
                for (int altitude : altitudesList) {
                    if (altitude > 0) { // 고도 0인 땅은 해수면 0에서 잠김
                        if (submergedPreviously) {
                            islandsAtSeaLevelZero++;
                        }
                        submergedPreviously = false;
                    } else {
                        submergedPreviously = true;
                    }
                }
                maxIslands = islandsAtSeaLevelZero;
            }


            // 2. 스위프 라인: 해수면이 h_unique - epsilon (h_unique > 0)일 때
            // 즉, 고도 h_unique 이상인 땅들로 이루어진 섬을 고려합니다.
            
            List<Point> points = new ArrayList<>();
            Set<Integer> uniquePositiveAltitudesSet = new HashSet<>();

            for (int i = 0; i < n; i++) {
                int alt = altitudesList.get(i);
                if (alt > 0) { // 스위프 라인은 양의 고도에 대해서만 진행
                    points.add(new Point(alt, i));
                    uniquePositiveAltitudesSet.add(alt);
                }
            }

            if (!points.isEmpty()) {
                // Point들을 고도 내림차순, 인덱스 오름차순으로 정렬
                points.sort((p1, p2) -> {
                    if (p1.altitude != p2.altitude) {
                        return Integer.compare(p2.altitude, p1.altitude); // 고도 내림차순
                    }
                    return Integer.compare(p1.index, p2.index); // 인덱스 오름차순 (일관성 위함)
                });

                List<Integer> uniquePositiveAltitudesDesc = new ArrayList<>(uniquePositiveAltitudesSet);
                uniquePositiveAltitudesDesc.sort(Comparator.reverseOrder()); // 고유 양의 고도 내림차순

                DSU dsu = new DSU(n);
                boolean[] isActive = new boolean[n]; // 현재 땅이 드러났는지 여부
                int currentIslandCount = 0;
                int pointCursor = 0; // points 리스트를 순회하는 커서

                // 각 고유 양의 고도를 기준으로 스위프
                for (int currentProcessingAltitude : uniquePositiveAltitudesDesc) {
                    List<Integer> newlyActivatedIndices = new ArrayList<>();

                    // 현재 처리 중인 고도(currentProcessingAltitude)를 가진 모든 땅을 활성화
                    while (pointCursor < points.size() && points.get(pointCursor).altitude == currentProcessingAltitude) {
                        Point currentPoint = points.get(pointCursor);
                        int idx = currentPoint.index;
                        
                        // isActive[idx]는 이 시점에서 false여야 함 (더 높은 고도에서 이미 처리되지 않았다면)
                        // 이 조건은 중복 활성화를 방지 (이론적으로는 불필요할 수 있음)
                        if (!isActive[idx]) { 
                           isActive[idx] = true;
                           // DSU에서 각 노드는 초기에 자신을 부모로 가짐 (별도 컴포넌트)
                           currentIslandCount++; 
                           newlyActivatedIndices.add(idx);
                        }
                        pointCursor++;
                    }

                    // 새로 활성화된 땅들을 주변의 이미 활성화된 땅들과 합병 시도
                    for (int idx : newlyActivatedIndices) {
                        // 왼쪽 인접 땅 확인
                        if (idx - 1 >= 0 && isActive[idx - 1]) {
                            if (dsu.union(idx, idx - 1)) { // 합병 성공 시 섬 개수 감소
                                currentIslandCount--;
                            }
                        }
                        // 오른쪽 인접 땅 확인
                        if (idx + 1 < n && isActive[idx + 1]) {
                            if (dsu.union(idx, idx + 1)) { // 합병 성공 시 섬 개수 감소
                                currentIslandCount--;
                            }
                        }
                    }
                    // 현재 currentIslandCount는 해수면이 currentProcessingAltitude 보다 약간 낮을 때의 섬 개수
                    maxIslands = Math.max(maxIslands, currentIslandCount);
                }
            }
            
            System.out.println(maxIslands);
        }
    }
}