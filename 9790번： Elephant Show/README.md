# 9790번: Elephant Show - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9790)


<p>There are a lot of elephants in Chiang Mai and many elephant camps can be seen around this city. Elephant camps are among the most popular attractions in Chiang Mai, but Khun-LungKen Elephant Farm is very different from the others.</p>

<p>At Khun-Lung-Ken Elephant Farm you can enjoy shows performed by elephants such as dancing, playing football and painting. But the most interesting show is when an elephant eats apples on the ground at high speed. This show is held on a rectangular ground, which is covered with big square tiles. Each tile is colored in either red or yellow, and each tile has an apple placed on it. At first an elephant stands on a yellow tile. From this tile, he can move to one of four adjacent tiles. However, he can only move horizontally or vertically. Unbelievably, he will not move on red tiles, he will only move on yellow tiles in order to get an apple, and will never pick up an apple placed on a red tile.</p>

<p>Write a program to count the number of apples which the elephant can eat by repeating the moves described above.</p>



## 입력


<p>The input consists of multiple data sets. A data set starts with a line containing two positive integers W and H; W and H are the numbers of tiles in the x- and y- directions, respectively. W and H are not more than 40.</p>

<p>There are H lines in the data set, each of which includes W characters. Each character represents the color of a tile as follows.</p>

<ul>
<li><code>'.'</code> → a yellow tile</li>
<li><code>'#'</code> → a red tile</li>
<li><code>'A'</code> → an elephant on a yellow tile (appears once in the data set)</li>
</ul>

<p>The end of the input is indicated when both W and H are Zero.</p>



## 출력


<p>For each data set, your program should output a line which contains the number of tiles the elephant can reach from the initial tile (including this tile).</p>



## 소스코드

[소스코드 보기](Elephant%20Show.cpp)