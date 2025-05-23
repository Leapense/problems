# 12121번: Pretty Good Proportion (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12121)


<p>I have a sequence of&nbsp;<strong>N</strong>&nbsp;binary digits. I am looking for a substring with just the right proportion of 0s and 1s, but it may not exist, so I will settle for something that's just pretty good.</p>

<p>Can you find a substring where the fraction of 1s is as close as possible to the given fraction&nbsp;<strong>F</strong>? Output the earliest possible index at which such a substring starts.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;&nbsp;<strong>T</strong>&nbsp;test cases follow. Each one starts with a line containing&nbsp;<strong>N</strong>&nbsp;and&nbsp;<strong>F</strong>.&nbsp;<strong>F</strong>&nbsp;will be a decimal fraction between 0 and 1 inclusive, with exactly 6 digits after the decimal point. The next line contains&nbsp;<strong>N</strong>&nbsp;digits, each being either 0 or 1.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li>0 ≤&nbsp;<strong>F</strong>&nbsp;≤ 1</li>
<li><strong>F</strong>&nbsp;will have exactly 6 digits after the decimal point.</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 1000.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the 0-based index of the start of the substring with the fraction of 1s that is as close as possible to&nbsp;<strong>F</strong>. If there are multiple possible answers, output the smallest correct value.</p>



## 소스코드

[소스코드 보기](Pretty%20Good%20Proportion%20(Small).cpp)