# 32443번: Lecographically Maximum - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32443)


<p>A list of $N$ integers $a_1, \dots , a_N$ is stored in the memory of an electronic device. This device has a very peculiar operation available: bit swapping between numbers. More precisely, given integers $i$, $j$ and $k$, this operation swaps the $k$-th bit of the integer $a_i$ with the $k$-th bit of the integer $a_j$ (and vice-versa).</p>

<p>Very interesting phenomena can occur when performing this operation one or more times, such as obtaining numbers that did not even belong to the original list, or even numbers larger or smaller than all the original elements.</p>

<p>For this problem, we are interested in using the operation as many times as necessary to change the list of numbers so that the resulting list is the lexicographically maximum, that is, that $a_1$ is the largest possible, that $a_2$ is the largest possible among the possible solutions that maximize $a_1$, and so on.</p>



## 입력


<p>The first line of input contains an integer $N$ ($1 ≤ N ≤ 10^5$) and the second line contains $N$ integers, separated by spaces, corresponding to the list $a_1, \dots , a_N$ ($0 ≤ a_i ≤ 10^9$).</p>



## 출력


<p>Your program should print a single line containing $N$ space-separated integers corresponding to the lexicographically maximum obtainable sequence.</p>



## 소스코드

[소스코드 보기](Lecographically%20Maximum.cpp)