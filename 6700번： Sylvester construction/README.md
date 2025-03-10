# 6700번: Sylvester construction - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6700)


<p>A Hadamard matrix of order n is an n × n matrix containing only 1s and -1s, called H<sub>n</sub>, such that \(&nbsp;H_nH_n^T = nI_n \)&nbsp;where I<sub>n</sub> is the n × n identity matrix. An interesting property of Hadamard matrices is that they have the maximum possible determinant of any n × n matrix with elements in the range [−1,1]. Hadamard matrices have applications in error- correcting codes and weighing design problems.</p>

<p>The Sylvester construction is a way to create a Hadamard matrix of size 2n given H<sub>n</sub>. H<sub>2n</sub> can be constructed as:</p>

<p>\( H_{2n} = \begin{pmatrix} H_n &amp; H_n \\ H_n &amp; -H_n \end{pmatrix} \)</p>

<p>For example:&nbsp;</p>

<p>H<sub>1</sub> = (1)</p>

<p>\( H_2 = \begin{pmatrix} 1 &amp; 1 \\ 1 &amp; -1 \end{pmatrix} \)</p>

<p>and so on.</p>

<p>In this problem you are required to print a part of a Hadamard matrix<br>
constructed in the way described above.</p>



## 입력


<p>The first number in the input is the number of test cases to follow. For each test case there are five integers: n, x, y, w and h. n will be between 1 and 2<sup>62</sup> (inclusive) and will be a power of 2. x and y specify the upper left corner of the sub matrix to be printed, w and h specify the width and height respectively. Coordinates are zero based, so 0 ≤ x,y &lt; n. You can assume that the sub matrix will fit entirely inside the whole matrix and that 0 &lt; w,h ≤ 20. There will be no more than 1000 test cases.</p>



## 출력


<p>For each test case print the sub matrix followed by an empty line.</p>



## 소스코드

[소스코드 보기](Main.java)