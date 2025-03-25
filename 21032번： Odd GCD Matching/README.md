# 21032번: Odd GCD Matching - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21032)


<p>Supposed there are N integers A<sub>1..N</sub>. A<sub>i</sub> can be paired with A<sub>j</sub> if GCD(A<sub>i</sub>, A<sub>j</sub>) is an odd number. GCD(a, b) is the greatest common divisor of a and b. For example, 6 can be paired with 9 because GCD(6, 9) = 3 is an odd number; however, 12 cannot be paired with 8 because GCD(12, 8) = 4 is an even number.</p>

<p>An odd GCD matching of A<sub>1..N</sub> is a set of pairs which satisfies the following.</p>

<ul>
<li>Each pair contains two integers (i, j) where 1 ≤ i &lt; j ≤ N.</li>
<li>Each integer i only appears at most once in the set.</li>
<li>If (i, j) is in the set, then Ai must be able to be paired with A<sub>j</sub>.</li>
</ul>

<p>Given A<sub>1..N</sub>, your task is to find the size of a maximum odd GCD matching of A<sub>1..N</sub>. An odd GCD matching is maximum if and only if there are no other odd GCD matching which has more pairs than it.</p>

<p>For example, let A<sub>1..5</sub> = {6, 8, 9, 12, 13}. The size of a maximum odd GCD matching in this example is 2; one such example is {(1, 3),(2, 5)} which corresponds to the pairs (A<sub>1</sub> = 6 with A<sub>3</sub> = 9) and (A<sub>2</sub> = 8 with A<sub>5</sub> = 13). Note that {(1, 3)} with the size of 1 is also a valid odd GCD matching, but it is not a maximum one. On the other hand, {(2, 4)} is not a valid odd GCD matching as A<sub>2</sub> = 8 cannot be paired with A<sub>4</sub> = 12 in this example.</p>



## 입력


<p>Input begins with a line containing an integer: N (1 ≤ N ≤ 20 000) representing the size of A. The next line contains N integers: A<sub>i</sub> (1 ≤ A<sub>i</sub> ≤ 10<sup>6</sup>) representing the array A.</p>



## 출력


<p>Output in a line an integer representing the size of a maximum odd GCD matching of A<sub>1..N</sub>.</p>



## 소스코드

[소스코드 보기](Odd%20GCD%20Matching.cpp)