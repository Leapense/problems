# 30570번: Mini-Tetris 3023 - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30570)


<p>A guy named Gry found a new game called "Mini-Tetris 3023". This small version of Tetris is played on a very long grid only $2$ cells high and has just three types of tile:</p>

<ul>
<li>A <code>square</code> made out of $4$ tiles in a $2 \times 2$ grid.</li>
<li>An <code>S-tile</code> made out of $4$ tiles, $2$ on one row and $2$ slightly offset on the other</li>
<li>A <code>corner</code> made out of $3$ tiles, $1$ on one row and $2$ on the other</li>
</ul>

<p>Tiles may be rotated $0$, $90$, $180$, or $270$ degrees to fit amongst each other, however, they cannot overlap or go outside the vertical boundary of the grid.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/4ee70ed0-3d25-4d44-8baf-be617bfab4cd/-/preview/" style="width: 335px; height: 100px;"></p>

<p>This game provides $a$ squares, $b$ S-tiles, and $c$ corners. Gry would like to beat the high score by creating the largest-possible contiguous $2 \times n$ rectangle out of some or all of the provided tiles, without any tiles overlapping or sticking out of the rectangle.</p>



## 입력


<ul>
<li>The sole line of input contains three integers $a$, $b$, and $c$ ($0 \leq a, b, c \leq 50$) --- the number of squares, S-tiles, and corners, respectively.</li>
</ul>



## 출력


<p>Output the maximum possible width of the grid, $n$, that can be perfectly filled by some or all of the given tiles without overlapping or overstepping the boundaries.</p>



## 소스코드

[소스코드 보기](Mini-Tetris%203023.py)