# 6188번: Clear Cold Water - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6188)


<p>The steamy, sweltering summers of Wisconsin's dairy district stimulate the cows to slake their thirst. Farmer John pipes clear cold water into a set of N (3 &lt;= N &lt;= 99999; N odd) branching pipes conveniently numbered 1..N from a pump located at the barn. As the water flows through the pipes, the summer heat warms it. &nbsp;Bessie wants to find the coldest water so she can enjoy the weather more than any other cow.</p>

<p>She has mapped the entire set of branching pipes and noted that they form a tree with its root at the farm and furthermore that every branch point has exactly two pipes exiting from it. Surprisingly, every pipe is exactly one unit in length; of course, all N pipes connect up in one way or another to the pipe-tree.</p>

<p>Given the map of all the pipe connections, make a list of the distance from the barn for every branching point and endpoint. Bessie will use the list to find the very coldest water.</p>

<p>The endpoint of a pipe, which might enter a branching point or might be a spigot, is named by the pipe's number. The map contains C (1 &lt;= C &lt;= N) connections, each of which specifies three integers: the endpoint E_i (1 &lt;= E_i &lt;= N) of a pipe and two branching pipes B1_i and B2_i (2 &lt;= B1_i &lt;= N; 2 &lt;= B2_i &lt;= N). Pipe number 1 connects to the barn; the distance from its endpoint to the barn is 1.</p>



## 입력


<ul>
<li>Line 1: Two space-separated integers: N and C</li>
<li>Lines 2..C+1: Line i+1 describes branching point i with three space-separated integers: E_i, B1_i, and B2_i</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Lines 1..N: Line i of the output contains a single integer that is the distance from the barn to the endpoint of pipe i</li>
</ul>



## 소스코드

[소스코드 보기](Clear%20Cold%20Water.py)