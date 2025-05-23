# 12036번: Dance Around The Clock (Large) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12036)


<p>The owner of a prestigious ballroom has painted a beautiful circular clock on the dance floor, and a group of&nbsp;<strong>D</strong>&nbsp;dancers numbered 1 through&nbsp;<strong>D</strong>&nbsp;are about to literally "dance around the clock". They are standing in a circle, with dancer 1 at the 12:00 position of the circle and the other dancers going clockwise around the circle in increasing numerical order. The number of dancers is even.</p>

<p>The dance will go on for&nbsp;<strong>N</strong>&nbsp;turns. On the i-th turn (counting starting from 1), the following will happen:</p>

<ul>
<li>If i is odd, then the dancer currently at the 12:00 position will swap positions with the next dancer in clockwise order. Then, going past those two, the next pair of dancers in clockwise order will swap positions, and so on, all the way around the ring clockwise, until all dancers have participated in exactly one swap.</li>
<li>If i is even, then the dancer currently at the 12:00 position will swap positions with the next dancer in counterclockwise order. Then, going past those two, the next pair of dancers in counterclockwise order will swap positions, and so on, all the way around the ring counterclockwise, until all dancers have participated in a swap.</li>
</ul>

<p>For example, this diagram shows the initial state and two turns of a dance with eight people.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/12035/12035.png" style="height:157px; width:589px"></p>

<p>Which two dancers will be next to dancer number&nbsp;<strong>K</strong>&nbsp;when the dance is over?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;&nbsp;<strong>T</strong>&nbsp;test cases follow. Each consists of one line with three integers&nbsp;<strong>D</strong>,&nbsp;<strong>K</strong>, and&nbsp;<strong>N</strong>: the total number of dancers, the number of one of the dancers, and the number of turns the dance will go on for.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li><strong>D</strong>&nbsp;is even.</li>
<li>1 ≤&nbsp;<strong>K</strong>&nbsp;≤&nbsp;<strong>D</strong>.</li>
<li>4 ≤&nbsp;<strong>D</strong>&nbsp;≤ 10<sup>8</sup>.</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 10<sup>8</sup>.</li>
</ul>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y z</code>, where:</p>

<ul>
<li><code>x</code>&nbsp;is the test case number (starting from 1).</li>
<li><code>y</code>&nbsp;is the number of the dancer who will be standing to dancer number&nbsp;<strong>K</strong>'s left (that is, one step away in clockwise order) when the dance is over.</li>
<li><code>z</code>&nbsp;is the number of the dancer who will be standing to dancer number&nbsp;<strong>K</strong>'s right (that is, one step away in counterclockwise order) when the dance is over.</li>
</ul>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Dance%20Around%20The%20Clock%20(Large).py)