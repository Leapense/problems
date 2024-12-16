# 10487번: 4 thought - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10487)


<p>Write a program which, given an integer n as input, will produce a mathematical expression whose solution is n. The solution is restricted to using exactly four 4’s and exactly three of the binary operations selected from the set {∗, +, −, /}. The number 4 is the ONLY number you can use. You are not allowed to concatenate fours to generate other numbers, such as 44 or 444.</p>

<p>For example given n = 0, a solution is 4 ∗ 4 − 4 ∗ 4 = 0. Given n = 7, a solution is 4 + 4 − 4 / 4 = 7. Division is considered truncating integer division, so that 1/4 is 0 (instead of 0.25). Assume the usual precedence of operations so that 4 + 4 ∗ 4 = 20, not 32. Not all integer inputs have solutions using four 4’s with the aforementioned restrictions (consider n = 11).</p>



## 입력


<p>Input begins with an integer 1 ≤ m ≤ 1000, indicating the number of test cases that follow. Each of the next m lines contain exactly one integer value for n in the range −1000000 ≤ n ≤ 1000000.</p>



## 출력


<p>For each test case print one line of output containing either an equation using four 4’s to reach the target number or the phrase no solution. Print the equation following the format of the sample output; use spaces to separate the numbers and symbols printed. If there is more than one such equation which evaluates to the target integer, print any one of them.</p>



## 소스코드

[소스코드 보기](4%20thought.cpp)