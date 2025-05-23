# 30939번: Pahuljice - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30939)


<p>Lana likes to draw specific snowflakes. A snowflake of size $x$ is defined as follows:</p>

<ul>
<li>The center of the snowflake is the character '<code>+</code>'.</li>
<li>Above and below the character '<code>+</code>' there is a sequence of $x$ characters '<code>|</code>'.</li>
<li>To the left and right of the character '<code>+</code>' there is a sequence of $x$ characters '<code>-</code>'.</li>
<li>On the diagonal from the upper left corner to the center and from the center to the lower right corner of the snowflake there is a sequence of $x$ characters '<code>\</code>'.</li>
<li>On the diagonal from the upper right corner to the center and from the center to the lower left corner of the snowflake there is a sequence of $x$ characters '<code>/</code>'.</li>
</ul>

<p>Sometimes Lana connects several snowflakes, but even then the size of each snowflake is determined separately, regardless of whether the snowflakes share some characters.</p>

<table class="table table-bordered td-center td-middle">
<tbody>
<tr>
<td>
<pre>\|/
-+-
/|\</pre>
</td>
<td>
<pre>\.|./..
.\|/...
--+--..
./|\...
/.|.\|/
....-+-
..../|\</pre>
</td>
<td>
<pre>\.|./.
.\|/..
--+---
./|\..
/...\.</pre>
</td>
</tr>
</tbody>
</table>

<p style="text-align: center;">On the left is an example of a snowflake of size $1$.</p>

<p style="text-align: center;">In the middle is an example of connected snowflakes, the left one of size $2$ and the right one of size $1$.</p>

<p style="text-align: center;">On the right is an example of a snowflake of size $1$. It is missing one character '<code>|</code>' to be of size $2$.</p>

<p>Lana is currently drawing snowflakes on a piece of paper of size $n \times m$. However, she got a bit confused and did not draw all the snowflakes completely in accordance with her usual snowflake shapes. Namely, some snowflakes are missing some characters, so their size is equal to the smallest length of the corresponding character sequence from the center in one of the eight directions. Moreover, she drew some characters that are not part of any snowflake.</p>

<p>Can you help Lana determine the size of the largest snowflake in the drawing?</p>



## 입력


<p>The first line contains two integers $n$ and $m$ ($1 ≤ n, m ≤ 50$), the size of the drawing.</p>

<p>In each of the following $n$ lines there are $m$ characters describing the drawing.</p>

<p>The characters that can appear in the drawing are '<code>+</code>', '<code>-</code>', '<code>\</code>', '<code>|</code>', '<code>/</code>' and '<code>.</code>'. The ASCII values of these characters are 43, 45, 92, 124, 47 and 46 respectively.</p>



## 출력


<p>In the first and only line you should output the size of the largest snowflake in the drawing.</p>



## 소스코드

[소스코드 보기](Pahuljice.cpp)