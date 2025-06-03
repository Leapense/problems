import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public final class Main {
    public static void main(final String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String line = bufferedReader.readLine();

        if (line == null) {
            System.out.println("no route found");
            return;
        }

        int numberOfPieces;
        try {
            numberOfPieces = Integer.parseInt(line.trim());
        } catch (NumberFormatException e) {
            System.out.println("no route found");
            return;
        }

        /*
         * 1) 인접 리스트를 완전한 무방향 그래프로 빌드한다.
         *    - 예를 들어, "A B" 가 주어지면 A→B 와 B→A 둘 다 추가.
         *    - 조각으로 등장하지 않는 노드(역)도 키(key)로 자동 생성.
         */
        Map<String, List<String>> adjacencyMap = new HashMap<>();

        for (int i = 0; i < numberOfPieces; i++) {
            String inputLine = bufferedReader.readLine();
            if (inputLine == null || inputLine.isBlank()) {
                continue;
            }

            StringTokenizer tokenizer = new StringTokenizer(inputLine);
            String stationName = tokenizer.nextToken().trim();

            // 첫 토큰(역 이름)이 맵에 없으면 빈 리스트 할당
            adjacencyMap.computeIfAbsent(stationName, key -> new ArrayList<>());

            while (tokenizer.hasMoreTokens()) {
                String neighbor = tokenizer.nextToken().trim();
                if (neighbor.isEmpty()) {
                    continue;
                }

                // stationName → neighbor 간선 추가
                adjacencyMap.get(stationName).add(neighbor);

                // neighbor → stationName 간선도 추가 (무방향)
                adjacencyMap.computeIfAbsent(neighbor, key -> new ArrayList<>());
                adjacencyMap.get(neighbor).add(stationName);
            }
        }

        // 마지막 줄: "출발역(start) 목적지역(destination)"
        String lastLine = bufferedReader.readLine();
        if (lastLine == null || lastLine.isBlank()) {
            System.out.println("no route found");
            return;
        }

        StringTokenizer tokenizer = new StringTokenizer(lastLine);
        String startStation = tokenizer.nextToken().trim();
        String destinationStation = tokenizer.nextToken().trim();

        String result = findRoute(adjacencyMap, startStation, destinationStation);
        System.out.println(result);
    }

    /**
     * 완전한 무방향 그래프를 이용해 BFS로 경로를 탐색한다.
     *
     * @param adjacencyMap       역 전체를 키로 삼는 인접 리스트 맵
     * @param startStation       출발역 이름
     * @param destinationStation 목적지역 이름
     * @return 경로가 있으면 "역1 역2 ... 목적지역", 없으면 "no route found"
     */
    private static String findRoute(final Map<String, List<String>> adjacencyMap,
                                    final String startStation,
                                    final String destinationStation) {
        // 출발역이 그래프에 없으면 곧바로 실패
        if (!adjacencyMap.containsKey(startStation)) {
            return "no route found";
        }

        // BFS 자료구조 초기화
        Deque<String> queue = new ArrayDeque<>();
        Set<String> visited = new HashSet<>();
        Map<String, String> parentMap = new HashMap<>();

        // 시작점 설정
        queue.addLast(startStation);
        visited.add(startStation);

        boolean isReachable = false;

        // BFS 반복
        while (!queue.isEmpty()) {
            String currentStation = queue.pollFirst();

            if (currentStation.equals(destinationStation)) {
                // 목적지 발견
                isReachable = true;
                break;
            }

            List<String> neighbors = adjacencyMap.get(currentStation);
            if (neighbors == null) {
                // (정상적으로는 null이 될 수 없음—그래프 빌드 시 항상 createIfAbsent 했으므로)
                continue;
            }

            for (String neighbor : neighbors) {
                if (visited.contains(neighbor)) {
                    continue;
                }
                // 부모 정보 저장
                parentMap.put(neighbor, currentStation);

                if (neighbor.equals(destinationStation)) {
                    // 목적지 발견 시 즉시 탐색 종료
                    isReachable = true;
                    queue.clear();
                    break;
                }

                visited.add(neighbor);
                queue.addLast(neighbor);
            }
        }

        if (!isReachable) {
            return "no route found";
        }

        // 경로 복원: 목적지 역부터 출발역까지 거슬러 올라가며 리스트 생성
        List<String> path = new ArrayList<>();
        String cursor = destinationStation;
        path.add(cursor);

        while (!cursor.equals(startStation)) {
            String parent = parentMap.get(cursor);
            if (parent == null) {
                // 부모 정보가 없으면 경로가 잘못된 것
                return "no route found";
            }
            path.add(0, parent);
            cursor = parent;
        }

        return String.join(" ", path);
    }
}