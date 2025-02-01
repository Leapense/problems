# 26235번: Chairs - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26235)


<p>Ostap and Kisa found themselves at a chair sale. They are facing two problems. First, they must leave the sale as soon as possible, because their rival company, represented by father Theodore, is breathing down their necks; second, they must get all chairs at the sale.</p>

<p>The sale site is a rectangular table of $N$ rows and $M$ columns, with some of its cells occupied by chairs that need to be collected. Initially our enterpreneurs are in the top-left corner  --- the cell with the coordinates $(1, 1)$, and the exit is located in the bottom-right corner  --- the cell with the coordinates $(N, M)$. A single move can transfer them from a given sell to any of adjacent by a side cells. Passing through a cell with a chair, they take the chair with them. Find a shortest path from the starting to the ending cell. Among all such paths, find one passing through all cells with chairs, or find out if such a path doesn't exist.</p>



## 입력


<p>The first line contains three integers: $N$, $M$, $K$  --- size of the table and the number of chairs,  respectively ($2 \le N, M \le 100$, $0 \le K \le 1000$).</p>

<p>The following $K$ lines of the input data each contain two integers: $X_i$  --- the number of the row in which the $i$-th chair is located, and $Y_i$  --- the number of the column in which the $i$-th chair is located ($1 \le X_i \le N$, $1 \le Y_i \le M$). A single cell cannot contain multiple chairs.</p>



## 출력


<p>If collecting all chairs along any single shortest path is impossible, print a single word  &lt;&lt;<code>Impossible</code>&gt;&gt; (without brackets) in the output file.</p>

<p>If such a path exists, print it as a line containing the sequence of moves, with each move coded by a single symbol according to the following:</p>

<ul>
<li><code>R</code>  --- move right;</li>
<li><code>D</code>  --- move down;</li>
</ul>

<p>If several solutions are possible, print the lexicographically smallest solution.</p>



## 소스코드

[소스코드 보기](Chairs.py)