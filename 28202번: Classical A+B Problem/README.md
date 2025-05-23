# 28202번: Classical A+B Problem - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/28202)


<p>An integer is called a <em>repdigit</em> if it is positive and its decimal representation consists of repeated instances of the same digit. For example, $1$, $666$, $4444$, and $999999$ are repdigits, while $0$, $44244$, $50216$, and $787788$ are not.</p>

<p>You are given a positive integer $n$. It is known that $n$ can be represented as $n = a + b$, where $a$ and $b$ are repdigits. Find any such representation.</p>



## 입력


<p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.</p>

<p>The only line of each test case contains a single integer $n$ without leading zeros ($2 \le n &lt; 10^{4000}$). It is guaranteed that $n$ can be represented as $n = a + b$, where $a$ and $b$ are repdigits.</p>

<p>It is guaranteed that the total number of digits in $n$ over all test cases does not exceed $10^5$.</p>



## 출력


<p>For each test case, print two integers $a$ and $b$ such that $n = a + b$ and both $a$ and $b$ are repdigits.</p>

<p>If there are multiple solutions, print any of them.</p>



## 소스코드

[소스코드 보기](Main.java)