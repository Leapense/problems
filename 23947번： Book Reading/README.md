# 23947번: Book Reading - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23947)


<p>Supervin is a librarian handling an ancient book with&nbsp;<b>N</b>&nbsp;pages, numbered from 1 to&nbsp;<b>N</b>. Since the book is too old, unfortunately&nbsp;<b>M</b>&nbsp;pages are torn out: page number&nbsp;<b>P<sub>1</sub></b>,&nbsp;<b>P<sub>2</sub></b>, ...,&nbsp;<b>P<sub>M</sub></b>.</p>

<p>Today, there are&nbsp;<b>Q</b>&nbsp;lazy readers who are interested in reading the ancient book. Since they are lazy, each reader will not necessarily read all the pages. Instead, the i-th reader will only read the pages that are numbered multiples of&nbsp;<b>R<sub>i</sub></b>&nbsp;and not torn out. Supervin would like to know the sum of the number of pages read by each reader.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<b>T</b>.&nbsp;<b>T</b>&nbsp;test cases follow. Each test case begins with a line containing the three integers&nbsp;<b>N</b>,&nbsp;<b>M</b>, and&nbsp;<b>Q</b>, the number of pages in the book, the number of torn out pages in the book, and the number of readers, respectively. The second line contains&nbsp;<b>M</b>&nbsp;integers, the i-th of which is&nbsp;<b>P<sub>i</sub></b>. The third line contains&nbsp;<b>Q</b>&nbsp;integers, the i-th of which is&nbsp;<b>R<sub>i</sub></b>.</p>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is the total number of pages that will be read by all readers.</p>



## 소스코드

[소스코드 보기](Book%20Reading.py)