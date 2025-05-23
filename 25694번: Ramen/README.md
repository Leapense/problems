# 25694번: Ramen - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25694)


<p>Grammy likes to eat noodles. She divided a very long strip of noodle into $N$ parts of unit length. Each part $i$ has deliciousness $a_i$. She would like to fold the noodle into one piece of unit length before eating by repeating the following operation several (possibly, zero) times.</p>

<p>Let $n$ be the current length of the noodle. In each operation, Grammy can choose a length $\ell$ such that $2 \ell \leq n$ and $a_i &gt; 0$ for all $i \leq \ell$, and fold the noodle $a_1, a_2, \ldots, a_\ell, a_{\ell + 1}, \ldots, a_{2 \ell}, a_{2 \ell + 1}, \ldots, a_n$ into $a_{\ell + 1} + a_\ell, a_{\ell + 2} + a_{\ell - 1}, \ldots, a_{2 \ell} + a_1, a_{2 \ell + 1}, \ldots, a_n$, where $n$ is the length of the noodle before the operation. After the operation, the length will become $n - \ell$.</p>

<p>Grammy wants to know whether she can fold the noodle to length $1$, can you tell her?</p>



## 입력


<p>The first line of input contains a single integer $N$ ($1 \leq N \leq 100\,000$).</p>

<p>The second line contains $N$ integers $a_i$ ($-20\,000 \leq a_i \leq 20\,000$), representing the deliciousness of each part of the noodle.</p>



## 출력


<p>If Grammy can fold the noodle to length $1$, output a single line with the word "<code>YES</code>". Otherwise, output a single line with the word "<code>NO</code>".</p>



## 소스코드

[소스코드 보기](Ramen.cpp)