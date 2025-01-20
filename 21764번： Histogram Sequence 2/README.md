# 21764번: Histogram Sequence 2 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21764)


<p>A 2-dimensional grid can be represented as a set of pairs of positive integers. Each cell can be numbered as in the figure below:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/fbe7c2c9-940f-4c99-a588-0f84b4fa62af/-/preview/" style="width: 339px; height: 233px;"></p>

<p>Suppose you are given a histogram where the height of each column is $h_1, h_2, \cdots, h_N$. Its area can be represented as a set containing cells $(i, 1), (i, 2), \cdots, (i, h_i)$ for $i = 1, 2, \cdots, N$. (If $h_i = 0$, it means the histogram's area does not contain any cell from the $i$-th column.)</p>

<p>You may choose $N$ integers $x_1, x_2, \cdots, x_N$ with $0 \le x_i &lt; h_i$ and subtract a sub-histogram with heights $x_1, x_2, \cdots, x_N$. After removing such a sub-histogram, the remaining area can be written as: $$ \bigcup_{i=1}^N \{ (i, j) : x_i &lt; j \le h_i \}. $$</p>

<p>For example, the following figure shows an example of $h_1 = 4$, $h_2 = 5$, $h_3 = 4$, $h_4 = 4$ and $x_1 = 1$, $x_2 = 2$, $x_3 = 3$, $x_4 = 2$.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d59fd676-bdae-4dd9-a5ac-38a4d777c921/-/preview/" style="width: 141px; height: 172px;"></p>

<p>The remaining area is called <em>connected</em> if for every pair of cells $((r_1, c_1), (r_2, c_2))$ in the remaining area, one can move from $(r_1, c_1)$ to $(r_2, c_2)$ using only the following moves without leaving the remaining area:</p>

<ul>
<li>$(r, c) \to (r+1, c)$</li>
<li>$(r, c) \to (r-1, c)$</li>
<li>$(r, c) \to (r, c+1)$</li>
<li>$(r, c) \to (r, c-1)$</li>
</ul>

<p>Compute the number of ways to choose $(x_1, x_2, \cdots, x_N)$ such that the remaining area is connected.</p>



## 입력


<p>The first line contains a single integer, $N$. The second line contains $N$ integers - $h_1, h_2, \cdots, h_N$ in order.</p>



## 출력


<p>Output the number of ways to choose $(x_1, x_2, \cdots, x_N)$ such that the remaining area is connected, modulo $10^9 + 7$.</p>



## 소스코드

[소스코드 보기](Histogram%20Sequence%202.py)