# 23980번: Common Anagrams - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23980)


<p>Ayla has two strings&nbsp;<b>A</b>&nbsp;and&nbsp;<b>B</b>, each of length&nbsp;<b>L</b>, and each of which is made of uppercase English alphabet letters. She would like to know how many different substrings of&nbsp;<b>A</b>&nbsp;appear as anagrammatic substrings of&nbsp;<b>B</b>. More formally, she wants the number of different ordered tuples (i, j), with 0 ≤ i ≤ j &lt;&nbsp;<b>L</b>, such that the i-th through j-th characters of&nbsp;<b>A</b>&nbsp;(inclusive) are the same multiset of characters as at least one contiguous substring of length (j - i + 1) in&nbsp;<b>B</b>.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<b>T</b>.&nbsp;<b>T</b>&nbsp;test cases follow. Each test case starts with one line, containing&nbsp;<b>L</b>: the length of the string. The next two lines contain one string of&nbsp;<b>L</b>&nbsp;characters each: these are strings&nbsp;<b>A</b>&nbsp;and&nbsp;<b>B</b>, in that order.</p>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is the answer Ayla wants, as described above.</p>



## 소스코드

[소스코드 보기](Common%20Anagrams.py)