import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    static class Node {
        char c;
        Node prev, next;

        Node(char c) {
            this.c = c;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        Node[] pool = new Node[N];
        int poolPtr = 0;

        Node[] stack = new Node[N];
        int sp = 0;

        Node head = new Node((char) 0), tail = new Node((char) 0);
        head.next = tail;
        tail.prev = head;

        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            if (cmd == 1 || cmd == 2) {
                char ch = st.nextToken().charAt(0);
                Node node = pool[poolPtr++] = new Node(ch);
                if (cmd == 1) {
                    Node prev = tail.prev;
                    prev.next = node;
                    node.prev = prev;
                    node.next = tail;
                    tail.prev = node;
                } else {
                    Node next = head.next;
                    head.next = node;
                    node.prev = head;
                    node.next = next;
                    next.prev = node;
                }
                stack[sp++] = node;
            } else {
                if (sp > 0) {
                    Node node = stack[--sp];
                    Node p = node.prev, n = node.next;
                    p.next = n;
                    n.prev = p;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (Node cur = head.next; cur != tail; cur = cur.next) {
            sb.append(cur.c);
        }

        if (sb.length() == 0) {
            System.out.println("0");
        } else {
            System.out.println(sb.toString());
        }

    }
}
