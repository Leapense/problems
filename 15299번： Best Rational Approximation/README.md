# 15299번: Best Rational Approximation - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15299)


<p>Many microcontrollers have no floating point unit but do have a (reasonably) fast integer divide unit. In these cases it may pay to use rational values to approximate floating point constants. For instance,</p>

<p style="text-align:center">355/113 = 3.1415929203539823008849557522124</p>

<p>is a quite good approximation to</p>

<p style="text-align:center">π = 3.14159265358979323846</p>

<p>A best rational approximation, p/q, to a real number, x, with denominator at most M is a rational number, p/q (in lowest terms), with q &lt;= M such that, for any integers, a and b with b &lt;= M, and a and b relatively prime, p/q is at least as close to x as a/b:</p>

<p style="text-align:center">|x – p/q| ≤ |x – a/b|</p>

<p>Write a program to compute the best rational approximation to a real number, x, with denominator at most M.</p>



## 입력


<p>The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set should be processed identically and independently.</p>

<p>Each data set consists of a single line of input. It contains the data set number, K, followed by the maximum denominator value, M (15 ≤ M ≤ 100000), followed by a floating-point value, x, (0 ≤ x &lt; 1).</p>



## 출력


<p>For each data set there is a single line of output. The single output line consists of the data set number, K, followed by a single space followed by the numerator, p, of the best rational approximation to x, followed by a forward slash (/) followed by the denominator, q, of the best rational approximation to x.</p>



## 소스코드

[소스코드 보기](Best%20Rational%20Approximation.cpp)