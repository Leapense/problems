# 10654번: Cow Jog - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10654)


<p>The cows are out exercising their hooves again! &nbsp;There are N cows jogging on an infinitely-long single-lane track (1 &lt;= N &lt;= 100,000). Each cow starts at a distinct position on the track, and some cows jog at different speeds.</p>

<p>With only one lane in the track, cows cannot pass each other. &nbsp;When a faster cow catches up to another cow, she has to slow down to avoid running into the other cow, becoming part of the same running group.</p>

<p>The cows will run for T minutes (1 &lt;= T &lt;= 1,000,000,000). &nbsp;Please help Farmer John determine how many groups will be left at this time. Two cows should be considered part of the same group if they are at the same position at the end of T minutes.</p>



## 입력


<p>The first line of input contains the two integers N and T.</p>

<p>The following N lines each contain the initial position and speed of a single cow. &nbsp;Position is a nonnegative integer and speed is a positive integer; both numbers are at most 1 billion. &nbsp;All cows start at &nbsp;distinct positions, and these will be given in increasing order in the input.</p>



## 출력


<p>A single integer indicating how many groups remain after T minutes.</p>



## 소스코드

[소스코드 보기](Cow%20Jog.cpp)