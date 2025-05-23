# 23921번: Kick_Start - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23921)


<p>Ksenia is very fond of reading so she kicks off each day by reading a fragment from her favourite book before starting with the rest of her morning routine. A fragment is simply a&nbsp;<a href="https://en.wikipedia.org/wiki/Substring">substring</a>&nbsp;of the text. Ksenia is somewhat superstitious and believes that her day will be lucky if the fragment she reads starts with the string KICK, then goes on with 0 or more characters, and eventually ends with the string START, even if the overall fragment makes little sense.</p>

<p>Given the text of the book, count the number of different lucky fragments that Ksenia can read before the book gets old and she needs to buy another one. Two fragments are considered to be different if they start or end at different positions in the text, even if the fragments read the same. Also note that different lucky fragments may overlap.</p>



## 입력


<p>The first line of the input gives the number of test cases&nbsp;<b>T</b>.&nbsp;<b>T</b>&nbsp;lines follow, each containing a single string&nbsp;<b>S</b>&nbsp;consisting of upper case English letters only.'</p>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is the number of different lucky fragments in the text of this test case.</p>



## 소스코드

[소스코드 보기](Kick_Start.py)