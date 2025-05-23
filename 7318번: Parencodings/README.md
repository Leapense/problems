# 7318번: Parencodings - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7318)


<p>Let S = s<sub>1</sub>s<sub>2</sub>...s<sub>2n</sub> be a well-formed string of parentheses. S can be encoded in two different ways:</p>

<ol>
<li>By an integer sequence P = p<sub>1</sub>p<sub>2</sub>...p<sub>n</sub> where pi is the number of left parentheses before the i-th right parenthesis in S (P-sequence).</li>
<li>By an integer sequence W = w<sub>1</sub>w<sub>2</sub> w<sub>n</sub> where for each right parenthesis, say a in S, we associate an integer which is the number of right parentheses counting from the matched left parenthesis of a up to a. (W-sequence).</li>
</ol>

<p>Following is an example of the above encodings:</p>

<p><br>
S&nbsp;&nbsp; &nbsp;(((()()())))<br>
P-sequence&nbsp;&nbsp; &nbsp;4 5 6666<br>
W-sequence&nbsp;&nbsp; &nbsp;1 1 1456</p>

<p>Write a program to convert P-sequence of a well-formed string to the W-sequence of the same string.</p>



## 입력


<p>The first line of the input file contains a single integer t ( 1 ≤ t ≤ 10), the number of test cases, followed by the input data for each test case. The first line of each test case is an integer n ( 1 ≤ n ≤ 20), and the second line is the P-sequence of a well-formed string. It contains n positive integers, separated with blanks, representing the P-sequence.</p>

<p>&nbsp;</p>



## 출력


<p>The output file consists of exactly t lines corresponding to test cases. For each test case, the output line should contain n integers describing the W-sequence of the string corresponding to its given P-sequence.</p>



## 소스코드

[소스코드 보기](Parencodings.cpp)