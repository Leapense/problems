# 11978번: Mowing the Field (Bronze) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11978)


<p>Farmer John is quite reliable in all aspects of managing his farm, except one: he is terrible at mowing the grass in a timely or logical fashion.</p>

<p>The farm is a large 2D grid of square unit cells. FJ starts in one of these cells at time \(t = 0\), mowing the grass in this cell so that it is initially the only cell in which the grass is cut. FJ's remaining mowing pattern is described by a sequence of \(N\) statements. For example, if the first statement is "W 10", then for times \(t = 1\) through \(t = 10\) (i.e., the next 10 units of time), FJ will step one cell to his west, mowing the grass along the way. After completing this sequence of steps, he will end up 10 cells to his west at time \(t = 10\), having mowed the grass in every cell along the way.</p>

<p>So slow is FJ's progress that some of the grass he mows might grow back before he is finished with all his mowing. Any section of grass that is cut at time \(t\) will reappear at time \(t + x\).</p>

<p>FJ's mowing pattern might have him re-visit the same cell multiple times, but he remarks that he never encounters a cell in which the grass is already cut. That is, every time he visits a cell, his most recent visit to that same cell must have been at least \(x\) units of time earlier, in order for the grass to have grown back.</p>

<p>Please determine the maximum possible value of \(x\) so that FJ's observation remains valid.</p>



## 입력


<p>The first line of input contains \(N\) (\(1 \leq N \leq 100\)). Each of the remaining \(N\) lines contains a single statement and is of the form 'D S', where D is a character describing a direction (N=north, E=east, S=south, W=west) and S is the number of steps taken in that direction (\(1 \leq S \leq 10\)).</p>



## 출력


<p>Please determine the maximum value of \(x\) such that FJ never steps on a cell with cut grass. If FJ never visits any cell more than once, please output -1.</p>



## 소스코드

[소스코드 보기](Mowing%20the%20Field%20(Bronze).cpp)