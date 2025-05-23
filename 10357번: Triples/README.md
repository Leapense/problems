# 10357번: Triples - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10357)


<p>Mr. A invites you to solve the following problem:</p>

<p>“Let be \(m\) and \(n\) two positive integers, \(5 \le m \le 100\), \(2 \le n \le 100\). Consider the following sets of triples:</p>

<p>\[T_{m,j} = \left\{ { (x,y,z) \in \mathbb{N}^{3} }|{ x \le y \le z \le m ~ and ~ x^j + y^j = z^j } \right\} , &nbsp;j = 2 .. n\]</p>

<p>where \(\mathbb{N}\) is the set of nonnegative integers (\(\mathbb{N}\) = {0, 1, 2, ...}).</p>

<p>The problem asks you to compute the sum \(S_{m,n}\):</p>

<p>\[S_{m,n} = \sum_{j=2}^{n}{card(T_{m,j})}\]</p>

<p>where \(card(T_{m,j})\) is the number of elements of the set \(T_{m,j}\)."</p>



## 입력


<p>The input file contains a single test. The first line of the input file contains the value of \(m\)and the second line contains the value of \(n\).</p>

<p>&nbsp;</p>



## 출력


<p>The result will be written to standard output.</p>



## 소스코드

[소스코드 보기](Triples.cpp)