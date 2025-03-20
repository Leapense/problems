# 19440번: It's All In The Mind - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/19440)


<p>Professor Zhang has a number sequence $a_1, a_2, \ldots, a_n$. However, the sequence is not complete and some elements are missing. Fortunately, Professor Zhang remembers some attributes of the sequence:</p>

<ul>
<li>For every $i \in \{1, 2, \ldots, n\}$, $0 \le a_i \le 100$.</li>
<li>The sequence is non-increasing: $a_1 \ge a_2 \ge \ldots \ge a_n$.</li>
<li>The sum of all elements in the sequence is not zero.</li>
</ul>

<p>Professor Zhang wants to know the maximum value of $\frac{a_1 + a_2}{\sum_{i = 1}^{n}{a_i}}$ among all the possible sequences.</p>



## 입력


<p>There are multiple test cases. The first line of input contains an integer $T$ indicating the number of test cases. For each test case:</p>

<p>The first line contains two integers $n$ and $m$ ($2 \le n \le 100$, $0 \le m \le n$): the length of the sequence and the number of known elements.</p>

<p>Each of the next $m$ lines contains two integers $x_i$ and $y_i$ ($1 \le x_i \le n$, $0 \le y_i \le 100$, $x_i &lt; x_{i + 1}$, $y_i \ge y_{i + 1}$) indicating that $a_{x_i} = y_i$.</p>

<p>There are at most $2000$ test cases, and the total size of the input is no more than $350$ kibibytes.</p>



## 출력


<p>For each test case, output the answer as an irreducible fraction $p$<code>/</code>$q$ where $p$ and $q$ are integers, and $q &gt; 0$.</p>



## 소스코드

[소스코드 보기](It's%20All%20In%20The%20Mind.cpp)