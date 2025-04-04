# 12638번: All Your Base (Large) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12638)


<p>In A.D. 2100, aliens came to Earth. They wrote a message in a cryptic language, and next to it they wrote a series of symbols. We've come to the conclusion that the symbols indicate a number: the number of seconds before war begins!</p>

<p>Unfortunately we have no idea what each symbol means. We've decided that each symbol indicates one digit, but we aren't sure what each digit means or what base the aliens are using. For example, if they wrote "ab2ac999", they could have meant "31536000" in base 10 -- exactly one year -- or they could have meant "12314555" in base 6 -- 398951 seconds, or about four and a half days. We are sure of three things: the number is positive; like us, the aliens will never start a number with a zero; and they aren't using unary (base 1).</p>

<p>Your job is to determine the minimum possible number of seconds before war begins.</p>



## 입력


<p>The first line of input contains a single integer,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow. Each test case is a string on a line by itself. The line will contain only characters in the 'a' to 'z' and '0' to '9' ranges (with no spaces and no punctuation), representing the message the aliens left us. The test cases are independent, and can be in different bases with the symbols meaning different things.</p>

<p>Limits</p>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100</li>
<li>The answer will never exceed 10<sup>18</sup></li>
<li>1 ≤ the length of each line &lt; 61</li>
</ul>



## 출력


<p>For each test case, output a line in the following format:&nbsp;</p>

<pre>Case #<strong>X</strong>: <strong>V</strong></pre>

<p>Where&nbsp;<strong>X</strong>&nbsp;is the case number (starting from 1) and&nbsp;<strong>V</strong>&nbsp;is the minimum number of seconds before war begins.</p>



## 소스코드

[소스코드 보기](All%20Your%20Base%20(Large).cpp)