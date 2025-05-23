# 12629번: Crazy Rows (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12629)


<p>You are given an&nbsp;<strong>N</strong>&nbsp;x&nbsp;<strong>N</strong>&nbsp;matrix with 0 and 1 values. You can swap any two&nbsp;<em>adjacent</em>&nbsp;rows of the matrix.</p>

<p>Your goal is to have all the 1 values in the matrix below or on the main diagonal. That is, for each X where 1 ≤ X ≤ N, there must be no 1 values in row X that are to the right of column X.</p>

<p>Return the minimum number of row swaps you need to achieve the goal.</p>



## 입력


<p>The first line of input gives the number of cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow.<br>
The first line of each test case has one integer,&nbsp;<strong>N</strong>. Each of the next&nbsp;<strong>N</strong>&nbsp;lines contains&nbsp;<strong>N</strong>characters. Each character is either 0 or 1.</p>

<p>Limits</p>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 60</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 8</li>
</ul>



## 출력


<p>For each test case, output</p>

<pre>Case #X: K</pre>

<p>where&nbsp;<strong>X</strong>&nbsp;is the test case number, starting from 1, and&nbsp;<strong>K</strong>&nbsp;is the minimum number of row swaps needed to have all the 1 values in the matrix below or on the main diagonal.</p>

<p>You are guaranteed that there is a solution for each test case.</p>



## 소스코드

[소스코드 보기](Crazy%20Rows%20(Small).cpp)