# 25039번: Med - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25039)


<p>The moment has finally arrived. Not only is it the last round of COCI this season, it is also the last round of COCB - the Croatian Open Competition in Beekeeping. Not many people know that the two competitions share the same scoring system. More precisely, both competitions consist of six rounds, the points on each round are between 0 and 500, and the scores of the individual rounds are summed up for the final tally.</p>

<p>After the six rounds, the competitors are ranked based on their total score over the six rounds. If two competitors have the same score, the one with the lexicographically smaller name appears sooner on the ranking. No two competitors have the same name.</p>

<p>The beekeepers are very impatient and they would like to know what their final ranking will be in advance. Each beekeeper wants to know their best and worst possible positions on the final ranking. Unlike skilled COCI programmers, the beekeepers don’t know how to code. Therefore, they are asking you to determine the range of positions they could occupy after the sixth round.</p>



## 입력


<p>The first line contains a positive integer $n$ ($1 ≤ n ≤ 500$), the number of beekeepers.</p>

<p>Each of the following $n$ lines contains the name of a beekeeper $s_i$ ($1 ≤ |s_i| ≤ 10$) and five numbers $b_{i1}$, $b_{i2}$, $b_{i3}$, $b_{i4}$, $b_{i5}$ from the range $[0, 500]$, the scores of the $i$-th beekeeper on the first five rounds of COCB. The names of the beekeepers are distinct and are made up of at most ten lowercase letters of the latin alphabet.</p>



## 출력


<p>Print $n$ lines. In the $i$-th line print the best and worst possible position on the ranking for the $i$-th beekeeper.</p>



## 소스코드

[소스코드 보기](Med.py)