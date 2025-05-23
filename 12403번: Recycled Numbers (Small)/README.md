# 12403번: Recycled Numbers (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12403)


<p>Do you ever become frustrated with television because you keep seeing the same things, recycled over and over again? Well I personally don't care about television, but I do sometimes feel that way about numbers.</p>

<p>Let's say a pair of distinct positive integers (<em>n</em>,&nbsp;<em>m</em>) is&nbsp;<em>recycled</em>&nbsp;if you can obtain&nbsp;<em>m</em>&nbsp;by moving some digits from the back of&nbsp;<em>n</em>&nbsp;to the front without changing their order. For example, (12345, 34512) is a recycled pair since you can obtain 34512 by moving 345 from the end of 12345 to the front. Note that&nbsp;<em>n</em>&nbsp;and&nbsp;<em>m</em>&nbsp;must have the same number of digits in order to be a recycled pair. Neither&nbsp;<em>n</em>&nbsp;nor&nbsp;<em>m</em>&nbsp;can have leading zeros.</p>

<p>Given integers&nbsp;<strong>A</strong>&nbsp;and&nbsp;<strong>B</strong>&nbsp;with the same number of digits and no leading zeros, how many distinct recycled pairs (<em>n</em>,&nbsp;<em>m</em>) are there with&nbsp;<strong>A</strong>&nbsp;≤&nbsp;<em>n</em>&nbsp;&lt;&nbsp;<em>m</em>&nbsp;≤&nbsp;<strong>B</strong>?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow. Each test case consists of a single line containing the integers&nbsp;<strong>A</strong>&nbsp;and&nbsp;<strong>B</strong>.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 50.</li>
<li><strong>A</strong>&nbsp;and&nbsp;<strong>B</strong>&nbsp;have the same number of digits.</li>
<li>1 ≤&nbsp;<strong>A</strong>&nbsp;≤&nbsp;<strong>B</strong>&nbsp;≤ 1000.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1), and y is the number of recycled pairs (<em>n</em>,&nbsp;<em>m</em>) with&nbsp;<strong>A</strong>&nbsp;≤&nbsp;<em>n</em>&nbsp;&lt;&nbsp;<em>m</em>&nbsp;≤&nbsp;<strong>B</strong>.</p>



## 소스코드

[소스코드 보기](Recycled%20Numbers%20(Small).cpp)