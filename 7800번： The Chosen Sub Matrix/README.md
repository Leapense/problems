# 7800번: The Chosen Sub Matrix - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7800)


<p>From a given N x N matrix, you should find an M x M sub matrix which has the least distinct element in it. If there are more than one sub matrixes which have the same number of distinct elements then compare each element in descending order and choose one that has the first highest element. If all of distinct elements of all sub matrixes are the same, chose one with the least row index, and then the least column index. The matrix index starts at 1.</p>

<p>For example, given a 4x4 matrix:</p>

<table class="table table-bordered" style="width:10%">
<tbody>
<tr>
<td>3</td>
<td>9</td>
<td>9</td>
<td>9</td>
</tr>
<tr>
<td>3</td>
<td>9</td>
<td>9</td>
<td>2</td>
</tr>
<tr>
<td>3</td>
<td>9</td>
<td>9</td>
<td>2</td>
</tr>
<tr>
<td>2</td>
<td>5</td>
<td>5</td>
<td>2</td>
</tr>
</tbody>
</table>

<p>Then, the possible sub matrixes of 3x3 are:</p>

<table class="table table-bordered" style="width:45%">
<tbody>
<tr>
<td style="width:3%">3</td>
<td style="width:3%">9</td>
<td style="width:3%">9</td>
<td rowspan="4" style="width:3%">&nbsp;</td>
<td style="width:3%">9</td>
<td style="width:3%">9</td>
<td style="width:3%">9</td>
<td rowspan="4" style="width:3%">&nbsp;</td>
<td style="width:3%">3</td>
<td style="width:3%">9</td>
<td style="width:3%">9</td>
<td rowspan="4" style="width:3%">&nbsp;</td>
<td style="width:3%">9</td>
<td style="width:3%">9</td>
<td style="width:3%">2</td>
</tr>
<tr>
<td>3</td>
<td>9</td>
<td>9</td>
<td>9</td>
<td>9</td>
<td>2</td>
<td>3</td>
<td>9</td>
<td>9</td>
<td>9</td>
<td>9</td>
<td>2</td>
</tr>
<tr>
<td>3</td>
<td>9</td>
<td>9</td>
<td>9</td>
<td>9</td>
<td>2</td>
<td>2</td>
<td>5</td>
<td>5</td>
<td>5</td>
<td>5</td>
<td>2</td>
</tr>
<tr>
<th colspan="3">S<sub>1</sub></th>
<th colspan="3">S<sub>2</sub></th>
<th colspan="3">S<sub>3</sub></th>
<th colspan="3">S<sub>4</sub></th>
</tr>
</tbody>
</table>

<p>Sub matrix S1 has 2 distinct elements: 9 and 3;</p>

<p>Sub matrix S2 has 2 distinct elements: 9 and 2;</p>

<p>Sub matrix S3 has 4 distinct elements: 9, 5, 3, and 2;</p>

<p>Sub matrix S4 has 3 distinct elements: 9, 5, and 2.</p>

<p>Sub matrixes are ranked using the rules above and give result as S1, S2, S4, and then S3.</p>

<p>Which means the chosen sub matrix is S1.</p>



## 입력


<p>The first line of each case contains two integers, N (1&lt;=N&lt;=10) the size of matrix, and M (1&lt;=M&lt;=N) the size of sub matrix to be chosen. In the next N lines, each contains N integers (each separated by a space) that represent the matrix. Each element in the matrix should be between 0 and 9 inclusively.</p>

<p>&nbsp;</p>



## 출력


<p>For each case you should output in a single line, the top-left index (row and column, separated by a single space) of the chosen sub matrix.</p>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](The%20Chosen%20Sub%20Matrix.cpp)