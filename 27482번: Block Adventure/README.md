# 27482번: Block Adventure - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27482)

<p>Gildong is playing a video game called <em>Block Adventure</em>. In Block Adventure, there are $n$ columns of blocks in a row, and the columns are numbered from $1$ to $n$. All blocks have equal heights. The height of the $i$-th column is represented as $h_i$, which is the number of blocks stacked in the $i$-th column.</p>

<p>Gildong plays the game as a character that can stand only on the top of the columns. At the beginning, the character is standing on the top of the $1$-st column. The goal of the game is to move the character to the top of the $n$-th column.</p>

<p>The character also has a bag that can hold infinitely many blocks. When the character is on the top of the $i$-th column, Gildong can take one of the following three actions as many times as he wants:</p>

<ul>
<li>if there is at least one block on the column, remove one block from the top of the $i$-th column and put it in the bag;</li>
<li>if there is at least one block in the bag, take one block out of the bag and place it on the top of the $i$-th column;</li>
<li>if $i&lt;n$ and $|h_i-h_{i+1}|\le k$, move the character to the top of the $i+1$-st column. $k$ is a non-negative integer given at the beginning of the game. Note that it is only possible to move to the <strong>next</strong> column.</li>
</ul>

<p>In actions of the first two types the character remains in the $i$-th column, and the value $h_i$ changes.</p>

<p>The character initially has $m$ blocks in the bag. Gildong wants to know if it is possible to win the game. Help Gildong find the answer to his question.</p>

## 입력

<p>Each test contains one or more test cases. The first line contains the number of test cases $t$ ($1\le t\le 1000$). Description of the test cases follows.</p>

<p>The first line of each test case contains three integers $n$, $m$, and $k$ ($1\le n\le 100$, $0\le m\le 10^6$, $0\le k\le 10^6$) --- the number of columns in the game, the number of blocks in the character’s bag at the beginning, and the non-negative integer $k$ described in the statement.</p>

<p>The second line of each test case contains $n$ integers. The $i$-th integer is $h_i$ ($0\le h_i\le 10^6$), the initial height of the $i$-th column.</p>

## 출력

<p>For each test case, print “<code>YES</code>” if it is possible to win the game. Otherwise, print “<code>NO</code>”.</p>

<p>You can print each letter in any case (upper or lower).</p>

## 소스코드

[소스코드 보기](Block%20Adventure.py)