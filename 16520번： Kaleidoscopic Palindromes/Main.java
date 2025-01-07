import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // 입력 받기: 세 개의 정수 a, b, k를 입력
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        /*
         * k = 2인 경우:
         * a부터 b까지의 각 숫자 n에 대해:
         * n을 진법 2로 변환한다.
         * 변환된 문자열이 팰린드롬인지 확인한다.
         * 팰린드롬인 경우, 카운트를 증가시킨다.
         * 최종적으로 카운트를 출력한다.
         * 
         * k > 2인 경우:
         * 0과 1이 [a, b] 범위에 포함되는지 확인한다.
         * 포함된다면 각각을 카운트한다.
         * 최종적으로 카운트를 출력한다.
         */
        if (k == 2) {
            int count = 0;
            for (int i = a; i <= b; i++) {
                String binary = Integer.toBinaryString(i);
                if (isPalindrome(binary)) {
                    count++;
                }
            }
            System.out.println(count);
        } else {
            int count = 0;
            if (a <= 0 && 0 <= b) count++;
            if (a <= 1 && 1 <= b) count++;
            System.out.println(count);
        }
    }

    public static boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}