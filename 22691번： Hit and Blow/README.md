# 22691번: Hit and Blow - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/22691)


<p><i>Hit and blow</i>&nbsp;is a popular code-breaking game played by two people, one codemaker and one codebreaker. The objective of this game is that the codebreaker guesses correctly a secret number the codemaker makes in his or her mind.</p>

<p>The game is played as follows. The codemaker first chooses a secret number that consists of four different digits, which may contain a leading zero. Next, the codebreaker makes the first attempt to guess the secret number. The guessed number needs to be legal (i.e. consist of four different digits). The codemaker then tells the numbers of&nbsp;<i>hits</i>&nbsp;and&nbsp;<i>blows</i>&nbsp;to the codebreaker. Hits are the matching digits on their right positions, and blows are those on different positions. For example, if the secret number is 4321 and the guessed is 2401, there is one hit and two blows where 1 is a hit and 2 and 4 are blows. After being told, the codebreaker makes the second attempt, then the codemaker tells the numbers of hits and blows, then the codebreaker makes the third attempt, and so forth. The game ends when the codebreaker gives the correct number.</p>

<p>Your task in this problem is to write a program that determines, given the situation, whether the codebreaker can logically guess the secret number within the next two attempts. Your program will be given the four-digit numbers the codebreaker has guessed, and the responses the codemaker has made to those numbers, and then should make output according to the following rules:</p>

<ul>
<li>if only one secret number is possible, print the secret number;</li>
<li>if more than one secret number is possible, but there are one or more critical numbers, print the&nbsp;<i>smallest</i>&nbsp;one;</li>
<li>otherwise, print “????” (four question symbols).</li>
</ul>

<p>Here, critical numbers mean those such that, after being given the number of hits and blows for them on the next attempt, the codebreaker can determine the secret number uniquely.</p>



## 입력


<p>The input consists of multiple data sets. Each data set is given in the following format:</p>

<pre><i>N</i>
<i>four-digit-number</i><sub>1</sub> <i>n-hits</i><sub>1</sub> <i>n-blows</i><sub>1</sub>
...
<i>four-digit-number<sub>N</sub> n-hits<sub>N</sub> n-blows<sub>N</sub></i>
</pre>

<p><i>N</i>&nbsp;is the number of attempts that has been made.&nbsp;<i>four-digit-number<sub>i</sub></i>&nbsp;is the four-digit number guessed on the&nbsp;<i>i</i>-th attempt, and&nbsp;<i>n-hits<sub>i</sub></i>&nbsp;and&nbsp;<i>n-blows<sub>i</sub></i>&nbsp;are the numbers of hits and blows for that number, respectively. It is guaranteed that there is at least one possible secret number in each data set.</p>

<p>The end of input is indicated by a line that contains a zero. This line should not be processed.</p>



## 출력


<p>For each data set, print a four-digit number or “????” on a line, according to the rules stated above.</p>



## 소스코드

[소스코드 보기](Hit%20and%20Blow.cpp)