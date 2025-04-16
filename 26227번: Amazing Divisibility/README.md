# 26227번: Amazing Divisibility - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26227)

<p>The sun was setting. Teddy sat in the bus 127, stuck in traffic. Bored, he'd already figured out how to get a hundred by juggling with the digits of his ticket number. He noticed that if he added the digits of the number of the bus to those of the year of his birth, 1997, he got a number divisible by 7. &lt;&lt;Heh!&gt;&gt;, --- Teddy thought and wrote 12 after the bus number, because that day was the 12th. Again, he got a number divisible by 7. The evening was becoming fun. Finally, he wrote the day of the month after the year of his birth.</p>

<p>"Coincidence? I don't think so!", --- Teddy wondered and dashed out of the bus to get home as fast as he could run, to write a program to evaluate the probability of his results.</p>

<p>Help Teddy write a program that finds the number of ways to choose a pair of numbers from a given set, such that if the digits of the second number are added to those of the first, the resulting number is divisible by 7.</p>

## 입력

<p>The first line of the input file contains an integer $N$ --- the number of numbers($2\leq N\leq 10^5$).</p>

<p>The second line contains $N$ space-separated different integers$a_i$ ($1\leq i\leq N$, $1\leq a_i\leq 10^9$).</p>

## 출력

<p>The output file must contain a single number - the number of ways to choose a pair of numbers from a given set, such that if the digits of the second number are added to those of the first, the resulting number is divisible  by 7.</p>

## 소스코드

[소스코드 보기](Amazing%20Divisibility.cpp)