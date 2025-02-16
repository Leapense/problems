# 2189번: Magickology - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/2189)


<p>Matheos the magician wishes to organise her considerable collection of squares into categories based on the amount of magical power that each one possesses. A square is a table of numbers with an equal number of rows and columns and each square has an associated sum (S), the sum of the first column. Matheos wishes to categorise them based on the following properties:</p>

<p>Not Magick : At least one row or column does not sum to S.<br>
Semi-Magick Square : Each row and column sums to S but at least one of the diagonals doesn’t.<br>
Weakly-Magick Square : All the rows, columns and diagonals sum to S.<br>
Strongly-Magick Square : All the rows, columns and diagonals sum to S, and the numbers are distinct (i.e. no number is duplicated).<br>
Magically-Magick Square : All the rows, columns and diagonals sum to S, the numbers are distinct and they are consecutive (i.e. they form a sequence with no gaps).</p>

<p>Thus</p>

<table border="1" cellpadding="1" cellspacing="1" style="width:50px">
<tbody>
<tr>
<td>2</td>
<td>3</td>
</tr>
<tr>
<td>3</td>
<td>2</td>
</tr>
</tbody>
</table>

<p>is a Semi-Magick square because each row and column adds up to 5, but the diagonals don’t.</p>

<p>and</p>

<table border="1" cellpadding="1" cellspacing="1" style="width:70px">
<tbody>
<tr>
<td>8</td>
<td>1</td>
<td>6</td>
</tr>
<tr>
<td>3</td>
<td>5</td>
<td>7</td>
</tr>
<tr>
<td>4</td>
<td>9</td>
<td>2</td>
</tr>
</tbody>
</table>

<p>is a Magically-Magick square because each row, column and diagonal adds up to 15, each number is distinct, and the numbers are consecutive (i.e. 1 2 3 4 5 6 7 8 9).</p>

<p>Your task is to help Matheos by writing a program to read and evaluate a sequence of squares. For each square your program is to output a message to say whether it is Magically-Magick, Strongly-Magick, Weakly-Magick, Semi-Magick, or has no magical properties at all.</p>

<p>&nbsp;</p>



## 입력


<p>Input will consist of a sequence of squares. Each square starts with an integer, n, specifying the square’s size (number of rows and columns; 2 ≤ n ≤ 8) on a line by itself, followed by n lines, each with n integers. The sequence of squares is terminated by a line containing a zero (0).</p>



## 출력


<p>Output for each square is a single line starting with the word ‘Square’ followed by a space, a sequence number (starting at 1) and a colon (:). This is then followed by another space and then one of following massages ‘Magically-Magick Square’, ‘Strongly-Magick Square’, ‘Weakly-Magick Square’, ‘Semi-Magick Square’, or ‘Not a Magick Square’ as appropriate.</p>



## 소스코드

[소스코드 보기](Main.java)