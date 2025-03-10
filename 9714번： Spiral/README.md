# 9714번: Spiral - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9714)


<p>Consider all positive integers written in the following manner (you can imagine an infinite spiral).</p>

<pre>21  22  23  24  25  26
20   7   8   9  10 ...
19   6   1   2  11 ...
18   5   4   3  12 ...
17  16  15  14  13 ...</pre>

<p>Your task is to determine the position (row,column) of a given number N, assuming that the center (number 1) has position (0,0). Rows are numbered from top to bottom, columns are numbered from left to right (for example, number 3 is at (1,1). Your program should output a string containing the position of N in the form (R,C) where R is the row and C is the column. R and C must not contain any leading zeroes.</p>



## 입력


<p>The first line of the input gives an integer T, which is the number of test cases. &nbsp;Each test case contains an integer N (1 ≤ N&lt;2<sup>31</sup>).</p>



## 출력


<p>For each test case, output the position as described above. See sample output for further clarification. &nbsp;</p>



## 소스코드

[소스코드 보기](Spiral.cpp)