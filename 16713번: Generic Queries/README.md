# 16713번: Generic Queries - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16713)


<p>관영이는 쿼리를 좋아하고, XOR도 좋아한다. 그래서 관영이는 XOR을 이용한 쿼리 문제를 좋아한다.</p>

<p>길이가 $N$인 수열 $a_1 , a_2 , \cdots a_N$이 있다.&nbsp;</p>

<p>이제 관영이는 $Q$개의 쿼리에 답하려 한다. 각 쿼리는 $s_i , e_i$ ($1 \le s_i \le e_i \le N$)의 형태로 들어오고, 그 쿼리의 답은 $a_{s_i}, a_{s_i+1}, \cdots&nbsp;a_{e_i}$을 모두 XOR한 값이다.&nbsp;</p>

<p>$Q$개의 쿼리가 들어올 때, 각 쿼리의 답을 모두 XOR한 결과를 구하시오.&nbsp;</p>



## 입력


<p>첫째 줄에는 $N, Q$가 공백을 사이에 두고 주어진다. ($1 \le N \le 10^6$, $1 \le Q \le 3 \cdot 10^6$)</p>

<p>둘째 줄에는 $a_1, a_2, \cdots a_N$이 공백을 사이에 두고 주어진다. ($0 \le&nbsp;a_i \le 10^9$)</p>

<p>그 후, $Q$개의 줄에 걸쳐서, 각 줄마다 하나의 쿼리 $s_i, e_i$가 공백을 사이에 두고 주어진다. ($1 \le s_i \le e_i \le N$)&nbsp;</p>



## 출력


<p>모든 쿼리의 답을 XOR한 값을 출력하시오.&nbsp;</p>



## 소스코드

[소스코드 보기](Generic%20Queries.cpp)