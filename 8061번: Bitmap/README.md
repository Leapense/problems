# 8061번: Bitmap - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8061)


<p>There is given a rectangular bitmap of size n x m. Each pixel of the bitmap is either white or black, but at least one is white. The pixel in i-th line and j-th column is called the pixel (i,j). The distance between two pixels p1=(i<sub>1</sub>,j<sub>1</sub>) and p2=(i<sub>2</sub>,j<sub>2</sub>) is defined as:</p>

<p>d(p<sub>1</sub>,p<sub>2</sub>)=|i<sub>1</sub>-i<sub>2</sub>|+|j<sub>1</sub>-j<sub>2</sub>|.</p>

<p>Write a program which:</p>

<ul>
<li>reads the description of the bitmap from standard input,</li>
<li>for each pixel, computes the distance to the nearest white pixel,</li>
<li>writes the results to the standard output.</li>
</ul>



## 입력


<p>First line of the standard input there is a pair of integer numbers n, m separated by a single space, 1 ≤ n ≤ 182, 1 ≤ m ≤ 182. In each of the following n lines of the input exactly one zero-one word of length m, the description of one line of the bitmap, is written. On the j-th position in the line (i+1), 1 ≤ i ≤ n, 1 ≤ j ≤ m, is 1 if, and only if the pixel (i,j) is white.</p>



## 출력


<p>In the i-th line of the standard output, 1 ≤ i ≤ n, there should be written m integers f(i,1),…,f(i,m) separated by single spaces, where f(i,j) is the distance from the pixel (i,j) to the nearest white pixel.</p>



## 소스코드

[소스코드 보기](Bitmap.cpp)