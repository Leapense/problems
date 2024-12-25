# 12076번: gCube (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12076)


<p>Googlers are very interested in cubes, but they are bored with normal three-dimensional cubes and also want to think about other kinds of cubes! A "D-dimensional cube" has D dimensions, all of equal length. (D may be any positive integer; for example, a 1-dimensional cube is a line segment, and a 2-dimensional cube is a square, and a 4-dimensional cube is a hypercube.) A "D-dimensional cuboid" has D dimensions, but they might not all have the same lengths.</p>

<p>Suppose we have an&nbsp;<strong>N</strong>-dimensional cuboid. The&nbsp;<strong>N</strong>&nbsp;dimensions are numbered in order (0, 1, 2, ..., N - 1), and each dimension has a certain length. We want to solve many subproblems of this type:</p>

<ol>
<li>Take all consecutive dimensions between the&nbsp;<strong>L<sub>i</sub></strong>-th dimension and&nbsp;<strong>R<sub>i</sub></strong>-th dimension, inclusive.</li>
<li>Use those dimensions to form a D-dimensional cuboid, where D =&nbsp;<strong>R<sub>i</sub></strong>&nbsp;-&nbsp;<strong>L<sub>i</sub></strong>&nbsp;+ 1. (For example, if&nbsp;<strong>L<sub>i</sub></strong>&nbsp;= 3 and&nbsp;<strong>R<sub>i</sub></strong>&nbsp;= 6, we would form a 4-dimensional cuboid using the 3rd, 4th, 5th, and 6th dimensions of our&nbsp;<strong>N</strong>-dimensional cuboid.)</li>
<li>Reshape it into a D-dimensional cube&nbsp;<strong>that has exactly the same volume as that D-dimensional cuboid</strong>, and find the edge length of that cube.</li>
</ol>

<p>Each test case will have&nbsp;<strong>M</strong>&nbsp;subproblems like this, all of which use the same original&nbsp;<strong>N</strong>-dimensional cuboid.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow.</p>

<p>Each test case begins with two integers&nbsp;<strong>N</strong>&nbsp;and&nbsp;<strong>M</strong>;&nbsp;<strong>N</strong>&nbsp;is the number of dimensions and&nbsp;<strong>M</strong>&nbsp;is the number of queries. Then there is one line with&nbsp;<strong>N</strong>&nbsp;positive integers&nbsp;<strong>a<sub>i</sub></strong>, which are the lengths of the dimensions, in order. Then,&nbsp;<strong>M</strong>&nbsp;lines follow. In the ith line, there are two integers&nbsp;<strong>L<sub>i</sub></strong>&nbsp;and&nbsp;<strong>R<sub>i</sub></strong>, which give the range of dimensions to use for the ith subproblem.</p>



## 출력


<p>For each test case, output one line containing "Case #x:", where x is the test case number (starting from 1). After that, output&nbsp;<strong>M</strong>&nbsp;lines, where the ith line has the edge length for the ith subproblem. An edge length will be considered correct if it is within an absolute error of 10<sup>-6</sup>&nbsp;of the correct answer.</p>



## 소스코드

[소스코드 보기](gCube%20(Small).cpp)