# 13242번: Harps and Tails - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13242)


<p>Gary likes the Celtic Harp that appears in the 1 euro coins.</p>

<p>He has a grid of n rows and m columns of such coins. Each coin has either the harp or the tail facing up.</p>

<p>Gary also loves order, he wants as many rows as possible with all the coins showing the Celtic Harp. To make things interesting he can only do the following operation: choose any column and turn all the coins in this column. That is, any coin showing the Harp will change to tails and any coin showing tails will turn to the Harp.</p>

<p>Gary can perform this operation as many times as he wants to maximize the number of rows with all Harps. Can you help him?</p>

<p>Example: We have the following grid of coins. Coins with tails are represented with the character T and coins with the Harp are represented by H.</p>

<pre>T H T H
H T T T
H H H H
T H T H</pre>

<p>In this state, only one row show all Harps. If we change the first column we obtain:</p>

<pre>H H T H
T T T T
T H H H
H H T H</pre>

<p>Then we change the third row to obtain:</p>

<pre>H H H H
T T H T
T H T H
H H H H
</pre>

<p>In this state the first and fourth rows are all Harps which is the best we can get. Hence our answer will be 2.</p>



## 입력


<p>The first line of input contains 2 integers n and m (1 ≤ n, m ≤ 1000) representing the number of rows and columns of the grid.&nbsp;</p>

<p>The next n lines will describe the state of the grid. The i-th line will contain a string with n characters denoting the state of the i-th row of the grid. The j-th character on this line is 'T' if the j-th square in the i-th row contains a tail, and 'H' if contains a Harp.</p>



## 출력


<p>The output should be a single line containing an integer equal to a maximum possible number of rows that are completely converted to Harps (‘H’).</p>



## 소스코드

[소스코드 보기](Harps%20and%20Tails.cpp)