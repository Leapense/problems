import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public final class Main {
    private static final int TOP_RANK_LIMIT = 6;

    private Main() {
        throw new IllegalStateException("Utility class");
    }

    static class CarNode {
        private final int carId;
        private CarNode prev;
        private CarNode next;

        public CarNode(int carId) {
            this.carId = carId;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        CarNode[] carNodes = new CarNode[n + 1];
        CarNode head = initializeRace(n, carNodes);

        for (int i = 0; i < k; i++) {
            int overtakingCarId = Integer.parseInt(br.readLine());
            CarNode overtakingNode = carNodes[overtakingCarId];

            if (overtakingNode.prev != null) {
                head = performOvertake(overtakingNode, head);
            }
        }

        printResults(head, n);
    }

    private static CarNode initializeRace(int n, CarNode[] carNodes) {
        if (n <= 0) {
            return null;
        }
        
        CarNode head = new CarNode(1);
        carNodes[1] = head;
        CarNode prevNode = head;

        for (int i = 2; i <= n; i++) {
            CarNode currentNode = new CarNode(i);
            carNodes[i] = currentNode;
            prevNode.next = currentNode;
            currentNode.prev = prevNode;
            prevNode = currentNode;
        }
        return head;
    }

    private static CarNode performOvertake(CarNode C, CarNode head) {
        final CarNode P = C.prev;

        P.next = C.next;
        if (C.next != null) {
            C.next.prev = P;
        }

        C.prev = P.prev;
        C.next = P;

        if (P.prev != null) {
            P.prev.next = C;
        }

        P.prev = C;

        if (head == P) {
            return C;
        }

        return head;
    }

    private static void printResults(CarNode head, int n) {
        StringBuilder sb = new StringBuilder();
        CarNode currentNode = head;
        int count = 0;
        int limit = Math.min(n, TOP_RANK_LIMIT);

        while (currentNode != null && count < limit) {
            sb.append(currentNode.carId);
            count++;
            if (count < limit) {
                sb.append(" ");
            }
            currentNode = currentNode.next;
        }

        System.out.println(sb.toString());
    }
}