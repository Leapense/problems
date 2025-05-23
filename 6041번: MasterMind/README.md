# 6041번: MasterMind - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6041)


<p>Jessie was learning about programming contests at Bessie's knee. "Do they play games?" she asked.</p>

<p>"Oh yes," Bessie nodded sagely. "Here's a classic."</p>

<p>MasterMind is a classic two player game. One of the players is the 'codemaker'; she picks a four digit secret number S (1000 &lt;= S &lt;= 9999). The other player is the 'codebreaker' who repeatedly guesses four digit numbers until she solves the code.</p>

<p>The codemaker provides feedback that comprises two integers for each codebreaker guess G_i (1000 &lt;= G_i &lt;= 9999). For each codebreaker guess, the codemaker's feedback comprises two integers:</p>

<p>The first integer C_i (0 &lt;= C_i &lt;= 4) specifies how many of the guess's digits are correct and in their correct location in the secret number</p>

<p>The second integer W_i (0 &lt;= W_i &lt;= 4-C_i) specifies how many of the remaining digits (i.e., those not described by C_i) are correct but in the wrong location.</p>

<p>For example, suppose codemaker's secret number is 2351. If codebreaker guesses 1350, the codemaker provides the feedback "2 1", since 3 and 5 are in correct locations in the number, and 1 is in the wrong location. As another example, if the secret number is 11223 (in a five-digit version of mastermind) and the guess is 12322, then the feedback would be "2 2".</p>

<p>Below is a sample game where the secret number is 2351:</p>

<pre>        Correct digits in correct location
        | Correct digits in wrong location
Guess   | |
3157    1 2
1350    2 1
6120    0 2
2381    3 0
2351    4 0</pre>

<p>For this task, you are given N (1 &lt;= N &lt;= 100) guesses with their feedback in the middle of a game. You are asked to output the smallest four digit number which can be a candidate for codemaker's secret code (i.e., which satisfies all the constraints).</p>

<p>If there are no such numbers, output "NONE" (without the quotes).</p>



## 입력


<ul>
<li>Line 1: A single integer: N</li>
<li>Lines 2..N+1: Line i+1 contains guess i and its two responses expressed as three space-separated integers: G_i, C_i, and W_i</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: A single integer that is the smallest four-digit number (same range as the secret integer: 1000..9999) which could be the secret code. If there are no such numbers, output a single line containing the word "NONE" (without quotes).</li>
</ul>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Main.java)