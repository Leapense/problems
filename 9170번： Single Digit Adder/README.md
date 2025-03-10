# 9170번: Single Digit Adder - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9170)


<p>Write a program that can evaluate expressions from the following roughly BNF (Backus Naur Form) grammar:</p>

<pre>expr ::=  term | expr ‘+’ term | expr ‘-’ term
unary_op ::= ‘+’ term | ‘-’ term
term ::= ‘(’ expr ‘)’ | ‘(’ unary_op ‘)’ | literal
literal ::= [0-9]</pre>

<p>There will be no whitespace within an expression. All expressions will consist solely of the characters (, ), +, -, and the digits 0 through 9. You may assume that all input is well-formed.</p>



## 입력


<p>The input will consist of one expression per line followed by a newline. The length of expression does not exceed 200.</p>

<p>There will be no blank lines in the file.</p>



## 출력


<p>For each expression, output its integer value, followed by a single newline.</p>



## 소스코드

[소스코드 보기](Single%20Digit%20Adder.cpp)