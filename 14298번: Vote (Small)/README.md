# 14298번: Vote (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14298)


<p>A and B are the only two candidates competing in a certain election. We know from polls that exactly&nbsp;N&nbsp;voters support A, and exactly&nbsp;M&nbsp;voters support B. We also know that&nbsp;N&nbsp;is greater than&nbsp;M, so A will win.</p>

<p>Voters will show up at the polling place one at a time, in an order chosen uniformly at random from all possible (N&nbsp;+&nbsp;M)! orders. After each voter casts their vote, the polling place worker will update the results and note which candidate (if any) is winning so far. (If the votes are tied, neither candidate is considered to be winning.)</p>

<p>What is the probability that A stays in the lead the entire time -- that is, that A will always be winning after every vote?</p>



## 입력


<p>The input starts with one line containing one integer&nbsp;T, which is the number of test cases. Each test case consists of one line with two integers&nbsp;N&nbsp;and&nbsp;M: the numbers of voters supporting A and B, respectively.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;T&nbsp;≤ 100.</li>
<li>0 ≤&nbsp;M&nbsp;&lt;&nbsp;N&nbsp;≤ 10.</li>
</ul>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is the probability that A will always be winning after every vote.</p>

<p><code>y</code>&nbsp;will be considered correct if&nbsp;<code>y</code>&nbsp;is within an absolute or relative error of 10<sup>-6</sup>&nbsp;of the correct answer.&nbsp;</p>



## 소스코드

[소스코드 보기](Vote%20(Small).py)