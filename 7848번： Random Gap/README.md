# 7848번: Random Gap - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7848)


<p>The pseudo-random number genegators (or RNGs for short) are widely used in statistical calculations. One of the simplest and ubiquitious is the linear congruence RNG, that calculates the <i>n</i>-th random number <i>R<sub>n</sub></i> as <i>R<sub>n</sub></i> = (<i>aR</i><sub><i>n</i> - 1</sub> + <i>c</i>) mod <i>m</i>, where <i>a</i>, <i>c</i> and <i>m</i> are constants. For example, the sequence for <i>a</i> = 15, <i>c</i> = 7, <i>m</i> = 100 and starting value <i>R</i><sub>0</sub> = 1 is 1, 22, 37, 62, 37, 62, ...</p>

<p>Linear RNG is very fast, and can yield surprisinly good sequence of random numbers, given the right choice of constants. There are various measures of RNG quality, and your task is to calculate one of them, namely the longest gap between members of the sequence. More precisely, given the values of <i>a</i>, <i>c</i>, <i>m</i>, and <i>R</i><sub>0</sub>, find such two elements <i>R<sub>i</sub></i> &lt; <i>R<sub>j</sub></i> that:</p>

<ol>
<li>there are no other <i>R<sub>k</sub></i> <i>R<sub>i</sub></i> &amp;le; <i>R<sub>k</sub></i> &amp;le; <i>R<sub>j</sub></i>,</li>
<li>the difference <i>R<sub>j</sub></i> &amp;minus; <i>R<sub>i</sub></i> is maximal.</li>
</ol>



## 입력


<p>Input file contains integer numbers <i>a</i> <i>c</i> <i>m</i> <i>R</i><sub>0</sub>.</p>



## 출력


<p>Output file should contain the single number -- the maximal difference found.</p>



## 소스코드

[소스코드 보기](Random%20Gap.cpp)