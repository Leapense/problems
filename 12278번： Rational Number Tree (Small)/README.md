# 12278번: Rational Number Tree (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12278)


<p>Consider an infinite complete binary tree where the root node is 1/1 and left and right childs of node p/q are p/(p+q) and (p+q)/q, respectively. This tree looks like:</p>

<pre>         1/1
    ______|______
    |           |
   1/2         2/1
 ___|___     ___|___
 |     |     |     |
1/3   3/2   2/3   3/1
...
</pre>

<p>It is known that every positive rational number appears exactly once in this tree. A level-order traversal of the tree results in the following array:</p>

<pre>1/1, 1/2, 2/1, 1/3, 3/2, 2/3, 3/1, ...
</pre>

<p>Please solve the following two questions:</p>

<ol>
<li>Find the&nbsp;<b>n</b>-th element of the array, where&nbsp;<b>n</b>&nbsp;starts from 1. For example, for the input 2, the correct output is 1/2.</li>
<li>Given&nbsp;<b>p/q</b>, find its position in the array. As an example, the input 1/2 results in the output 2.</li>
</ol>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<b>T</b>.&nbsp;<b>T</b>&nbsp;test cases follow. Each test case consists of one line. The line contains a problem id (1 or 2) and one or two additional integers:</p>

<ol>
<li>If the problem id is 1, then only one integer&nbsp;<b>n</b>&nbsp;is given, and you are expected to find the&nbsp;<b>n</b>-th element of the array.</li>
<li>If the problem id is 2, then two integers&nbsp;<b>p</b>&nbsp;and&nbsp;<b>q</b>&nbsp;are given, and you are expected to find the position of&nbsp;<b>p/q</b>&nbsp;in the array.</li>
</ol>



## 출력


<p>For each test case:</p>

<ol>
<li>If the problem id is 1, then output one line containing "<code>Case #x: p q</code>", where&nbsp;<code>x</code>&nbsp;is the case number (starting from 1), and&nbsp;<code>p</code>,&nbsp;<code>q</code>&nbsp;are numerator and denominator of the asked array element, respectively.</li>
<li>If the problem id is 2, then output one line containing "<code>Case #x: n</code>", where&nbsp;<code>x</code>&nbsp;is the case number (starting from 1), and&nbsp;<code>n</code>&nbsp;is the position of the given number.</li>
</ol>



## 소스코드

[소스코드 보기](Rational%20Number%20Tree%20(Small).cpp)