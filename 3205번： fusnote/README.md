# 3205번: fusnote - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/3205)


<p>A text in a book consists of a sequence of lines. A line may contain references to footnotes. A footnote consists of one or more lines and it have to be printed together with its reference on the same page. Once a footnote is printed on a page, only another footnote may follow it on that page. A maximal number of lines that can be printed on one page is known. No page of a book may contain more than that number of lines, including footnotes.</p>

<p>Write a program that will compute the minimal number of pages a book can have.</p>



## 입력


<p>The first line of input contains two integers: N, a number of lines in a document (2 ≤ N ≤ 1000), and K, maximal number of lines a page of a book may contain (2 ≤ K ≤ 1000), separated by a space character.</p>

<p>The second line of input contains an integer F, 1 ≤ F ≤ 100, a number of footnotes in a book.</p>

<p>Each of the next F lines consists of two numbers, X and Y, separated by a space character, meaning that X-th line of the text has a reference to a footnote consisting of Y lines. Those footnotes descriptions will be sorted with respect to the lines where they are being referenced.</p>

<p>Note: Input data will be chosen so that a solution always exists.</p>



## 출력


<p>The first and only line of output should contain the minimal number of pages a book can have.</p>



## 소스코드

[소스코드 보기](Main.java)