# 32788번: Big Integers - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32788)


<p>Nick is preparing a problem for a programming contest about comparing big integers. He has decided on the input format for the integers: They will be expressed in base 62, with $0$ through $9$ representing digit values $0$ through $9$, lowercase letters <code>a</code> through <code>z</code> representing digit values $10$ through $35$, and uppercase letters <code>A</code> through <code>Z</code> representing digit values $36$ through $61$. For example, the string <code>Aa</code> would represent $36 \times 62 + 10 = 2242$.</p>

<p>The problem is to take two strings representing two distinct base 62 integers and determine which of the two is smaller. However, Nick wrote his judge solution incorrectly, assuming that the lexicographically smaller string is always the smaller integer.</p>

<p>Given some test cases, determine for each if Nick's solution would report the correct result.</p>



## 입력


<p>The first line of input contains a single integer $t$ ($1\leq t \leq 10^5$). This is the number of test cases.</p>

<p>Each test case consists of two lines.</p>

<p>The first line contains a single alphanumeric string of length at most $10^5$.</p>

<p>The second line contains a single alphanumeric string of length at most $10^5$.</p>

<p>Both strings are guaranteed to contain no unnecessary leading zeroes, and the two strings are guaranteed to be distinct.</p>

<p>The sum of the lengths of all input strings across all $t$ test cases is guaranteed to be at most $2 \times 10^6$.</p>



## 출력


<p>For each test case, output a single line with <code>YES</code> if the lexicographically smaller string represents the smaller integer in base 62, and output a single line with <code>NO</code> otherwise.</p>



## 소스코드

[소스코드 보기](Big%20Integers.cpp)