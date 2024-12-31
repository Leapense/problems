# 13880번: A Rational Sequence (Take 3) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13880)


<p>An infinite full binary tree labeled by positive rational numbers is defined by:</p>

<ul>
<li>The label of the root is 1/1.</li>
<li>The left child of label p/q is p/(p+q).</li>
<li>The right child of label p/q is (p+q)/q.</li>
</ul>

<p>The top of the tree is shown in the following figure:</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13880/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-11-19%20%EC%98%A4%EC%A0%84%204.09.27.png" style="height:280px; width:521px"></p>

<p>A rational sequence is defined by doing a level order (breadth first) traversal of the tree (indicated by the light dashed line). So that:</p>

<pre><code>F(1) = 1/1, F(2) = 1/2, F(3) = 2/1, F(4) = 1/3, F(5) = 3/2, F(6) = 2/3, … </code></pre>

<p>Write a program to compute the nth element of the sequence, F(n). Does this problem sound familiar? Well it should! We had variations of this problem at the 2014 and 2015 Greater NY Regionals.&nbsp;</p>



## 입력


<p>The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow.</p>

<p>Each data set should be processed identically and independently. Each data set consists of a single line of input. It contains the data set number, K, and the index, N, of the sequence element to compute (1 &lt;= N &lt;= 2147483647).</p>



## 출력


<p>For each data set there is a single line of output. It contains the data set number, K, followed by a single space which is then followed by the numerator of the fraction, followed immediately by a forward slash (‘/’) followed immediately by the denominator of the fraction. Inputs will be chosen so neither the numerator nor the denominator will overflow an 32-bit unsigned integer.</p>



## 소스코드

[소스코드 보기](A%20Rational%20Sequence%20(Take%203).cpp)