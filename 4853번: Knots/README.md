# 4853번: Knots - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4853)


<p>An even number N of strands are stuck through a wall. On one side of the wall, a girl ties N/2 knots between disjoint pairs of strands. On the other side of the wall, the girl's groom−to−be also ties N/2 knots between disjoint pairs of strands. You are to find the probability that the knotted strands form one big loop (in which case the couple will be allowed to marry).</p>

<p>For example, suppose that N = 4 and you number the strands 1, 2, 3, 4. Also suppose that the girl has created the following pairs of strands by tying knots: {(1, 4), (2,3)}. Then the groom−to−be has two choices for tying the knots on his side: {(1,2), {3,4)} or {(1,3), (2,4)}.</p>



## 입력


<p>The input file consists of one or more lines. Each line of the input file contains a positive even integer, less than or equal to 100. This integer represents the number of strands in the wall.</p>



## 출력


<p>For each line of input, the program will produce exactly one line of output: the probability that the knotted strands form one big loop, given the number of strands on the corresponding line of input. Print the probability to 5 decimal places.</p>



## 소스코드

[소스코드 보기](Knots.cpp)