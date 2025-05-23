# 29781번: Rainbow Sort - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29781)


<p>Your friend Charles gives you a challenge. He puts $\mathbf{N}$ cards on a table and arranges them in a line in an order that he chooses. Each card has a single color, and each color can be on one or more cards.</p>

<p>Charles then asks you to write a positive integer on each card without altering his chosen order such that:</p>

<ol>
<li>The integers you write appear in non-decreasing order when cards are read from left to right.</li>
<li>Cards of the same color have the same integer written on them.</li>
<li>Cards of different colors have different integers written on them.</li>
</ol>

<p>Finally, Charles wants you to order the colors in increasing order of written integer. For example, if blue cards have a $2$, red cards have a $5$, and green cards have a $3$, the color order would be blue, green, red.</p>



## 입력


<p>The first line of the input gives the number of test cases, $\mathbf{T}$. $\mathbf{T}$ test cases follow.</p>

<p>Each test case begins with a line containing the integer $\mathbf{N}$. The next line contains $\mathbf{N}$ integers, $\mathbf{S_1}$, $\mathbf{S_2}$, $\dots$, $\mathbf{S_N}$, where $\mathbf{S_i}$ represents the color of the $i$-th card from the left.</p>



## 출력


<p>For each test case, output one line containing <code>Case #x: y</code>, where $x$ is the test case number (starting from 1) and $y$ is the set of colors, once each, listed in the requested order. If it is impossible to write integers in the given cards while adhering to all the rules, $y$ must be <code>IMPOSSIBLE</code> instead.</p>



## 소스코드

[소스코드 보기](Rainbow%20Sort.cpp)