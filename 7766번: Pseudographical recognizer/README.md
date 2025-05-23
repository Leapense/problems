# 7766번: Pseudographical recognizer - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7766)


<p>Let us define a pseudographical image to be a rectangular matrix of the characters ’<code>.</code>’, ’<code>-</code>’, ’<code>|</code>’, ’<code>\</code>’, and ’<code>/</code>’.</p>

<p>The character ’<code>.</code>’ denotes empty space on the image. A horizontal line segment is given as a set of ’<code>-</code>’ characters in adjacent cells in the same row of the matrix. A vertical line segment is given as a set of ’<code>|</code>’ characters in adjacent cells in the same column of the matrix. Similarly, a diagonal line segment is given as a set of ’<code>/</code>’ or ’<code>\</code>’ characters in adjacent cells in the same diagonal of the matrix. Of course, a line segment going from Northwest to Southeast has to be given using the ’<code>\</code>’ characters and a line segment going from Southwest to Northeast using the ’<code>/</code>’ characters.</p>

<p>Write a program that, given a pseudographical image, determines if it contains exactly one line segment – horizontal, vertical, or diagonal.&nbsp;</p>



## 입력


<p>The input contains several test cases. The first line contains the number of test cases T (1 ≤ T ≤ 100). Next follow the descriptions of each test case. The first line of the test case description contains two integers N and M (1 ≤ N, M ≤ 10), the number of rows and columns of the matrix, respectively. Each of the following N lines of the description contains exactly M symbols ‘<code>.</code>’, ‘<code>-</code>’, ‘<code>|</code>’, ‘<code>\</code>’, or ‘<code>/</code>’.</p>



## 출력


<p>The output consists of T lines, one line per each test case. This line should contain the word CORRECT if the input image contains exactly one line segment, or the word INCORRECT otherwise.</p>



## 소스코드

[소스코드 보기](Pseudographical%20recognizer.cpp)