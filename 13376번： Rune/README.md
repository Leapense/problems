# 13376번: Rune - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13376)


<p>Akara is a great wizard of Sanctuary. She is currently interested in runes, letters from an ancient language, which can enhance magic items and spells. Her recent studies show that some runes are more powerful than others.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13376/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-11%20%EC%98%A4%ED%9B%84%204.20.10.png" style="height:194px; width:308px"></p>

<p>Runes from Anglo-Saxon language.</p>

<p>Rune's power can be determined by a number of vowels (a, e, i, o, u) in its name. However, adjacent vowels will not increase its power more than once. For example:</p>

<ol>
<li>Rune named ‘gattaca’ has a power of 3. Since there are 3 non-adjacent vowels in its name.</li>
<li>Rune named 'beautiful' also has a power of 3. Even though there are 5 vowels, because ‘eau’ are adjacency vowels and are counted as one.</li>
</ol>

<p>Different languages have theirs own runes and cannot be mixed. Akara wants to rank her known runes from each language. So she can easily pick them up later. Your task, as her apprentice, is to write a program that takes lists of runes. Then print out every rune in that language from the most powerful to the least ones. If some of them fall in the same power level, show them in lexicographical order.</p>



## 입력


<p>The first line of input gives integer L, a number of languages you interested (1 &lt; L ≤ 10)</p>

<p>Next L lines will start with N (1 &lt; N ≤ 10<sup>5</sup>), a number of runes in that language.</p>

<p>Following by N space-separated strings W indicated each rune. Each string W will contain only lowercase English alphabet (a-z) and has a maximum length of 100 characters.</p>



## 출력


<p>Output L lines. Each line contains N strings, separated by a single space. The strings must be ordered by its calculated rune's power. If some of them have the same power, order them lexicographically.</p>



## 소스코드

[소스코드 보기](Rune.py)