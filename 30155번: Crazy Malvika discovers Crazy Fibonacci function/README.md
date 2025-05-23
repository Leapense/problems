# 30155번: Crazy Malvika discovers Crazy Fibonacci function - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30155)


<p>Malvika was getting bored of the usual Fibonacci problems, and decided to add a little twist to it. She defined a new function f() with the following properties:</p>

<ul>
<li>She'll give you two integers, A and B. f(1) is defined to be A and f(2) is B.</li>
<li>And for all integers x ≥ 2, f(x) = f(x-1) + f(x+1).</li>
</ul>

<p>She'll give an integer N, and you have to find out what f(N) is. Output the answers modulo 10<sup>9</sup>+7.</p>



## 입력


<p>The first line of input contains a single integer T denoting number of test cases.</p>

<p>The only line of each test case contains three integers: A, B and N, denoting f(1), f(2) and the query.</p>



## 출력


<p>For each test case, output a line which contains a single integer, corresponding to f(N) for the given input.</p>



## 소스코드

[소스코드 보기](Main.java)