# 19658번: Labels - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/19658)


<p>Today is the first day of work for Charles the Courier. He has been tasked with delivering N packages where each package has a (not necessarily unique) label number between 1 and N inclusive. At the end of each day, he is required to report a sequence A of N integers A<sub>1</sub>, . . . , A<sub>N</sub> where A<sub>i</sub> is the label number of the i<sup>th</sup> delivered package.</p>

<p>A mathematician at heart, Charles decides to use delta encoding to save on memory space and records a sequence D of N − 1 integers D<sub>1</sub>, . . . , D<sub>N−1</sub> instead, where D<sub>i</sub> = A<sub>i+1</sub> − A<sub>i</sub>.</p>

<p>After delivering all the packages, Charles realises that he does not know how to recover A from D. Your task today is to help him, or state that it is not possible to uniquely recover A.</p>



## 입력


<p>Your program must read from standard input.</p>

<p>The first line contains a single integer N, the total number of packages.</p>

<p>The second line contains N − 1 space-separated integers, D<sub>1</sub>, . . . , D<sub>N−1</sub>. D<sub>i</sub> represents the difference between the label numbers of the (i + 1)<sup>th</sup> and i<sup>th</sup> delivered package.</p>



## 출력


<p>Your program must print to standard output.</p>

<p>If it is possible to uniquely recover A from D, your output should contain N space-separated integers, the sequence A.</p>

<p>Otherwise, your output should contain a single integer on a single line, the integer -1.</p>



## 소스코드

[소스코드 보기](Labels.cpp)