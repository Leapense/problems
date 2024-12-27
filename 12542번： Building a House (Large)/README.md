# 12542번: Building a House (Large) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12542)


<p>You have just bought land and want to plant the largest rectangular field possible. In surveying your land, you find a number of obstacles and decide to draw a map. You indicate in each square of the map whether it contains grass (<strong>G</strong>), rock (<strong>R</strong>), water (<strong>W</strong>), shrubs (<strong>S</strong>), or trees (<strong>T</strong>). While the grass can be mowed and the shrubs dug from the ground, the water, rocks, and trees&nbsp;<strong>cannot</strong>&nbsp;be removed. Given these obstacles, determine the area of the largest rectangular field.</p>



## 입력


<p>The first line of input gives the number of cases,&nbsp;<strong>N</strong>.<br>
<strong>N</strong>&nbsp;test cases follow. For each test case there will be:</p>

<ul>
<li>One line containing two space-separated integers indicating the length (<strong>L</strong>) and width (<strong>W</strong>) of your land.</li>
<li>Followed by,&nbsp;<strong>W</strong>&nbsp;lines, each containing&nbsp;<strong>L</strong>&nbsp;characters where each indicates the conditions for that square of land (one of&nbsp;<code>G, R, W, S, or T</code>).</li>
</ul>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>L</strong>&nbsp;≤ 50</li>
<li>1 ≤&nbsp;<strong>W</strong>&nbsp;≤ 50</li>
<li><strong>N</strong>&nbsp;≤ 30</li>
<li>Fewer than 20 obstacles in each test case.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #<strong>x</strong>: " followed by the maximum area of the largest rectangle that can be cleared.</p>



## 소스코드

[소스코드 보기](Building%20a%20House%20(Large).py)