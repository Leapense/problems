# 4632번: Flow Layout - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4632)


<p>A flow layout manager takes rectangular objects and places them in a rectangular window from left to right. If there isn't enough room in one row for an object, it is placed completely below all the objects in the first row at the left edge, where the order continues from left to right again. Given a set of rectangular dimensions and a maximum window width, you are to write a program that computes the dimensions of the final window after all the rectangles have been placed in it.</p>

<p>For example, given a window that can be at most 35 units wide, and three rectangles with dimensions 10 x 5, &nbsp;20 x 12, and 8 x 13, the flow layout manager would create a window that looked like the figures below after each rectangle was added.</p>

<table class="table">
<tbody>
<tr>
<td><img alt="insert 10x5 rectangle" src="https://www.acmicpc.net/upload/images2/fig1a.gif"></td>
<td><img alt="insert 20x12 rectangle" src="https://www.acmicpc.net/upload/images2/fig1b.gif"></td>
<td><img alt="insert 8x13 rectangle" src="https://www.acmicpc.net/upload/images2/fig1c.gif"></td>
</tr>
</tbody>
</table>

<p>The final dimensions of the resulting window are 30 x 25, since the width of the first row is 10+20 = 30 and the combined height of the first and second rows is 12+13 = 25.</p>



## 입력


<p>The input consists of one or more sets of data, followed by a final line containing only the value 0. Each data set starts with a line containing an integer, m, 1 ≤ m ≤ 80, which is the maximum width of the resulting window. This is followed by at least one and at most 15 lines, each containing the dimensions of one rectangle, width first, then height. The end of the list of rectangles is signaled by the pair -1 -1, which is not counted as the dimensions of an actual rectangle. Each rectangle is between 1 and 80 units wide (inclusive) and between 1 and 100 units high (inclusive).</p>



## 출력


<p>For each input set print the width of the resulting window, followed by a space, then the lowercase letter "x", followed by a space, then the height of the resulting window.</p>



## 소스코드

[소스코드 보기](Flow%20Layout.cpp)