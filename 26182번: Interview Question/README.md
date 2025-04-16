# 26182번: Interview Question - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26182)

<p><em>Fizz Buzz</em> is a party game that is often used as a programming exercise in job interviews. In the game, there are two positive integers $a$ and $b$, and the game consists of counting up through the positive integers, replacing any number by <code>Fizz</code> if it is a multiple of $a$, by <code>Buzz</code> if it is a multiple of $b$, and by <code>FizzBuzz</code> if it is a multiple of both $a$ and $b$. The most common form of the game has $a=3$ and $b=5$, but other parameters are allowed.</p>

<p>Your task here is to solve the reverse problem: given a transcript of part of the game (not necessarily starting at 1), find possible values of $a$ and $b$ that could have been used to generate it.</p>

<p>Figure I.1 shows some sample sequences for various values of $a$ and $b$.</p>

<table class="table table-bordered">
<tbody>
<tr>
<td>$a=3, b=5:$</td>
<td><code>1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz</code></td>
</tr>
<tr>
<td>$a=6, b=2:$</td>
<td><code>1 Buzz 3 Buzz 5 FizzBuzz 7 Buzz 9 Buzz 11 FizzBuzz 13</code></td>
</tr>
<tr>
<td>$a=4, b=4:$</td>
<td><code>1 2 3 FizzBuzz 5 6 7 FizzBuzz 9 10 11 FizzBuzz 13 14</code></td>
</tr>
</tbody>
</table>

<p style="text-align: center;">Figure I.1: Example sequences for <em>Fizz Buzz</em>.</p>

## 입력

<p>The input consists of:</p>

<ul>
<li>One line with two integers $c$ and $d$ ($1 \le c \le d \le 10^5$), indicating that your transcript starts at $c$ and ends at $d$.</li>
<li>One line with $d-c+1$ integers and strings, the contents of the transcript.</li>
</ul>

<p>It is guaranteed that the transcript is valid for some integers $a$ and $b$ with $1 \le a,b \le 10^6$, according to the rules laid out above.</p>

## 출력

<p>Output two positive integers $a$ and $b$ ($1 \le a,b \le 10^6$) that are consistent with the given transcript.</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>

## 소스코드

[소스코드 보기](Interview%20Question.cpp)