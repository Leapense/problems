# 12046번: Not So Random (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12046)


<p>There is a certain "random number generator" (RNG) which takes one nonnegative integer as input and generates another nonnegative integer as output. But you know that the RNG is really not very random at all! It uses a fixed number&nbsp;<strong>K</strong>, and always performs one of the following three operations:</p>

<ul>
<li>with probability&nbsp;<strong>A</strong>/100: return the bitwise AND of the input and&nbsp;<strong>K</strong></li>
<li>with probability&nbsp;<strong>B</strong>/100: return the bitwise OR of the input and&nbsp;<strong>K</strong></li>
<li>with probability&nbsp;<strong>C</strong>/100: return the bitwise XOR of the input and&nbsp;<strong>K</strong></li>
</ul>

<p>(You may assume that the RNG&nbsp;<em>is</em>&nbsp;truly random in the way that it chooses the operation each time, based on the values of&nbsp;<strong>A</strong>,&nbsp;<strong>B</strong>, and&nbsp;<strong>C</strong>.)</p>

<p>You have&nbsp;<strong>N</strong>&nbsp;copies of this RNG, and you have arranged them in series such that output from one machine will be the input for the next machine in the series. If you provide&nbsp;<strong>X</strong>&nbsp;as an input to the first machine, what will be the expected value of the output of the final machine in the series?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow; each consists of one line with six integers&nbsp;<strong>N</strong>,&nbsp;<strong>X</strong>,&nbsp;<strong>K</strong>,&nbsp;<strong>A</strong>,&nbsp;<strong>B</strong>, and&nbsp;<strong>C</strong>. Respectively, these denote the number of machines, the initial input, the fixed number with which all the bitwise operations will be performed (on every machine), and 100 times the probabilities of the bitwise AND, OR, and XOR operations.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 50.</li>
<li>0 ≤&nbsp;<strong>A</strong>&nbsp;≤ 100.</li>
<li>0 ≤&nbsp;<strong>B</strong>&nbsp;≤ 100.</li>
<li>0 ≤&nbsp;<strong>C</strong>&nbsp;≤ 100.</li>
<li><strong>A+B+C</strong>&nbsp;= 100.</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 10.</li>
<li>0 ≤&nbsp;<strong>X</strong>&nbsp;≤ 10<sup>4</sup>.</li>
<li>0 ≤&nbsp;<strong>K</strong>&nbsp;≤ 10<sup>4</sup>.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the expected value of the final output. y will be considered correct if it is within an absolute or relative error of 10<sup>-9</sup>&nbsp;of the correct answer. See the&nbsp;<a href="https://code.google.com/codejam/faq.html#floating_point" style="color: rgb(85, 26, 139);" target="_blank">FAQ</a>&nbsp;for an explanation of what that means, and what formats of real numbers we accept.</p>



## 소스코드

[소스코드 보기](Not%20So%20Random%20(Small).cpp)