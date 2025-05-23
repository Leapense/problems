# 12713번: Ugly Numbers (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12713)


<p>Once upon a time in a strange situation, people called a number&nbsp;<em>ugly</em>&nbsp;if it was divisible by any of the one-digit primes (2, 3, 5 or 7). Thus, 14 is ugly, but 13 is fine. 39 is ugly, but 121 is not. Note that 0 is ugly. Also note that negative numbers can also be ugly; -14 and -39 are examples of such numbers.</p>

<p>One day on your free time, you are gazing at a string of digits, something like:</p>

<pre>123456
</pre>

<p>You are amused by how many possibilities there are if you are allowed to insert&nbsp;<em>plus</em>&nbsp;or&nbsp;<em>minus</em>&nbsp;signs between the digits. For example you can make</p>

<pre>1 + 234 - 5 + 6 = 236
</pre>

<p>which is ugly. Or</p>

<pre>123 + 4 - 56 = 71
</pre>

<p>which is not ugly.</p>

<p>It is easy to count the number of different ways you can play with the digits: Between each two adjacent digits you may choose put a plus sign, a minus sign, or nothing. Therefore, if you start with D digits there are 3<sup>D-1</sup>&nbsp;expressions you can make.</p>

<p>Note that it is fine to have leading zeros for a number. If the string is "01023", then "01023", "0+1-02+3" and "01-023" are legal expressions.</p>

<p>Your task is simple: Among the 3<sup>D-1</sup>&nbsp;expressions, count how many of them evaluate to an ugly number.</p>



## 입력


<p>The first line of the input file contains the number of cases,&nbsp;<strong>N</strong>. Each test case will be a single line containing a non-empty string of decimal digits.</p>

<p>Limits</p>

<ul>
<li>0 &lt;=&nbsp;<strong>N</strong>&nbsp;&lt;= 100.</li>
<li>The string in each test case will be non-empty and will contain only characters '0' through '9'.</li>
<li>Each string is no more than 13 characters long.</li>
</ul>



## 출력


<p>For each test case, you should output a line&nbsp;</p>

<pre>Case #<strong>X</strong>: <strong>Y</strong></pre>

<p>where&nbsp;<strong>X</strong>&nbsp;is the case number, starting from 1, and&nbsp;<strong>Y</strong>&nbsp;is the number of expressions that evaluate to an ugly number.</p>



## 소스코드

[소스코드 보기](Ugly%20Numbers%20(Small).cpp)