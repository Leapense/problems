# 6374번: To the Max - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6374)


<p>Given a two-dimensional array of positive and negative integers, a sub-rectangle is any contiguous sub-array of size 1 × 1 or greater located within the whole array. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle.</p>

<p>As an example, the maximal sub-rectangle of the array:</p>

<pre>&nbsp;0 -2 -7 0
&nbsp;9 &nbsp;2 -6 2
-4 &nbsp;1 -4 1
-1 &nbsp;8 0 -2</pre>

<p>is in the lower left corner:</p>

<pre>&nbsp;9 2
-4 1
-1 8</pre>

<p>and has a sum of 15.</p>



## 입력


<p>The input consists of an N × N array of integers. The input begins with a single positive integer N on a line by itself, indicating the size of the square two-dimensional array. This is followed by N<sup>2</sup> integers separated by whitespace (spaces and newlines). These are the N<sup>2</sup> integers of the array, presented in row-major order. That is, all numbers in the first row, left to right, then all numbers in the second row, left to right, etc. N may be as large as 100. The numbers in the array will be in the range [-127,127].</p>



## 출력


<p>Output the sum of the maximal sub-rectangle.</p>



## 소스코드

[소스코드 보기](To%20the%20Max.cpp)