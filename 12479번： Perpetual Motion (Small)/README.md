# 12479번: Perpetual Motion (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12479)


<p>Have you ever been to the Google Lemming Factory? It is a very unusual place. The floor is arranged into an&nbsp;<strong>R</strong>&nbsp;x&nbsp;<strong>C</strong>&nbsp;grid. Within each grid square, there is a conveyor belt oriented up-down, left-right, or along one of the two diagonals. The conveyor belts move either forwards or backwards along their orientations, and you can independently choose which of the two possible directions each conveyor belt should move in.</p>

<p><img src="https://onlinejudgeimages.s3.amazonaws.com/problem/12479/images-36.png" style="border:0px; opacity:0.9; vertical-align:middle"></p>

<p>Currently, there is a single lemming standing at the center of each square. When you start the conveyor belts, each lemming will move in the direction of the conveyor belt he is on until he reaches the center of a new square. All these movements happen simultaneously and take exactly one second to complete. Afterwards, the lemmings will all be on new squares, and the process will repeat from their new positions. This continues forever, or at least until you turn off the conveyor belts.</p>

<ul>
<li>When a lemming enters a new square, he continues going in the direction he was already going until he reaches the center of that square. He will not be affected by the new conveyor belt until the next second starts.</li>
<li>If a lemming moves off the edge of the grid, he comes back at the same position on the opposite side. For example, if he were to move diagonally up and left from the top-left square, he would arrive at the bottom-right square. By the miracle of science, this whole process still only takes 1 second.</li>
<li>Lemmings never collide and can always move past each other without difficulty.</li>
</ul>

<p>The trick is to choose directions for each conveyor belt so that the lemmings will keep moving forever without ever having two of them end up in the center of the same square at the same time. If that happened, they would be stuck together from then on, and that is not as fun for them.</p>

<p>Here are two ways of assigning directions to each conveyor belt from the earlier example:</p>

<p><img src="https://onlinejudgeimages.s3.amazonaws.com/problem/12479/images-37.png" style="border:0px; vertical-align:middle"></p>

<p>&nbsp;</p>

<p>In both cases, we avoid ever sending two lemmings to the center of the same square at the same time.</p>

<p>Given an arbitrary floor layout, calculate&nbsp;<strong>N</strong>, the number of ways to choose directions for each conveyor belt so that no two lemmings will ever end up in the center of the same square at the same time. The answer might be quite large, so please output it modulo 1000003.</p>



## 입력


<p>The first line of input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow. Each begins with a line containing positive integers&nbsp;<strong>R</strong>&nbsp;and&nbsp;<strong>C</strong>.</p>

<p>This is followed by&nbsp;<strong>R</strong>&nbsp;lines, each containing a string of&nbsp;<strong>C</strong>&nbsp;characters chosen from&nbsp;<code>"|-/\"</code>. Each character represents the orientation of the conveyor belt in a single square:</p>

<ul>
<li>'<code>|</code>' represents a conveyor belt that can move up or down.</li>
<li>'<code>-</code>' represents a conveyor belt that can move left or right.</li>
<li>'<code>/</code>' represents a conveyor belt that can move up-right or down-left.</li>
<li>'<code>\</code>' represents a conveyor belt that can move up-left or down-right.</li>
</ul>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 25.</li>
<li>3 ≤&nbsp;<strong>R</strong>&nbsp;≤ 4.</li>
<li>3 ≤&nbsp;<strong>C</strong>&nbsp;≤ 4.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x:&nbsp;<strong>M</strong>", where x is the case number (starting from 1), and&nbsp;<strong>M</strong>&nbsp;is the remainder when dividing&nbsp;<strong>N</strong>&nbsp;by 1000003.</p>



## 소스코드

[소스코드 보기](Perpetual%20Motion%20(Small).py)