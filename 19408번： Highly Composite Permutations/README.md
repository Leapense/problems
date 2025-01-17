# 19408번: Highly Composite Permutations - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/19408)


<p>Positive integer $x$ is called <em>composite</em> if it has strictly more than two positive integer divisors. For example, integers 4, 30 and 111 are composite, while 1, 7 and 239 are not.</p>

<p>Integer sequence $p = \langle p_1, p_2, \ldots, p_n \rangle$ is called a <em>permutation of length $n$</em> if it contains every integer between 1 and $n$, inclusive, exactly once.</p>

<p>We'll call permutation $p = \langle p_1, p_2, \ldots, p_n \rangle$ <em>highly composite</em> if for every $i$ between 1 and $n$, inclusive, the sum of the first $i$ elements of $p$ (that is, $p_1 + p_2 + \ldots + p_i$) is composite.</p>

<p>Given a single integer $n$, find a highly composite permutation of length $n$.</p>



## 입력


<p>The only line of the input contains a single integer $n$ ($1 \le n \le 100$).</p>



## 출력


<p>If no highly composite permutation of length $n$ exists, output a single integer $-1$. Otherwise, output $n$ integers $p_1, p_2, \ldots, p_n$ such that $p = \langle p_1, p_2, \ldots, p_n \rangle$ is a highly composite permutation.</p>

<p>If there are multiple highly composite permutations of length $n$, you may output any of them.</p>



## 소스코드

[소스코드 보기](Highly%20Composite%20Permutations.cpp)