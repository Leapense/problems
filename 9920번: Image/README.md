# 9920번: Image - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9920)


<p>This task concerns the output length of the quadtree image compression scheme. &nbsp;Only $L \times L$ images consisting of $L^2$ pixels are considered. &nbsp;An image pixel is either a $0$-pixel or a $1$-pixel.</p>

<p>The quadtree image compression scheme is as follows:</p>

<ol>
<li>
<p>If the image consists of both $0$-pixels and $1$-pixels, encode a $1$ to indicate that the image will be partitioned into $4$ sub-images as described in Step (2). &nbsp;Otherwise, encode the entire image as $00$ or $01$ to indicate that the image consists of only $0$-pixels or only $1$-pixels respectively.</p>
</li>
<li>
<p>An image $I$ is partitioned into $4$ equal size sub-images $A$, $B$, $C$, $D$ as shown:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/2c6174bb-d644-4a3d-ad87-a127569dd757/-/preview/" style="width: 260px; height: 100px;"></p>

<p>Step (1) is then performed on each of the four sub-images in the order of $A$, $B$, $C$, $D$.</p>
</li>
</ol>

<p>Let $(I)$ be the encoding of the image $I$. &nbsp;The following examples show the encoding process to compress an image.</p>

<p>Example 1. &nbsp;This example shows the encoding process of a $4 \times&nbsp;4$ image.</p>

<p>$$\begin{align*} \begin{bmatrix} 1&amp;1&amp;1&amp;1\\1&amp;1&amp;0&amp;1 \\ 0&amp;1&amp;0&amp;0 \\ 0&amp;0&amp;1&amp;1\end{bmatrix} &amp; = 1 \begin{bmatrix}0&amp;1\\0&amp;0\end{bmatrix} \begin{bmatrix}1&amp;1\\1&amp;1\end{bmatrix} \begin{bmatrix}0&amp;0\\1&amp;1\end{bmatrix} \begin{bmatrix}1&amp;1\\0&amp;1\end{bmatrix} \\ &amp; = 1 \, 1\begin{bmatrix}0\end{bmatrix}\begin{bmatrix}0\end{bmatrix}\begin{bmatrix}0\end{bmatrix}\begin{bmatrix}1\end{bmatrix} \, 01 \, 1\begin{bmatrix}1\end{bmatrix}\begin{bmatrix}0\end{bmatrix}\begin{bmatrix}1\end{bmatrix}\begin{bmatrix}0\end{bmatrix} \,1\begin{bmatrix}0\end{bmatrix}\begin{bmatrix}1\end{bmatrix}\begin{bmatrix}1\end{bmatrix}\begin{bmatrix}1\end{bmatrix} \\ &amp; = 1\,1\,00\,00\,00\,01\,01\,1\,01\,00\,01\,00\,1\,00\,01\,01\,01\end{align*}$$</p>

<p>Since there are $30$ bits ($0$’s and $1$’s) in the encoding, the length of the compressed image is $30$.</p>

<p>Example 2. &nbsp;This example shows the encoding process of an $8 \times 8$ image.</p>

<p>$$\begin{align*} \begin{bmatrix} 0&amp;0&amp;0&amp;0&amp;1&amp;1&amp;1&amp;1\\0&amp;0&amp;0&amp;0&amp;1&amp;1&amp;1&amp;1\\0&amp;0&amp;0&amp;0&amp;1&amp;1&amp;1&amp;1\\0&amp;0&amp;0&amp;0&amp;1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1&amp;1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1&amp;1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1&amp;1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1&amp;1&amp;1&amp;1&amp;1\end{bmatrix} &amp; = 1 \begin{bmatrix}1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1\end{bmatrix} \begin{bmatrix}0&amp;0&amp;0&amp;0\\0&amp;0&amp;0&amp;0\\0&amp;0&amp;0&amp;0\\0&amp;0&amp;0&amp;0\end{bmatrix} \begin{bmatrix}1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1\end{bmatrix} \begin{bmatrix}1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1\\1&amp;1&amp;1&amp;1\end{bmatrix} \\ &amp; = 1\,01\,00\,01\,01\end{align*}$$</p>

<p>Thus the length of the compressed image is $9$ (bits).</p>

<ol>
<li>Read an $L \times L$ image ($1 \le L \le 64$ and $L$ is a power of $2$) from the input.</li>
<li>Compute the length (the number of bits) of the compressed image encoded by the quadtree compression scheme.</li>
<li>Write the length to the output.</li>
</ol>



## 입력


<p>For an $L \times L$ square image, the input file contains $L + 1$ lines. &nbsp;The first line consists of the single integer $L$. &nbsp;Each line of the subsequent $L$ lines consists of $L$ bits (a bit is either a $0$ or a $1$) with a blank between two adjacent bits.</p>



## 출력


<p>The output file consists of one integer which is the length (the number of bits) in the compressed image.</p>



## 소스코드

[소스코드 보기](Image.cpp)