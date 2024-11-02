# 14371번: Close Match (Small) - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14371)


<p>You are attending the most important game in sports history. The Oceania Coders are playing the Eurasia Jammers in the Centrifugal Bumble-Puppy world finals. Unfortunately, you were sleep deprived from all the anticipation, so you fell asleep during the game!</p>

<p>The scoreboard is currently displaying both scores, perhaps with one or more leading zeroes (because the scoreboard displays a fixed number of digits). While you were asleep, some of the lights on the scoreboard were damaged by strong ball hits, so one or more of the digits in one or both scores are not being displayed.</p>

<p>You think close games are more exciting, and you would like to imagine that the scores are as close as possible. Can you fill in all of the missing digits in a way that minimizes the absolute difference between the scores? If there is more than one way to attain the minimum absolute difference, choose the way that minimizes the Coders' score. If there is more than one way to attain the minimum absolute difference while also minimizing the Coders' score, choose the way that minimizes the Jammers' score.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;T.&nbsp;T&nbsp;cases follow. Each case consists of one line with two non-empty strings&nbsp;C&nbsp;and&nbsp;J&nbsp;of the same length, composed only of decimal digits and question marks, representing the score as you see it for the Coders and the Jammers, respectively. There will be at least one question mark in each test case.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;T&nbsp;≤ 200.</li>
<li>C&nbsp;and&nbsp;J&nbsp;have the same length.</li>
<li>1 ≤ the length of&nbsp;C&nbsp;and&nbsp;J&nbsp;≤ 3.</li>
</ul>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: c j</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1),&nbsp;<code>c</code>&nbsp;is&nbsp;C&nbsp;with the question marks replaced by digits, and&nbsp;<code>j</code>&nbsp;is&nbsp;J&nbsp;with the question marks replaced by digits, such that the absolute difference between the integers represented by&nbsp;<code>c</code>&nbsp;and&nbsp;<code>j</code>&nbsp;is minimized. If there are multiple solutions with the same absolute difference, use the one in which&nbsp;<code>c</code>&nbsp;is minimized; if there are multiple solutions with the same absolute difference and the same value of&nbsp;<code>c</code>, use the one in which&nbsp;<code>j</code>&nbsp;is minimized.</p>



## 소스코드

[소스코드 보기](Close%20Match%20(Small).cpp)