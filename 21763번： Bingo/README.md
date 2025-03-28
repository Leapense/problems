# 21763번: Bingo - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21763)


<p><strong>Bingo</strong> is a game on a square grid. Each player gets an $n \times n$ grid and writes a unique number in each cell. The game host then draws a random number, and each player looks for that number on their grid and, if the number is present on their grid, fills in the corresponding cell. This repeats until someone finds $n$ filled cells on a single line, which we will call a <strong>bingo line</strong>.</p>

<p>There are $2n + 2$ possible bingo lines: $n$ horizontal lines, $n$ vertical lines, and $2$ diagonal lines.</p>

<pre>---  ...  ...  |..  .|.  ..|  \..  ../
...  ---  ...  |..  .|.  ..|  .\.  ./.
...  ...  ---  |..  .|.  ..|  ..\  /..</pre>

<p>For example, the following grid has four bingo lines: two horizontal lines, one vertical line, and one diagonal line.</p>

<pre>#..#.
#####
..###
#####
..###</pre>

<p>Exactly when is a bingo line formed? That is completely random: you can get a line quite early if you are lucky, but on the other hand, you can fill most of the grid without getting any bingo lines. In this problem, we investigate the unfortunate case of filling $k$ cells without making any bingo lines.</p>

<p>Given two integers $n$ and $k$, determine whether it is possible to fill exactly $k$ cells in an $n \times n$ grid, without making any bingo lines. If it's possible, demonstrate how to do it.</p>



## 입력


<p>The first and only line of input contains two integers, $n$ and $k$.</p>



## 출력


<p>On the first line, output <code>YES</code> if it's possible to fill exactly $k$ cells of an $n \times n$ grid without making any bingo lines. Otherwise, output <code>NO</code>.</p>

<p>If the answer is <code>YES</code>, then output each row of the grid starting from the next line. Each row should be represented by a string of $n$ characters. The $i$-th character is <code>#</code> (ASCII 35) if the $i$-th cell of the row is filled, and <code>.</code> (ASCII 46) if it's not filled. Exactly $k$ cells must be filled, and there cannot be any bingo lines.</p>

<p>If there are multiple ways to fill the grid, then output any one of them.</p>



## 소스코드

[소스코드 보기](Bingo.cpp)