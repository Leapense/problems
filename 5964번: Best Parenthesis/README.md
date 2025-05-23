# 5964번: Best Parenthesis - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/5964)


<p>Recently, the cows have been competing with strings of balanced parentheses and comparing them with each other to see who has the best one.</p>

<p>Such strings are scored as follows (all strings are balanced): the string "()" has score 1; if "A" has score s(A) then "(A)" has score 2*s(A); and if "A" and "B" have scores s(A) and s(B), respectively, then "AB" has score s(A)+s(B). For example, s("(())()") = s("(())")+s("()") = 2*s("()")+1 = 2*1+1 = 3.</p>

<p>Bessie wants to beat all of her fellow cows, so she needs to calculate the score of some strings. Given a string of balanced parentheses of length N (2 &lt;= N &lt;= 100,000), help Bessie compute its score.</p>



## 입력


<ul>
<li>Line 1: A single integer: N</li>
<li>Lines 2..N + 1: Line i+1 will contain 1 integer: 0 if the ith character of the string is '(', &nbsp;and 1 if the ith character of the string is ')'</li>
</ul>



## 출력


<ul>
<li>Line 1: The score of the string. Since this number can get quite large, output the &nbsp;score modulo 12345678910.</li>
</ul>



## 소스코드

[소스코드 보기](Main.java)