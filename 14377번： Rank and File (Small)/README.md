# 14377번: Rank and File (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14377)


<p>When Sergeant Argus's army assembles for drilling, they stand in the shape of an&nbsp;N&nbsp;by&nbsp;Nsquare grid, with exactly one soldier in each cell. Each soldier has a certain height.</p>

<p>Argus believes that it is important to keep an eye on all of his soldiers at all times. Since he likes to look at the grid from the upper left, he requires that:</p>

<ul>
<li>Within every row of the grid, the soldiers' heights must be in strictly increasing order, from left to right.</li>
<li>Within every column of the grid, the soldiers' heights must be in strictly increasing order, from top to bottom.</li>
</ul>

<p>Although no two soldiers in the same row or column may have the same height, it is possible for multiple soldiers in the grid to have the same height.</p>

<p>Since soldiers sometimes train separately with their row or their column, Argus has asked you to make a report consisting of 2*N&nbsp;lists of the soldiers' heights: one representing each row (in left-to-right order) and column (in top-to-bottom order). As you surveyed the soldiers, you only had small pieces of paper to write on, so you wrote each list on a separate piece of paper. However, on your way back to your office, you were startled by a loud bugle blast and you dropped all of the pieces of paper, and the wind blew one away before you could recover it! The other pieces of paper are now in no particular order, and you can't even remember which lists represent rows and which represent columns, since you didn't write that down.</p>

<p>You know that Argus will make you do hundreds of push-ups if you give him an incomplete report. Can you figure out what the missing list is?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;T.&nbsp;T&nbsp;test cases follow. Each consists of one line with an integer&nbsp;N, followed by 2*N-1 lines of&nbsp;N&nbsp;integers each, representing the lists you have, as described in the statement. It is guaranteed that these lists represent all but one of the rows and columns from a valid grid, as described in the statement.</p>

<p>Limits</p>

<ul>
<li>1 ≤&nbsp;T&nbsp;≤ 50.</li>
<li>1 ≤ all heights ≤ 2500.</li>
<li>The integers on each line will be in strictly increasing order.</li>
<li>2 ≤&nbsp;N&nbsp;≤ 10.</li>
</ul>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and y is a list of&nbsp;N&nbsp;integers in strictly increasing order, representing the missing list.</p>



## 소스코드

[소스코드 보기](Rank%20and%20File%20(Small).py)