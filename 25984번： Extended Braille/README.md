# 25984번: Extended Braille - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25984)


<p>The Blind Association for Pretty Calligraphy is annoyed by the lack of emoticons and math symbols in the braille alphabet. Given that the braille alphabet is supported by the Unicode format, it only makes sense to make all Unicode characters supported in braille.</p>

<p>The goal is to extend the braille alphabet to include all Unicode characters. Of course, this will not fit in the standard $2 \times 3$ format, so using a bigger box is allowed. Important is that no two braille characters are the same up to translation, i.e., have the same shape. See Figure \ref{fig:braille} for an example. You let a designer make up a large braille alphabet, and your job is to check how many unique shapes there are among the characters.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/7521df4a-84a4-46cc-a7db-53fbe159959d/-/preview/" style="width: 223px; height: 150px;"></p>

<p style="text-align: center;">Figure E.1: Illustration of Sample Input 1: two characters with the same shape.</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with an integer $n$ ($1\leq n\leq 10^5$), the number of braille characters.</li>
<li>Then for each of the $n$ braille characters:
<ul>
<li>One line with an integer $m$ ($1 \leq m \leq 1000$), the number of dots.</li>
<li>$m$ lines, each with two integers $x$ and $y$ ($\left| x \right|, \left| y \right| \leq 1000$), the coordinates of the dots.</li>
</ul>
</li>
<li>The total number of dots is at most $10^6$.</li>
</ul>



## 출력


<p>Output the number of distinct braille characters up to translation.</p>



## 소스코드

[소스코드 보기](Extended%20Braille.cpp)