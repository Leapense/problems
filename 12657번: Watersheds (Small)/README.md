# 12657번: Watersheds (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12657)


<p>Geologists sometimes divide an area of land into different regions based on where rainfall flows down to. These regions are called&nbsp;<em>drainage basins</em>.</p>

<p>Given an elevation map (a 2-dimensional array of altitudes), label the map such that locations in the same drainage basin have the same label, subject to the following rules.</p>

<ul>
<li>From each cell, water flows down to at most one of its 4 neighboring cells.</li>
<li>For each cell, if none of its 4 neighboring cells has a lower altitude than the current cell's, then the water does not flow, and the current cell is called a&nbsp;<em>sink</em>.</li>
<li>Otherwise, water flows from the current cell to the neighbor with the lowest altitude.</li>
<li>In case of a tie, water will choose the first direction with the lowest altitude from this list: North, West, East, South.</li>
</ul>

<p>Every cell that drains directly or indirectly to the same sink is part of the same drainage basin. Each basin is labeled by a unique lower-case letter, in such a way that, when the rows of the map are concatenated from top to bottom, the resulting string is lexicographically smallest. (In particular, the basin of the most North-Western cell is always labeled 'a'.)</p>



## 입력


<p>The first line of the input file will contain the number of maps,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;maps will follow, each starting with two integers on a line --&nbsp;<strong>H</strong>&nbsp;and&nbsp;<strong>W</strong>&nbsp;-- the height and width of the map, in cells. The next&nbsp;<strong>H</strong>&nbsp;lines will each contain a row of the map, from north to south, each containing&nbsp;<strong>W</strong>&nbsp;integers, from west to east, specifying the altitudes of the cells.</p>

<p>Limits</p>

<ul>
<li><strong>T</strong>&nbsp;≤ 100;</li>
<li>1 ≤&nbsp;<strong>H</strong>,&nbsp;<strong>W</strong>&nbsp;≤ 10;</li>
<li>0 ≤ altitudes &lt; 10.</li>
<li>There will be at most two basins.</li>
</ul>



## 출력


<p>For each test case, output 1+<strong>H</strong>&nbsp;lines. The first line must be of the form</p>

<pre>Case #<strong>X</strong>:</pre>

<p>where&nbsp;<strong>X</strong>&nbsp;is the test case number, starting from 1. The next&nbsp;<strong>H</strong>&nbsp;lines must list the basin labels for each of the cells, in the same order as they appear in the input.</p>



## 소스코드

[소스코드 보기](Watersheds%20(Small).cpp)