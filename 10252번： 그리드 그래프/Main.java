import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine().trim());
        for (int t = 0; t < T; t++) {
            String[] parts = br.readLine().trim().split("\\s+");
            int m = Integer.parseInt(parts[0]);
            int n = Integer.parseInt(parts[1]);
            List<String> cycle = new ArrayList<>();
            if (m % 2 == 0) {
                for (int i = 0; i < m; i++) {
                    if (i % 2 == 0) {
                        for (int j = 0; j < n; j++) {
                            cycle.add("(" + i + "," + j + ")");
                        }
                    } else {
                        for (int j = n - 1; j >= 0; j--) {
                            cycle.add("(" + i + "," + j + ")");
                        }
                    }
                }
            } else {
                if (n % 2 == 0) {
                    // 열 스네이크 순서
                    for (int j = 0; j < n; j++) {
                        if (j % 2 == 0) {
                            for (int i = 0; i < m; i++) {
                                cycle.add("(" + i + "," + j + ")");
                            }
                        } else {
                            for (int i = m - 1; i >= 0; i--) {
                                cycle.add("(" + i + "," + j + ")");
                            }
                        }
                    }
                } else {
                    // m, n 모두 홀수: 첫 행만 반대, 이후 행은 정방향
                    // 첫 행: 오른쪽->왼쪽
                    for (int j = n - 1; j >= 0; j--) {
                        cycle.add("(0," + j + ")");
                    }
                    for (int i = 1; i < m; i++) {
                        for (int j = 0; j < n; j++) {
                            cycle.add("(" + i + "," + j + ")");
                        }
                    }
                }
            }
            out.println(1);
            for (String s : cycle) {
                out.println(s);
            }
        }
        out.flush();
    }
}
