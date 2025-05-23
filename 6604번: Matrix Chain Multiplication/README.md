# 6604번: Matrix Chain Multiplication - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6604)


<p>Suppose you have to evaluate an expression like A*B*C*D*E where A,B,C,D and E are matrices.</p>

<p>Since matrix multiplication is associative, the order in which multiplications are performed is arbitrary. However, the number of elementary multiplications needed strongly depends on the evaluation order you choose.</p>

<p>For example, let A be a 50*10 matrix, B a 10*20 matrix and C a 20*5 matrix.</p>

<p>There are two different strategies to compute A*B*C, namely (A*B)*C and A*(B*C).</p>

<p>The first one takes 15000 elementary multiplications, but the second one only 3500.</p>

<p>Your job is to write a program that determines the number of elementary multiplications needed for a given evaluation strategy.</p>



## 입력


<p>Input consists of two parts: a list of matrices and a list of expressions.</p>

<p>The first line of the input file contains one integer <em>n</em> (1 n n lines each contain one capital letter, specifying the name of the matrix, and two integers, specifying the number of rows and columns of the matrix.</p>

<p>The second part of the input file strictly adheres to the following syntax (given in EBNF):</p>

<pre>SecondPart = Line { Line } &lt;EOF&gt;
Line       = Expression &lt;CR&gt;
Expression = Matrix | "(" Expression Expression ")"
Matrix     = "A" | "B" | "C" | ... | "X" | "Y" | "Z"</pre>



## 출력


<p>For each expression found in the second part of the input file, print one line containing the word "error" if evaluation of the expression leads to an error due to non-matching matrices. Otherwise print one line containing the number of elementary multiplications needed to evaluate the expression in the way specified by the parentheses.</p>



## 소스코드

[소스코드 보기](Matrix%20Chain%20Multiplication.cpp)