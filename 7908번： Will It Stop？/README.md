# 7908번: Will It Stop？ - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7908)


<p>Byteasar was wandering around the library of the University of Warsaw and at one of its facades he noticed a piece of a program with an inscription “Will it stop?”. The question seemed interesting, so Byteasar tried to tackle it after returning home. Unfortunately, when he was writing down the piece of code he made a mistake and noted:</p>

<pre>while n &gt; 1 do
  if n mod 2 = 0 then
    n := n / 2
  else
    n := 3 · n + 3</pre>

<p>Byteasar is now trying to figure out, for which initial values of the variable n the program he wrote down stops. We assume that the variable n has an unbounded size, i.e., it may attain arbitrarily large values.</p>



## 입력


<p>The first and only line of input contains one integer n (2 ≤ n ≤ 10<sup>14</sup>).</p>



## 출력


<p>In the first and only line of output you should write a single word TAK (i.e., yes in Polish), if the program stops for the given value of n, or NIE (no in Polish) otherwise.</p>



## 소스코드

[소스코드 보기](Will%20It%20Stop？.cpp)