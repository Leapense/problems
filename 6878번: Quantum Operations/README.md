# 6878번: Quantum Operations - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6878)


<p>Quantum computing is currently a hot topic in research. If they can be built, quantum computers will have the ability to perform certain computing tasks much faster than any computer in existence today. Fortunately, you won't need a quantum computer to do this question.</p>

<p>A fundamental concept in quantum computing is the idea of a quantum operation. A quantum operation can be essentially thought of as a matrix. Also, if you perform two quantum operations in parallel on separate quantum data, this can be thought of as a larger quantum operation. Thinking of these operations in terms of matrices again, the resulting matrix from performing two matrices in parallel is called the <em>tensor product</em> of the two matrices (using the symbol $\otimes$). This is different than the normal product of matrices that you may have learned about.</p>

<p>In a tensor product, you are given two matrices (which are essentially two-dimensional arrays). We will call them $A$ and $B$, and we will represent the individual elements of these two matrices this way:</p>

<p>$$\displaystyle A = \begin{bmatrix} a_{11} &amp; a_{12} &amp; \cdots &amp; a_{1n} \\ a_{21} &amp; a_{22} &amp; \cdots &amp; a_{2n} \\ \vdots &amp; \vdots &amp; \ddots &amp; \vdots \\ a_{m1} &amp; a_{m2} &amp; \cdots &amp; a_{mn} \end{bmatrix},\ B = \begin{bmatrix} b_{11} &amp; b_{12} &amp; \cdots &amp; b_{1q} \\ b_{21} &amp; b_{22} &amp; \cdots &amp; b_{2q} \\ \vdots &amp; \vdots &amp; \ddots &amp; \vdots \\ b_{p1} &amp; b_{p2} &amp; \cdots &amp; b_{pq} \end{bmatrix}.$$</p>

<p>Notice that the size of matrix $A$ is $m \times n$ ($m$ rows and $n$ columns), and the size of $B$ is $p \times q$.</p>

<p>The tensor product of these two matrices will be an $mp \times nq$ matrix (with $mp$ rows and $nq$ columns) that looks like:</p>

<p>$$\displaystyle A \otimes B = \begin{bmatrix} a_{11}[B] &amp; a_{12}[B] &amp; \cdots &amp; a_{1n}[B] \\ a_{21}[B] &amp; a_{22}[B] &amp; \cdots &amp; a_{2n}[B] \\ \vdots &amp; \vdots &amp; \ddots &amp; \vdots \\ a_{m1}[B] &amp; a_{m2}[B] &amp; \cdots &amp; a_{mn}[B] \end{bmatrix},$$</p>

<p>where $a_{ij}[B]$ simply indicates that each element in $B$ is being multiplied by $a_{ij}$.</p>

<p>Finally notice that the tensor product is not <em>commutative</em>, which means that changing the order of matrices may change the answer $(A \otimes B \ne B \otimes A)$.</p>

<p>For more than two matrices, we will define $A \otimes B \otimes C = (A \otimes B) \otimes C$, although it does not technically matter, since the tensor product is <em>associative</em>.</p>

<p>Your task is to compute and output the tensor product of two or more given matrices.</p>



## 입력


<p>The first line of input will contain the number of matrices, $N$, a positive integer. Then, there are $N$ blocks of lines describing the matrices in order.</p>

<p>In each block, the first line will contain two positive integers, $r$ and $c$, separated by a space, indicating the number of rows and columns, respectively. Then, the next $r$ lines will denote the rows, in order. Each line will contain $c$ integers, separated by spaces.</p>



## 출력


<p>The output (to the screen) will be 6 integers in the following order:</p>

<ul>
<li>the maximum element in the tensor product</li>
<li>the minimum element in the tensor product</li>
<li>the maximum row sum (i.e., sum of entries in each row)</li>
<li>the minimum row sum</li>
<li>the maximum column sum</li>
<li>the minimum column sum</li>
</ul>

<p>You may assume that the tensor product matrix will have no more than $1024$ rows and no more than $1024$ columns.</p>



## 소스코드

[소스코드 보기](Quantum%20Operations.py)