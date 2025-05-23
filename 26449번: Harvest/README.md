# 26449번: Harvest - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26449)


<p>Today is the Age of Agriculture.</p>

<p>As a member of Japan Agriculture Group (JAG), you grow $N$ kinds of plants this year. Each plant has different harvest seasons: the $i$-th plant must be gathered at some day between $s_i$ and $t_i$, inclusive.</p>

<p>You plan to gather plants $K$ times, where the $j$-th gathering day is $h_j$. On the $j$-th gethering day, if the $i$-th plant has not been gathered yet and the gathering day is within the harvest season of the $i$-th plant, that is $s_i \le h_j \le t_i$, you have to gather the $i$-th plant.</p>

<p>You are not sure whether your planned days are sufficient to gather all the $N$ plants. If not, you would not be able to survive this cruel Age of Agriculture. Thus you decided to write a program to compute the number of plants gathered after $K$ gathering days you planned.</p>



## 입력


<p>The input consists of a single test case of the following format.</p>

<blockquote>
<p>$N$</p>

<p>$s_1$ $t_1$</p>

<p>$\vdots$</p>

<p>$s_N$ $t_N$</p>

<p>$K$</p>

<p>$h_1$</p>

<p>$\vdots$</p>

<p>$h_K$</p>
</blockquote>

<p>The first line is the number $N$ of plants you will grow ($1 \le N \le 10^5$). The $i$-th of the following $N$ lines consists of two integers $s_i$ and $t_i$, which represent that the harvest season of the $i$-th plant is $[s_i,t_i]$ ($1 \le s_i \le t_i \le 10^9$).</p>

<p>The following line contains the number $K$ of the gathering days you plan ($1 \le K \le 10^5$). The j-th of the following $K$ lines contains an integer $h_j$ ($1 \le h_j \le 10^9$), which is the $j$-th gathering day you plan. You can assume that holds $h_j &lt; h_{j+1}$ for $1 \le j \le K-1$.</p>



## 출력


<p>Print the number of plants gathered after your planned gathering days.</p>



## 소스코드

[소스코드 보기](Harvest.cpp)