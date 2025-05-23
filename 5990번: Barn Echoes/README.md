# 5990번: Barn Echoes - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/5990)


<p>The cows enjoy mooing at the barn because their moos echo back, although sometimes not completely. Bessie, ever the excellent secretary, has been recording the exact wording of the moo as it goes out and returns. She is curious as to just how much overlap there is.</p>

<p>Given two lines of input (letters from the set a..z, total length in the range 1..80), each of which has the wording of a moo on it, determine the greatest number of characters of overlap between one string and the other. A string is an overlap between two other strings if it is a prefix of one string and a suffix of the other string.</p>

<p>By way of example, consider two moos:</p>

<pre>     moyooyoxyzooo
     yzoooqyasdfljkamo</pre>

<p>The last part of the first string overlaps 'yzooo' with the first part of the second string. The last part of the second string overlaps 'mo' with the first part of the first string. The largest overlap is 'yzooo' whose length is 5.</p>



## 입력


<ul>
<li>Lines 1..2: Each line has the text of a moo or its echo</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: A single line with a single integer that is the length of the longest overlap between the front of one string and end of the other.</li>
</ul>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Barn%20Echoes.cpp)