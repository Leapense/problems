# 27488번: Sum of Two Numbers - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27488)

<p>The sum of digits of a non-negative integer $a$ is the result of summing up its digits together when written in the decimal system. For example, the sum of digits of $123$ is $6$ and the sum of digits of $10$ is $1$.</p>

<p>In a formal way, the sum of digits of $\displaystyle a=\sum_{i=0}^{\infty} a_i \cdot 10^i$, where $0 \leq a_i \leq 9$, is defined as $\displaystyle\sum_{i=0}^{\infty}{a_i}$.</p>

<p>Given an integer $n$, find two non-negative integers $x$ and $y$ which satisfy the following conditions.</p>

<ul>
<li> $x+y=n$, and</li>
<li>The sum of digits of $x$ and the sum of digits of $y$ differ by at most $1$.</li>
</ul>

<p>It can be shown that such $x$ and $y$ always exist.</p>

## 입력

<p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10\,000$). </p>

<p>Each test case consists of a single integer $n$ ($1 \leq n \leq 10^9$)</p>

## 출력

<p>For each test case, print two integers $x$ and $y$.</p>

<p>If there are multiple answers, print any.</p>

## 소스코드

[소스코드 보기](Sum%20of%20Two%20Numbers.cpp)