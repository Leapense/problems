# 32801번: Generalized FizzBuzz - <img src="https://static.solved.ac/tier_small/2.svg" style="height:20px" /> Bronze IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32801)


<p>FizzBuzz is a common coding interview problem. The problem is as follows:</p>

<blockquote>
<p>Given a positive integer $n$, for all integers $i$ from 1 to $n$, inclusive:</p>

<ul>
<li>If $i$ is divisible by both $3$ and $5$, print "FizzBuzz".</li>
<li>Otherwise, if $i$ is divisible by $3$, print "Fizz".</li>
<li>Otherwise, if $i$ is divisible by $5$, print "Buzz".</li>
<li>Otherwise, print $i$.</li>
</ul>

<p>We are interested in a generalized version of FizzBuzz:</p>

<p>Given three positive integers $n$, $a$, and $b$, for all integers $i$ from 1 to $n$, inclusive:</p>

<ul>
<li>If $i$ is divisible by both $a$ and $b$, print "FizzBuzz".</li>
<li>Otherwise, if $i$ is divisible by $a$, print "Fizz".</li>
<li>Otherwise, if $i$ is divisible by $b$, print "Buzz".</li>
<li>Otherwise, print $i$.</li>
</ul>
</blockquote>

<p>Given $n$, $a$ and $b$, how many times are "Fizz", "Buzz", and "FizzBuzz" printed for a correct implementation?</p>



## 입력


<p>The first and only line of input contains three positive integers $n$, $a$ and $b$ $(1 \le n, a, b \le 10^6.)$</p>



## 출력


<p>Output three integers: the number of times "Fizz" is printed, the number of times "Buzz" is printed, and the number of times "FizzBuzz" is printed.</p>



## 소스코드

[소스코드 보기](Generalized%20FizzBuzz.py)