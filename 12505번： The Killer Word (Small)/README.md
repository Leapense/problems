# 12505번: The Killer Word (Small) - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12505)


<p>You are playing Hangman with your friend Sean. And while you have heard that Sean is very good at taking candy from a baby, he is not as good at this game. Can you take advantage of Sean's imperfect strategy, and make him lose as badly as possible?</p>

<pre> +--+
 |    O
 |   / | \       Mystery word: _ a _ a _ a _
 |    /  \
 |
+-+---+
</pre>

<p>Hangman is played as follows:</p>

<ul>
<li>There is a dictionary&nbsp;<strong>D</strong>&nbsp;of all valid words, which both you and Sean know. A word consists only of the characters&nbsp;<code>a</code>&nbsp;-&nbsp;<code>z</code>. In particular, there are no spaces.</li>
<li>You begin by choosing any word from&nbsp;<strong>D</strong>, and writing it down on a blackboard with each letter replaced by a blank:&nbsp;<code>_</code>.</li>
<li>On his turn, Sean can choose any letter and ask you if it is in the word. If it is, you reveal&nbsp;<em>all</em>&nbsp;locations of that letter. Otherwise, Sean loses a point.</li>
<li>Once all letters in the word have been revealed, the round ends.</li>
<li>The round never ends early, no matter how many points Sean loses.</li>
</ul>

<p>Sean uses a very simple strategy. He makes a list&nbsp;<strong>L</strong>&nbsp;of the 26 letters in some order, and goes through the list one letter at a time. If there is at least one word in&nbsp;<strong>D</strong>&nbsp;that (a) has the letter he is thinking of, and (b) is consistent with what you have written down so far&nbsp;<em>and the result of all of Sean's previous guesses</em>, then Sean guesses that letter. Otherwise, he skips it. No matter what, Sean then moves on to the next letter in his list.</p>

<p>Given Sean's list, what word should you choose to make Sean lose as many as points as possible? If several choices are equally good, you should choose the one that appears first in&nbsp;<strong>D</strong>.</p>

<h3>Example</h3>

<p>Suppose Sean decides to guess the letters in alphabetical order (i.e.,&nbsp;<strong>L</strong>&nbsp;= "abcdefghijklmnopqrstuvwxyz"), and&nbsp;<strong>D</strong>&nbsp;contains the words&nbsp;<code>banana</code>,&nbsp;<code>caravan</code>, and<code>pajamas</code>. If you choose&nbsp;<code>pajamas</code>, the game would play out as follows:</p>

<ul>
<li>You begin by writing 7 blanks&nbsp;<code>_ _ _ _ _ _ _</code>&nbsp;on the blackboard. Based on the number of blanks, Sean knows immediately that the word is either&nbsp;<code>caravan</code>&nbsp;or&nbsp;<code>pajamas</code>.</li>
<li>Sean begins by guessing&nbsp;<code>a</code>&nbsp;since it is first in&nbsp;<strong>L</strong>, and you reveal all locations of the letter&nbsp;<code>a</code>&nbsp;on the blackboard:&nbsp;<code>_ a _ a _ a _</code>.</li>
<li>Sean skips&nbsp;<code>b</code>&nbsp;even though it is used in&nbsp;<code>banana</code>. Sean already knows that is not your word.&nbsp;</li>
<li>He then guesses&nbsp;<code>c</code>&nbsp;because it appears in&nbsp;<code>caravan</code>. It does not appear in the word you actually chose though, so Sean loses a point and nothing more is revealed.</li>
<li>By process of elimination, Sean now knows your word has to be&nbsp;<code>pajamas</code>, so he proceeds to guess&nbsp;<code>j</code>,&nbsp;<code>m</code>,&nbsp;<code>p</code>, and&nbsp;<code>s</code>&nbsp;in order, without losing any more points.</li>
</ul>

<p>So Sean loses one point if you choose&nbsp;<code>pajamas</code>. He would have gotten either of the other words without losing any points.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow. Each test case begins with a line containing integers&nbsp;<strong>N</strong>&nbsp;and&nbsp;<strong>M</strong>, representing the number of words in the dictionary and the number of lists to consider.</p>

<p>The next&nbsp;<strong>N</strong>&nbsp;lines contain the words in the dictionary, one per line:&nbsp;<strong>D</strong><sub>1</sub>,&nbsp;<strong>D</strong><sub>2</sub>, ...,&nbsp;<strong>D<sub>N</sub></strong>. Each word is an arbitrary sequence of characters&nbsp;<code>a</code>&nbsp;-&nbsp;<code>z</code>.</p>

<p>The final&nbsp;<strong>M</strong>&nbsp;lines contain all of the lists Sean will use, one per line:&nbsp;<strong>L</strong><sub>1</sub>,&nbsp;<strong>L</strong><sub>2</sub>, ...,&nbsp;<strong>L<sub>M</sub></strong>. Each list is exactly 26 letters long, containing each letter exactly once. Sean will use these lists to guess letters as described above.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 10.</li>
<li>Each word in&nbsp;<strong>D</strong>&nbsp;will have between 1 and 10 characters inclusive.</li>
<li>No two words in&nbsp;<strong>D</strong>&nbsp;will be the same within a single test case.</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 100.</li>
<li>1 ≤&nbsp;<strong>M</strong>&nbsp;≤ 10.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x:&nbsp;<strong>w</strong><sub>1</sub>&nbsp;<strong>w</strong><sub>2</sub>&nbsp;...&nbsp;<strong>w</strong><sub><strong>M</strong></sub>", where x is the case number (starting from 1) and&nbsp;<strong>w</strong><sub>i</sub>&nbsp;is the word you should choose if Sean guesses the letters in order&nbsp;<strong>L</strong><sub>i</sub>. If multiple words cause Sean to lose the same number of points, you should choose the option that appears first in the dictionary.</p>



## 소스코드

[소스코드 보기](The%20Killer%20Word%20(Small).cpp)