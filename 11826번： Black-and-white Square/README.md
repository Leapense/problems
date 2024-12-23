# 11826번: Black-and-white Square - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11826)


<p>Famous painter Quasimir Malevich painted a picture called “Black-and-white square”. The picture looks like a rectangle ﬁlled with black and white cells.&nbsp;</p>

<p>Art historian Erik Stripeson put forward a hypothesis that Quasimir painted the picture in the following way: he took a canvas that was initially white, and drew horizontal and vertical black stripes, one cell wide, from the edge to the edge of the canvas.&nbsp;</p>

<p>Association of Computational Art Studies wants to ﬁnd out whether this hypothesis can be correct. If it can be correct, they also want to know the minimal number of stripes that the painter had to draw in order to paint this picture. Moreover, they need to ﬁnd a way to draw this picture using this number of stripes.&nbsp;</p>



## 입력


<p>The ﬁrst line of the input ﬁle contains two integers h and w (1 ≤ h,w ≤ 50) — the height and the width of the picture.&nbsp;</p>

<p>Each of the next h lines contains w space-separated numbers. Number 0 denotes a white cell, number 1 denotes a black cell.&nbsp;</p>



## 출력


<p>If Stripeson’s hypothesis can’t be correct, output only the number -1.&nbsp;</p>

<p>If the hypothesis can be correct, the ﬁrst line of the output ﬁle should contain number n — the minimal possible number of stripes needed to draw the picture.&nbsp;</p>

<p>The second line should contain n numbers that describe a way to draw the picture using n stripes. A positive number x stands for drawing a vertical black stripe in x-th column (columns are numbered from left to right, starting with 1). A negative number -x stands for drawing a horizontal black stripe in x-th row (rows are numbered from top to bottom, starting with 1).&nbsp;</p>

<p>If there are several ways to draw the picture using n stripes, output any one of these ways.&nbsp;</p>



## 소스코드

[소스코드 보기](Black-and-white%20Square.py)