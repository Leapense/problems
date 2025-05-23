# 12329번: Bullseye (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12329)


<p>Maria has been hired by the Ghastly Chemicals Junkies (GCJ) company to help them manufacture&nbsp;<strong>bullseyes</strong>. A&nbsp;<strong>bullseye</strong>&nbsp;consists of a number of concentric rings (rings that are centered at the same point), and it usually represents an archery target. GCJ is interested in manufacturing black-and-white bullseyes.&nbsp;</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/12329/images-53.png" style="height:222px; width:224px"></p>

<p>Maria starts with&nbsp;<strong>t</strong>&nbsp;millilitres of black paint, which she will use to draw rings of thickness 1cm (one centimetre). A ring of thickness 1cm is the space between two concentric circles whose radii differ by 1cm.</p>

<p>Maria draws the first black ring around a white circle of radius&nbsp;<strong>r</strong>&nbsp;cm. Then she repeats the following process for as long as she has enough paint to do so:</p>

<ol>
<li>Maria imagines a white ring of thickness 1cm around the last black ring.</li>
<li>Then she draws a new black ring of thickness 1cm around that white ring.</li>
</ol>

<p>Note that each "white ring" is simply the space between two black rings.</p>

<p>The area of a disk with radius 1cm is&nbsp;<strong>π</strong>&nbsp;cm<sup>2</sup>. One millilitre of paint is required to cover area&nbsp;<strong>π</strong>&nbsp;cm<sup>2</sup>. What is the maximum number of black rings that Maria can draw? Please note that:</p>

<ul>
<li>Maria only draws complete rings. If the remaining paint is not enough to draw a complete black ring, she stops painting immediately.</li>
<li>There will always be enough paint to draw at least one black ring.</li>
</ul>



## 입력


<p>The first line of the input gives the number of test cases, <strong>T</strong>. <strong>T</strong> test cases follow. Each test case consists of a line containing two space separated integers: <strong>r</strong> and <strong>t</strong>.</p>

<p>Limits</p>

<ul>
<li>1 ≤ <strong>T</strong> ≤ 1000.</li>
<li>1 ≤ <strong>r</strong>, <strong>t</strong> ≤ 1000.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #<strong>x</strong>: <strong>y</strong>", where <strong>x</strong> is the case number (starting from 1) and <strong>y</strong> is the maximum number of black rings that Maria can draw.</p>



## 소스코드

[소스코드 보기](Bullseye%20(Small).cpp)