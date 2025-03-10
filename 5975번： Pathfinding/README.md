# 5975번: Pathfinding - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/5975)


<p>Bessie is stranded on a deserted arctic island and wants to determine all the paths she might take to return to her pasture. She has tested her boat and knows she can travel from one island to another island in 1 unit of time if a route with proper currents connects the pair.</p>

<p>She has experimented to create a map of the ocean with valid single-hop routes between each pair of the N (1 &lt;= N &lt;= 100) islands, conveniently numbered 1..N. The routes are one-way (unidirectional), owing to the way the currents push her boat in the ocean. It's possible that a pair of islands is connected by two routes that use different currents and thus provide a bidirectional connection. The map takes care to avoid specifying that a route exists between an island and itself.</p>

<p>Given her starting location M (1 &lt;= M &lt;= N) and a representation of the map, help Bessie determine which islands are one 'hop' away, two 'hops' away, and so on. If Bessie can take multiple different paths to an island, consider only the path with the shortest distance.</p>

<p>By way of example, below are N=4 islands with connectivity as shown (for this example, M=1):</p>

<pre>       start--&gt; 1--------&gt;2
                |         |
                |         |
                V         V
                4&lt;--------3</pre>

<p>Bessie can visit island 1 in time 0 (since M=1), islands 2 and 4 at time 1, and island 3 at time 2.</p>

<p>The input for this task is a matrix C where the element at row r, column c is named C_rc (0 &lt;= C_rc &lt;= 1) and, if it has the value 1, means "Currents enable Bessie to travel directly from island r to island c in one time unit". Row C_r has N elements, respectively C_r1..C_rN, each one of which is 0 or 1.</p>



## 입력


<ul>
<li>Line 1: Two space-separated integers: N and M</li>
<li>Lines 2..N+1: Line i+1 contains N space-separated integers: C_r</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Lines 1..???: Line i+1 contains the list of islands (in ascending numerical order) that Bessie can visit at time i. &nbsp;Do not include any lines of output after all reachable islands have been listed.</li>
</ul>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Main.java)