# 3168번: stolni - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/3168)


<p>Two friends, Mirko and Slavko, are playing table soccer. Mirko has no players on the table, and Slavko's players are attached to vertical bars.&nbsp;</p>

<p>The ball is situated on the left edge of the table and Mirko shots the ball in the up-right diagonal direction. After that, the ball moves in a straight line across the table deflecting from the upper and lower edges.</p>

<pre style="text-align: center;">....................
......|..|....|.....
.........|..........
......|.......|.....
L.....|.............
..............|.....</pre>

<p>If the ball hits some of the Slavko's players, Mirko fails to score, and if the ball reaches the right edge of the table, Mirko scores.&nbsp;</p>

<p>Slavko knows that he is a better player than Mirko and he wants to allow Mirko to score.&nbsp;</p>

<p>Write a program that finds some arrangement of the Slavko's players that allows Mirko to score. Also, draw the path of the ball.&nbsp;</p>

<p>Slavko can arrange the players by moving each column up or down a certain distance with the restriction that all players have to remain within the table.&nbsp;</p>



## 입력


<p>The first line of input contains two integers R and C, 2 ≤ R,C ≤ 100, the numbers of rows and columns on the table.&nbsp;</p>

<p>Each of the following R lines contains C characters – the initial layout of the table.&nbsp;</p>

<p>The ball is labeled with 'L', players with '|' (vertical line) and empty squares on the table with '.' (dot). There will be no players in the leftmost column on the table.&nbsp;</p>



## 출력


<p>Output the final layout of the table, together with the path of the ball.&nbsp;</p>

<p>Note: the test data will be such that a solution, although not necessarily unique, will always exist.&nbsp;</p>



## 소스코드

[소스코드 보기](stolni.cpp)