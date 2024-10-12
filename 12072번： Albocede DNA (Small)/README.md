# 12072번: Albocede DNA (Small) - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12072)


<p>The DNA of the Albocede alien species is made up of 4 types of nucleotides:&nbsp;<code>a</code>,&nbsp;<code>b</code>,&nbsp;<code>c</code>, and&nbsp;<code>d</code>. Different Albocedes may have different sequences of these nucleotides, but any Albocede's DNA sequence obeys all of the following rules:</p>

<ul>
<li>It contains at least one copy of each of&nbsp;<code>a</code>,&nbsp;<code>b</code>,&nbsp;<code>c</code>, and&nbsp;<code>d</code>.</li>
<li>All&nbsp;<code>a</code>s come before all&nbsp;<code>b</code>s, which come before all&nbsp;<code>c</code>s, which come before all&nbsp;<code>d</code>s.</li>
<li>There are exactly as many&nbsp;<code>'a'</code>s as&nbsp;<code>'c'</code>s.</li>
<li>There are exactly as many&nbsp;<code>'b'</code>s as&nbsp;<code>'d'</code>s.</li>
</ul>

<p>For example,&nbsp;<code>abcd</code>&nbsp;and&nbsp;<code>aabbbccddd</code>&nbsp;are valid Albocede DNA sequences.&nbsp;<code>acbd</code>,&nbsp;<code>abc</code>, and&nbsp;<code>abbccd</code>&nbsp;are not.</p>

<p>The Albocede-n is an evolved species of Albocede. The DNA sequence of an Albocede-n consists of one or more valid Albocede DNA sequences, concatenated together end-to-end. For example,&nbsp;<code>abcd</code>&nbsp;and&nbsp;<code>aaabcccdaabbbccdddabcd</code>&nbsp;are valid Albocede-n DNA sequences. (Observe that a valid Albocede-n DNA sequence is not necessarily also a valid Albocede DNA sequence.)</p>

<p>From one of your alien expeditions, you retrieved an interesting sequence of DNA made up of only&nbsp;<code>a</code>s,&nbsp;<code>b</code>s,&nbsp;<code>c</code>s, and&nbsp;<code>d</code>s. You are interested in how many of the different&nbsp;<a href="https://en.wikipedia.org/wiki/Subsequence" style="color: rgb(85, 26, 139);" target="_blank">subsequences</a>&nbsp;of that sequence would be valid Albocede-n DNA sequences. (Even if multiple different selections of nucleotides from the sequence produce the same valid subsequence, they still all count as distinct subsequences.) Since the result may be very large, please find it modulo 1000000007 (10<sup>9</sup>&nbsp;+ 7).</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>. Each of the next&nbsp;<strong>T</strong>&nbsp;lines contains a string&nbsp;<strong>S</strong>&nbsp;that consists only of the characters&nbsp;<code>a</code>,&nbsp;<code>b</code>,&nbsp;<code>c</code>, and&nbsp;<code>d</code>.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 20.</li>
<li>1 ≤&nbsp;<strong>length of S</strong>&nbsp;≤ 50.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the output of the x<sup>th</sup>&nbsp;test case.</p>



## 소스코드

[소스코드 보기](Albocede%20DNA%20(Small).cpp)