# 32675번: Pascal Multiple - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32675)


<p>The $(i,j)$th binomial coefficient, denoted $C(i,j)$, is the (zero-indexed) $j$th entry of the (zero-indexed) $i$th row in Pascal's triangle:</p>

<pre>1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
...
</pre>

<p>where $C(0,0) = 1$ and the $(i+1)$st row can be computed from the $i$th row using the recursion $$C(i+1, j) = C(i,j) + C(i, j-1),$$ treating as $0$ any out-of-bounds entries of the triangle on the right-hand side.</p>

<p>Given $N$ and $K$, compute how many entries in the first $N+1$ rows of Pascal's triangle are multiples of $K$. To be precise: for how many pairs of indices $(i,j)$ with $0\leq i\leq N$ and $0 \leq j \leq i$, is $C(i,j)$ divisible by $K$?</p>



## 입력


<p>The single line of input contains two positive integers $N$ $(1 \leq N \leq 10^3)$ and $K$ $(1 \leq K \leq N)$, with meaning as described above.</p>



## 출력


<p>Print the number of entries in the first $N+1$ rows of Pascal's triangle that are divisible by $K$.</p>



## 소스코드

[소스코드 보기](Main.java)