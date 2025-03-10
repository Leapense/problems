# 9909번: Cellular - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9909)


<p>A square field is divided up into n × n cells. &nbsp;Each cell can only take one of two states: 0 or 1. &nbsp;At regular intervals, called generations, all cells update their state simultaneously, depending on the state that they and their neighbors had in the previous generation.</p>

<p>An interior cell has four neighbors, namely the cells above it and below it, and the cells to its right and to its left. &nbsp;Corner cells have only two neighbors. &nbsp;Other cells at the edge of the field have three neighbors.</p>

<p>One possible rule to update a cell is to look at the sum of the states that it and its neighbors had in the previous generation. &nbsp;This sum has a value in the range 0 through 5. &nbsp;In this case, the update rule for the cells can be encoded in 6 bits. &nbsp;For example, an update rule 0 0 1 0 0 1 means that the new state of each cell is</p>

<ul>
<li>0 if the sum was 5,</li>
<li>0 if the sum was 4,</li>
<li>1 if the sum was 3,</li>
<li>0 if the sum was 2,</li>
<li>0 if the sum was 1, and</li>
<li>1 if the sum was 0,</li>
</ul>

<p>where “the sum” means the sum of the old states of the cell and of all its neighbors. &nbsp;We can use binary code to uniquely identify the rule. &nbsp;A 6-bit binary number a b c d e f corresponds to the decimal value (a × 32) + (b × 16) + (c × 8) + (d × 4) + (e × 2) + f. &nbsp;The above rule would have the binary number 001001, which corresponds to the decimal value 9.</p>

<p>For example, if n is 4 we could have the starting state</p>

<pre>1111
1111
1111
1111</pre>

<p>With rule 9, we get after 1 generation the states</p>

<pre>1001
0000
0000
1001</pre>

<p>and after 2 generations</p>

<pre>0000
0110
0110
0000
</pre>

<p>Given a size n, a number of generations g, a starting state s and an ending state e, the goal is to find the rule with smallest decimal value that generates the ending state e from a starting state s after exactly g generations. &nbsp;The output required is the decimal value of the rule. &nbsp;If there is no such rule, the output should be –1.</p>

<p>You can assume that n is not bigger than 30 and g is not bigger than 50.</p>



## 입력


<p>The input consists of the following lines:</p>

<ol>
<li>The first line contains two positive integers indicating the size n and number of generations g.</li>
<li>Each of the next n lines contains n digits which are 0 or 1. &nbsp;These n lines indicate the starting state s.</li>
<li>The next line is empty.</li>
<li>Each of the following n lines contains n digits which are 0 or 1. &nbsp;These n lines indicate the ending state e.</li>
</ol>



## 출력


<p>The output contains a single integer value, which is the smallest decimal value of a rule that generates e from s after exactly g generations.</p>



## 소스코드

[소스코드 보기](Cellular.cpp)