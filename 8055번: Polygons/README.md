# 8055번: Polygons - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8055)


<p>Two players take part in the game polygons. A convex polygon with n vertices divided by n-3 diagonals into n-2 triangles is necessary. These diagonals may intersect in vertices of the polygon only. One of the triangles is black and the remaining ones are white. Players proceed in alternate turns. Each player, when its turn comes, cuts away one triangle from the polygon. Players are allowed to cut off triangles along the given diagonals. The winner is the player who cuts away the black triangle.</p>

<p>NOTE: We call a polygon convex if a segment joining any two points of the polygon is contained in the polygon.</p>

<p>
Write a program which:</p>

<ul>
<li>reads from the standard input the description of the polygon,</li>
<li>verifies whether the player who starts the game has a winning strategy,</li>
<li>writes the result to the standard output.</li>
</ul>



## 입력


<p>The first line of the standard input contains an integer n, 4 ≤ n ≤ 50,000. This is the number of vertices in the polygon. The vertices of the polygon are numbered, clockwise, from 0 to n-1. The next n-2 lines comprise descriptions of triangles in the polygon. In the i+1-th line, 1 ≤ i ≤ n-2, there are three non-negative integers a, b, c separated by single spaces. Theses are numbers of vertices of the i-th triangle. The first triangle in a sequence is black.</p>

<p>&nbsp;</p>



## 출력


<p>The standard output should have one line with the word:</p>

<ul>
<li>TAK (means "yes" in Polish), if the player, who starts the game has a winning strategy,</li>
<li>NIE (means "no" in Polish), if he does not have a winning strategy.</li>
</ul>



## 소스코드

[소스코드 보기](Polygons.cpp)