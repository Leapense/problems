# 11517번: Positive Con Sequences - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11517)


<p>Your younger sister is studying for an upcoming standardized test in mathematics. She needs practice with the common style of problem in which the student is asked to fill in the missing value in a sequence of numbers.</p>

<p>The vast majority of these problems feature either arithmetic sequences (where each number in the sequence is formed by adding an integer constant to the prior number) or geometric sequences (where each number in the sequence is formed by multiplying the prior number by an integer constant).</p>

<p>Write a program that will help your sister practice on this style of problem by allowing her to check her answers on sample problems.</p>



## 입력


<p>Input will consist of one or more datasets.</p>

<p>Each dataset will be a single line containing 4 integers defining a sequence. One of these will be -1, denoting the missing value. The remainder will be positive integers in the range 1..10,000, inclusive. Other than the -1 placeholder value, the values will be in non-decreasing order.</p>

<p>End of input will be signaled by a line containing four -1 values.</p>



## 출력


<p>For each dataset, print one line of output.</p>

<p>If an integer in the range 1..10,000 inclusive exists that can be filled in to the missing value position to create an arithmetic or geometric sequence, print that missing value.</p>

<p>If there is no such positive integer, print -1.</p>



## 소스코드

[소스코드 보기](Positive%20Con%20Sequences.py)