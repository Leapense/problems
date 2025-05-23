# 12705번: Triangle Areas (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12705)


<p>Ten-year-old Tangor has just discovered how to compute the area of a triangle. Being a bright boy, he is amazed by how many different ways one can compute the area. He also convinced himself that, if all the points of the triangle have integer coordinates, then the triangle's area is always either an integer or half of an integer! Isn't that nice?</p>

<p>But today Tangor is trying to go in the opposite direction. Instead of taking a triangle and computing its area, he is taking an integer&nbsp;<strong>A</strong>&nbsp;and trying to draw a triangle of area&nbsp;<strong>A</strong>/2. He restricts himself to using only the integer points on his graph paper for the triangle's vertices.</p>

<p>More precisely, the sheet of graph paper is divided into an&nbsp;<strong>N</strong>&nbsp;by&nbsp;<strong>M</strong>&nbsp;grid of square cells. The triangle's vertices may only be placed in the corners of those cells. If you imagine a coordinate system on the paper, then these points are of the form (<strong>x</strong>,&nbsp;<strong>y</strong>), where&nbsp;<strong>x</strong>&nbsp;and&nbsp;<strong>y</strong>are integers such that&nbsp;0 ≤&nbsp;<strong>x</strong>&nbsp;≤&nbsp;<strong>N</strong>&nbsp;and&nbsp;0 ≤&nbsp;<strong>y</strong>&nbsp;≤&nbsp;<strong>M</strong>.</p>

<p>Given the integer&nbsp;<strong>A</strong>, help Tangor find three integer points on the sheet of graph paper such that the area of the triangle formed by those points is exactly&nbsp;<strong>A</strong>/2, if that is possible. In case there is more than one way to do this, any solution will make him happy.</p>



## 입력


<p>One line containing an integer&nbsp;<strong>C</strong>, the number of test cases in the input file.</p>

<p>The next&nbsp;<strong>C</strong>&nbsp;lines will each contain three integers&nbsp;<strong>N</strong>,&nbsp;<strong>M</strong>, and&nbsp;<strong>A</strong>, as described above.</p>

<p>Limits</p>

<ul>
<li>0 ≤&nbsp;<strong>C</strong>&nbsp;≤ 1000</li>
<li>1 ≤&nbsp;<strong>A</strong>&nbsp;≤ 10<sup>8</sup></li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 50</li>
<li>1 ≤&nbsp;<strong>M</strong>&nbsp;≤ 50</li>
</ul>



## 출력


<p>For each test case, output one line. If there is no way to satisfy the condition, output&nbsp;</p>

<pre>Case #k: IMPOSSIBLE
</pre>

<p>where k is the case number, starting from 1. Otherwise, output</p>

<pre>Case #k: x<sub>1</sub> y<sub>1</sub> x<sub>2</sub> y<sub>2</sub> x<sub>3</sub> y<sub>3</sub>
</pre>

<p>where k is the case number and (x<sub>1</sub>, y<sub>1</sub>), (x<sub>2</sub>, y<sub>2</sub>), (x<sub>3</sub>, y<sub>3</sub>) are any three integer points on the graph paper that form a triangle of area&nbsp;<strong>A</strong>/2.</p>



## 소스코드

[소스코드 보기](Triangle%20Areas%20(Small).cpp)