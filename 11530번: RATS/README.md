# 11530번: RATS - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11530)


<p>The RATS (Reverse Add Then Sort) function takes as input a decimal integer (usually with digits in increasing order) and returns a decimal integer with digits in increasing order</p>

<p>To compute the value:</p>

<ol>
<li>Reverse the digits of the input value.</li>
<li>Add the reversed value to the input value.</li>
<li>Sort the digits of the sum into increasing order (dropping any leading zeroes).</li>
</ol>

<pre>RATS(12334444): 12334444 + 44443321 = 56777765 -&gt; 55667777
RATS(44556): 44556 + 65544 = 110100 -&gt; 111</pre>

<p>This problem deals with sequences where the first value is arbitrary and each succeeding value is the RATS of the previous value. For example:</p>

<pre>12334444, 55667777, 123334444, 556667777, 1233334444, 5566667777, …
123, 444, 888, 1677, 3489, 12333, 44556, 111, 222, 444, 888, …</pre>

<p>The first sequence is the creeper. It provably goes to infinity in this regular pattern. The second sequence enters a cycle which first repeats a value at the tenth term of the sequence. It is conjectured that every RATS sequence either eventually enters the creeper and goes to infinity or cycles as in the second sequence.</p>

<p>Write a program which computes the first M terms of a RATS sequence given the starting value. Your program should also detect if the sequence repeats a value in the first M terms or enters the creeper in the first M terms.</p>



## 입력


<p>The first line of input contains a single decimal integer P, (1 ≤ P ≤ 10000), which is the number of data sets that follow. Each data set should be processed identically and independently.</p>

<p>Each data set consists of a single line of input. It contains the data set number, K, followed by a single space, followed by the number of terms to compute (including the initial value), M, (1 ≤ M ≤ 60), a single space, followed by the initial value for the RATS sequence, a decimal integer with digits in increasing order. The decimal integer will have at most 40 digits although intermediate terms may have more.</p>



## 출력


<p>For each data set there is one line of output.</p>

<p>If the sequence enters the creeper (has a term of the form 1233+444 or 5566+7777) in the first M terms, the output is the data set number, a space, the upper case letter C, a space and the index of the first term to enter the creeper.</p>

<p>If the sequence repeats a value in the first M terms, the output is the data set number, a space, the upper case letter R, a space and the index of the first repeated term.</p>

<p>Otherwise, the output is the data set number, a space, and the Mth term of the sequence.</p>

<p>In the first two cases the index of the initial term is 1.</p>



## 소스코드

[소스코드 보기](RATS.cpp)