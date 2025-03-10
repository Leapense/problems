# 9265번: Count - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9265)


<p>You have:</p>

<ul>
<li>A matrix of natural numbers, with the property that all rows and all columns are sorted in ascending order (i.e. A[i,j]&gt;=A[i-1,j] and A[i,j]&gt;=A[i,j-1] for all i,j)</li>
<li>One or several pairs of numbers (X,Y) with the property that Y&gt;=X.</li>
</ul>

<p>For each (X,Y) pair, count how many numbers from the matrix are greater than or equal to X but smaller than or equal to Y.</p>



## 입력


<p>The input file is a binary file containing 32-bit integer numbers. The input file consists of:</p>

<ul>
<li>One integer N representing the number of rows (no more than 10000)</li>
<li>One integer M representing the number of columns (no more than 10000)</li>
<li>NxM integers, representing the values from the matrix, row by row&nbsp;</li>
<li>An unspecified number of integers, representing the (X,Y) pairs, one pair at a time.&nbsp;</li>
</ul>

<p>There will be at least one pair and at most 100 pairs in the file – and there will not be an incomplete pair at the end of the file.</p>



## 출력


<p>For each pair you should write to standard output a value representing how many numbers in the matrix are greater than or equal to X but smaller than or equal to Y.</p>



## 소스코드

[소스코드 보기](Count.cpp)