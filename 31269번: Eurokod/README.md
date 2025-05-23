# 31269번: Eurokod - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31269)


<p>This year, for the first time, the <em>Eurokod</em> is being held, an international competition in writing beautiful and readable code!</p>

<p>There are $n$ contestants participating in the competition, labeled with numbers from $1$ to $n$, and each of them has written a code.</p>

<p>Their codes are evaluated by an association of computer scientists. The association consists of a president and members of the association. The president awards points to codes in one way, and the members of the association award points in another way.</p>

<p><strong>President’s points:</strong></p>

<p>The president will rank the codes from the most beautiful to the least beautiful (in his opinion). The first code will be awarded $n$ points, and each subsequent code will be awarded one point less than the previous one.</p>

<p><strong>Members of the association’s points:</strong></p>

<p>Each member of the association will vote for the code he considers the most beautiful. After each member of the association has voted, the codes will be ranked in descending order according to the number of votes they received from the members of the association. The first code (the one with the most votes) will be awarded $n$ points, and each subsequent code will be awarded one point less than the previous one.</p>

<p><strong>Total points:</strong></p>

<p>The total number of points for each code is equal to the sum of the points awarded by the president and the number of points awarded by the members of the association.</p>

<p>Your task is to print the order of codes in descending order according to the number of points.</p>

<p>If more codes have the same number of points, then the better ranked one is the one that has won more points from the members of the association.</p>



## 입력


<p>The first line contains an integer $n$ ($1 ≤ n ≤ 50$), the number of contestants.</p>

<p>The second line contains $n$ integers $a_i$ ($1 ≤ a_i ≤ n$), where the $i$-th integer represents the label of the code that the president ranked $i$-th. The ranking of the president is given in the order from the most beautiful to the least beautiful, it contains all the labels from $1$ to $n$ exactly once.</p>

<p>The third line contains $n$ integers $b_i$ ($0 ≤ b_i ≤ 200$), where the $i$-th integer represents the number of <strong>votes</strong> that the $i$-th code received from the members of the association. There won’t be two codes that received the same number of votes.</p>



## 출력


<p>In $n$ lines, print the ranking of codes in descending order according to the number of points.</p>

<p>Each line should be in the form "<code>[rank]. Kod[label] ([number of points])</code>", where <code>[rank]</code> is the rank of the code in the ranking, <code>[label]</code> is the label of the code written in two-digit form with leading zeros, and <code>[number of points]</code> is the number of points that the code won.</p>

<p>For example, if the first place was won by the code with the label $3$ with $12$ points, then the first line is "<code>1. Kod03 (12)</code>".</p>



## 소스코드

[소스코드 보기](Eurokod.cpp)