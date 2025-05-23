# 12382번: Diamond Inheritance (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12382)


<p>You are asked to help diagnose class diagrams to identify instances of diamond inheritance. The following example class diagram illustrates the property of diamond inheritance. There are four classes: A, B, C and D. An arrow pointing from X to Y indicates that class X inherits from class Y.</p>

<p><img src="https://onlinejudgeimages.s3.amazonaws.com/problem/12382/images-49.png" style="vertical-align:middle"></p>

<p>In this class diagram, D inherits from both B and C, B inherits from A, and C also inherits from A. An inheritance path from X to Y is defined as a sequence of classes X, C<sub>1</sub>, C<sub>2</sub>, C<sub>3</sub>, ..., C<sub>n</sub>, Y where X inherits from C<sub>1</sub>, C<sub>i</sub>&nbsp;inherits from C<sub>i + 1</sub>&nbsp;for 1 ≤ i ≤ n - 1, and C<sub>n</sub>&nbsp;inherits from Y. There are two inheritance paths from D to A in the example above. The first path is D, B, A and the second path is D, C, A.</p>

<p>A class diagram is said to contain a diamond inheritance if there exists a pair of classes X and Y such that there are at least two different inheritance paths from X to Y. The above class diagram is a classic example of diamond inheritance. Your task is to determine whether or not a given class diagram contains a diamond inheritance.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;&nbsp;<strong>T</strong>&nbsp;test cases follow, each specifies a class diagram. The first line of each test case gives the number of classes in this diagram,&nbsp;<strong>N</strong>. The classes are numbered from 1 to&nbsp;<strong>N</strong>.&nbsp;&nbsp;<strong>N</strong>&nbsp;lines follow. The i<sup>th</sup>&nbsp;line starts with a non-negative integer&nbsp;<strong>M<sub>i</sub></strong>&nbsp;indicating the number of classes that class&nbsp;<em>i</em>&nbsp;inherits from. This is followed by&nbsp;<strong>M<sub>i</sub></strong>&nbsp;distinct positive integers each from 1 to&nbsp;<strong>N</strong>&nbsp;representing those classes. You may assume that:</p>

<ul>
<li>If there is an inheritance path from X to Y then there is no inheritance path from Y to X.</li>
<li>A class will never inherit from itself.</li>
</ul>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 50.</li>
<li>0 ≤&nbsp;<strong>M<sub>i</sub></strong>&nbsp;≤ 10.</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 50.</li>
</ul>



## 출력


<p>For each diagram, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is "Yes" if the class diagram contains a diamond inheritance, "No" otherwise.</p>



## 소스코드

[소스코드 보기](Diamond%20Inheritance%20(Small).cpp)