import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // 1) Fast I/O 세팅
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), q = Integer.parseInt(st.nextToken());

        // 2) A 읽고 정렬
        int[] a = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(a);

        // 3) 중복 제거 후 고유값 리스트 생성
        int uniqueCount = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[uniqueCount - 1]) {
                a[uniqueCount++] = a[i];
            }
        }

        // 4) 결측 수 누적(missingCount[i] = a[i] - i)
        int[] miss = new int[uniqueCount];
        for (int i = 0; i < uniqueCount; i++) {
            miss[i] = a[i] - i;
        }

        // 5) 쿼리 처리
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer(br.readLine());
        while (q-- > 0) {
            int k = Integer.parseInt(st.nextToken());

            // 5-1) 첫 구간에 속할 때
            if (k <= miss[0]) {
                // 0부터 누락된 수가 miss[0]개이므로 k번째는 k-1
                bw.write((k - 1) + " ");
                continue;
            }

            // 5-2) miss[idx] < k 인 가장 큰 idx 찾기 (upper bound)
            int lo = 0, hi = uniqueCount - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) >>> 1;
                if (miss[mid] < k)
                    lo = mid;
                else
                    hi = mid - 1;
            }
            // idx = lo
            int idx = lo;
            // 5-3) 결과 계산
            int beforeMissing = miss[idx];
            int ai = a[idx];
            int answer = ai + (k - beforeMissing);
            bw.write(answer + " ");
        }

        // 6) flush
        bw.newLine();
        bw.flush();
    }
}