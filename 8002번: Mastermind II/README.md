# 8002번: Mastermind II - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8002)


<p>We shall consider sequences that meet the following conditions:</p>

<p>&nbsp;&nbsp; &nbsp;the length of the sequence is c,<br>
&nbsp;&nbsp; &nbsp;the elements of the sequence are digits from the range of 1-9,<br>
&nbsp;&nbsp; &nbsp;the elements are not repeated in the sequence.</p>

<p>A single sequence will be called a code.</p>

<p>When two codes are given we estimate their compatibility giving two numbers. The first one (column A in the example) is the sum of those digits that occur in both codes and appear on the same positions in both sequences, whilst the second number (column B) is the sum of those digits that occur in both codes but appear on different positions.</p>

<p>We are given c codes and their compatibility estimations with some unknown code. One should find and present the unknown code. Sample data and a result for c=3 are presented below.</p>

<p>&nbsp;&nbsp; &nbsp;A &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;B &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; codes<br>
&nbsp;&nbsp; &nbsp;4 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;0 &nbsp; &nbsp; &nbsp; &nbsp; 4&nbsp;&nbsp; &nbsp;9&nbsp;&nbsp; &nbsp;7<br>
&nbsp;&nbsp; &nbsp;0 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;10 &nbsp; &nbsp; &nbsp; &nbsp;6&nbsp;&nbsp; &nbsp;7&nbsp;&nbsp; &nbsp;4<br>
&nbsp;&nbsp; &nbsp;0 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;5 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;9&nbsp;&nbsp; &nbsp;4&nbsp;&nbsp; &nbsp;1<br>
&nbsp;<br>
&nbsp;&nbsp; &nbsp;unknown code &nbsp;&nbsp; &nbsp;4&nbsp;&nbsp; &nbsp;1&nbsp;&nbsp; &nbsp;6</p>

<p>
Write a program which:</p>

<ul>
<li>reads a description of codes and estimations of their compatibility,</li>
<li>finds a code meeting the conditions of the task,</li>
<li>writes the result.</li>
</ul>



## 입력


<p>Your program should read the description from the standard input. In the first line there is one integer c, 1 ≤ c ≤ 9. In the following c lines there are the descriptions of the given codes of digits and the estimations of their compatibility with some unknown code, one per line. In each of the lines there are c+2 non-negative integers separated by single spaces. The first and the second number are the estimation of compatibility of the given code with the unknown one, and the last &nbsp;numbers are different digits from the range of 1-9 forming the given code.</p>

<p>&nbsp;</p>



## 출력


<p>Your program should write to the standard output. There should be c different digits from the range of 1-9 forming the code to be found, separated by single spaces.</p>

<p>You may assume that for the test data there is at least one solution. If for the input data there exist many satisfying codes, your program should write out only one of them (arbitrary).</p>



## 소스코드

[소스코드 보기](Mastermind%20II.cpp)