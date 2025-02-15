# 33439번: V-Diagram - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/33439)


<p>A $1$-indexed integer sequence $a$ of length $n$ is a V-diagram if $n\ge 3$ and there exists an index $i$ ($1&lt; i&lt; n$) satisfying:</p>

<ul>
<li>$a_j&gt;a_{j+1}$ for $1\le j&lt;i$;</li>
<li>$a_j&gt;a_{j-1}$ for $i&lt;j\le n$. </li>
</ul>

<p>Given a V-diagram $a$, find a V-diagram $b$ with maximum average, satisfying that $b$ is a consecutive subsequence of $a$.</p>

<p>Note that a consecutive subsequence of a sequence can be obtained by removing some (possibly zero) elements from the beginning and end of the sequence.</p>



## 입력


<p>Each test contains multiple test cases. The first line contains a single integer $t$ ($1\le t\le 10^5$), denoting the number of test cases.</p>

<p>For each test case, the first line contains one integer $n$ ($3\le n\le 3\cdot10^5$), denoting the length of the integer sequence $a$.</p>

<p>The second line contains $n$ integers $a_1,a_2,\cdots,a_n$ ($1\le a_i\le10^9$), denoting the sequence $a$.</p>

<p>It is guaranteed that $a$ is a V-diagram, and the sum of $n$ over all test cases does not exceed $3\cdot 10^5$.</p>



## 출력


<p>For each test case, output a real number denoting the maximum of the average.</p>

<p>Your answer is considered correct if its absolute or relative error does not exceed $10^{-9}$.</p>

<p>Formally, let your answer be $x$, and the jury's answer be $y$. Your answer is accepted if and only if $\frac{|x-y|}{\max(1,|y|)}\le 10^{-9}$.</p>



## 소스코드

[소스코드 보기](V-Diagram.py)