# 18788번: Swapity Swap - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18788)


<p>Farmer John's $N$ cows ($1\le N\le 100$) are standing in a line. The $i$th cow from the left has label $i$, for each $1\le i\le N$.</p>

<p>Farmer John has come up with a new morning exercise routine for the cows. He tells them to repeat the following two-step process exactly $K$ ($1\le K\le 10^9$) times:</p>

<ol>
<li>The sequence of cows currently in positions $A_1 \ldots A_2$ from the left reverse their order ($1\le A_1&lt;A_2\le N$).</li>
<li>Then, the sequence of cows currently in positions $B_1 \ldots B_2$ from the left reverse their order ($1\le B_1&lt;B_2\le N$).</li>
</ol>

<p>After the cows have repeated this process exactly $K$ times, please output the label of the $i$th cow from the left for each $1\le i\le N$.</p>



## 입력


<p>The first line of input contains $N$ and $K$. The second line contains $A_1$ and $A_2$, and the third contains $B_1$ and $B_2$.</p>



## 출력


<p>On the $i$th line of output, print the label of the $i$th cow from the left at the end of the exercise routine.</p>



## 소스코드

[소스코드 보기](Swapity%20Swap.cpp)