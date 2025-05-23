# 25803번: Soccer Standing Table - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25803)


<p>In soccer, a win is worth 3 points, draw (tie) is worth 1 point, and loss is worth zero points. Soccer standing tables show the following info for each team: number of matches played (MP), number of wins (W), number of draws (D), number of losses (L), and total number of points (Pts). For example, the entry:</p>

<pre>USA 11 5 4 2 19</pre>

<p>Indicates USA has played 11 matches, won 5 of them, drew 4 matches and lost 2, for a total number of points of 19 (5*3 + 4*1).</p>

<p>Even though the info is complete and helpful, some publications/websites list the numbers in different orders, e.g., the number of losses may be listed before the number of draws. And, if the columns are not labeled as to what they represent, that causes confusion.</p>

<p>Given five integers representing the entry for a soccer team, print these numbers in the order of MP-W-D-L-Pts.</p>



## 입력


<p>There is only one input line: it contains five integers, each between 0 and 300, inclusive. Assume that the input represents a valid entry, e.g., MP = W + D + L. Also assume that the input will not be all zeros, i.e., some games have been played.</p>



## 출력


<p>Print the numbers in the order of MP-W-D-L-Pts. Assume that there will be exactly one valid answer.</p>



## 소스코드

[소스코드 보기](Soccer%20Standing%20Table.cpp)