# 12531번: Vanishing Numbers (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12531)


<p>There is a pool of numbers which are arbitrary decimal fractions from the interval (0, 1). In the first round of the game the middle third of the interval disappears, and the numbers from this interval are eliminated from the pool. In the next rounds the middle thirds of each of the remaining intervals disappear. In the first round the the interval&nbsp;[1/3, 2/3]&nbsp;is eliminated and in the second round the two intervals&nbsp;[1/9, 2/9]&nbsp;and&nbsp;[7/9, 8/9]&nbsp;are eliminated, and so on. The endpoints of each removed interval are removed as well.</p>

<p>Your role is to sort the pool of numbers in the order that they are eliminated. If some numbers are never eliminated, list them last. In case of a tie, list the smaller numbers first.</p>



## 입력


<p>The first line of input will contain&nbsp;<strong>T</strong>, the number of test cases.&nbsp;<strong>T</strong>&nbsp;test cases will follow. Each one will start with a line containing an integer&nbsp;<strong>N</strong>.&nbsp;<strong>N</strong>&nbsp;numbers will follow, one per line. Each number will start with "0.", followed by one or more decimal digits. Each number will be larger than zero and will not have any trailing zeros.</p>

<h3>Limits</h3>

<ul>
<li><strong>T</strong>&nbsp;≤ 100</li>
<li><strong>N</strong>&nbsp;≤ 100</li>
<li>Each number will have at most 5 digits after the decimal point.</li>
</ul>

<div>&nbsp;</div>



## 출력


<p>For each test case, print the line "Case #<strong>x</strong>:", where&nbsp;<strong>x</strong>&nbsp;is the number of the test case, starting with 1. After that line, list the numbers, one per line, in order of elimination.</p>



## 소스코드

[소스코드 보기](Vanishing%20Numbers%20(Small).cpp)