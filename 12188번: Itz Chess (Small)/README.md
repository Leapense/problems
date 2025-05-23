# 12188번: Itz Chess (Small) - <img src="https://static.solved.ac/tier_small/10.svg" style="height:20px" /> Silver I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12188)


<p>Given an arranged chess board with pieces, figure out the total number of different ways in which any piece can be killed&nbsp;<strong>in one move</strong>. Note: in this problem, the pieces can be killed despite of the color.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/12188/images-2.jpeg" style="height:301px; opacity:0.9; width:301px"></p>

<p>For example, if there are 3 pieces King is at B2, Pawn at A1 and Queen at H8 then the total number of pieces that an be killed is 3. H8-Q can kill B2-K, A1-P can kill B2-K, B2-K can kill A1-P</p>

<p>A position on the chess board is represented as A1, A2... A8,B1.. H8</p>

<p>Pieces are represented as</p>

<ul>
<li>(K) King can move in 8 direction by one place.</li>
<li>(Q) Queen can move in 8 direction by any number of places, but can't overtake another piece.</li>
<li>(R) Rook can only move vertically or horitonzally, but can't overtake another piece.</li>
<li>(B) Bishop can only move diagonally, but can't overtake another piece.</li>
<li>(N) Knights can move to a square that is two squares horizontally and one square vertically&nbsp;<strong>OR</strong>&nbsp;one squares horizontally and two square vertically.</li>
<li>(P) Pawn can only kill by moving diagonally upwards (towards higher number i.e. A -&gt; B, B-&gt;C and so on).</li>
</ul>



## 입력


<p>The first line of the input gives the number of test cases, <strong>T</strong>. <strong>T</strong> Test cases follow. Each test case consists of the number of pieces , <strong>N</strong>. <strong>N</strong> lines follow, each line mentions where a piece is present followed by <strong>-</strong> with the piece type</p>

<p>Limits</p>

<ul>
<li>1 ≤ <strong>T</strong> ≤ 100.</li>
<li><span style="line-height:1.6em">1 ≤ </span><strong style="line-height:1.6em">N</strong><span style="line-height:1.6em"> ≤ 10.</span></li>
<li>Pieces can include K, P</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the the total number of different ways in which any piece can be killed.</p>



## 소스코드

[소스코드 보기](Main.java)